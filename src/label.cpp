#include <algorithm>
#include <map>
#include <string>
#include <iostream>
#include "label.hpp"

using namespace std;

short nextFreeAddr = 16;

map<string, short> symbolLUT = {
        {"SP",     0},
        {"LCL",    1},
        {"ARG",    2},
        {"THIS",   3},
        {"THAT",   4},
        {"R0",     0},
        {"R1",     1},
        {"R2",     2},
        {"R3",     3},
        {"R4",     4},
        {"R5",     5},
        {"R6",     6},
        {"R7",     7},
        {"R8",     8},
        {"R9",     9},
        {"R10",    10},
        {"R11",    11},
        {"R12",    12},
        {"R13",    13},
        {"R14",    14},
        {"R15",    15},
        {"SCREEN", 16384},
        {"KBD",    24576}
};

void addEntry(string line, short addr) {
    symbolLUT.insert(pair<string, short>(line, addr));
}

short getSymbol(string sym) {
    auto search = symbolLUT.find(sym);
    short value = 0;

    if (search == symbolLUT.end()) {
        addEntry(sym, nextFreeAddr);
        value = symbolLUT[sym];
        nextFreeAddr++;
    } else
        value = search->second;

    return value;
}

void parseLabel(string line, short addr) {
    auto pos = line.find('(');
    auto count = line.find(')');
    string sub = line.substr(pos + 1, count - 1);
    addEntry(sub, addr);
}
