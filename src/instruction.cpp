#include <algorithm>
#include <map>
#include <string>
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "instruction.hpp"
#include "label.hpp"
using namespace std;

map<string, string> compLUT = {
		{"0", "101010"}, {"1", "111111"}, {"-1", "111010"},
		{"D", "001100"}, {"A", "110000"}, {"!D", "001101"},
		{"!A", "110001"}, {"-D", "001111"}, {"-A", "110011"},
		{"D+1", "011111"}, {"A+1", "110111"}, {"D-1", "001110"},
		{"A-1", "110010"}, {"D+A", "000010"}, {"D-A", "010011"},
		{"A-D", "000111"}, {"D&A", "000000"}, {"D|A", "010101"},
		{"M", "110000"}, {"!M", "110001"}, {"-M", "110011"},
		{"M+1", "110111"}, {"M-1", "110010"}, {"D+M", "000010"},
		{"D-M", "010011"}, {"M-D", "000111"}, {"D&M", "000000"},
		{"D|M", "010101"}
};

map<string, string> destLUT = {
		{"", "000"}, {"M", "001"}, {"D", "010"},
		{"MD", "011"}, {"A", "100"}, {"AM", "101"},
		{"AD", "101"}, {"AMD", "111"}
};

map<string, string> jumpLUT = {
		{"", "000"}, {"JGT", "001"}, {"JEQ", "010"}, {"JGE", "011"},
		{"JLT", "100"}, {"JNE", "101"}, {"JLE", "110"}, {"JMP", "111"}
};

string Instruction::comp(string instruction) {
	auto pos = instruction.find("=");
	string sub = instruction.substr(pos+1);
	string bin = compLUT[sub];

	if (sub.find("M") != string::npos)
		bin = "1" + bin;
	else if (sub.find("M") == string::npos)
		bin = "0" + bin;

	return bin;
}

string Instruction::dest(string instruction) {
	auto count = instruction.find("=");
	string sub = instruction.substr(0, count);
	string bin = destLUT[sub];

	return bin;
}

string Instruction::jump(string instruction) {
	auto delim = instruction.find(";");
	string subcomp = instruction.substr(0, delim);
	string bincomp = compLUT[subcomp];

	string subjump = instruction.substr(delim+1);
	string binjump = jumpLUT[subjump];

	string bin = "0" + bincomp + "000" + binjump;

	return bin;
}

string Instruction::aIns(string instruction) {
	auto pos = instruction.find("@");
	string sub = instruction.substr(pos+1);
//	sub.pop_back();
	auto num = isNumber(sub);
	short addr = 0;

	if (num) {
		addr = (short) stoi(sub,nullptr);
	}
	else if (!num) {
		addr = getSymbol(sub);
	}

	string bin = "000000000000000";

	short addr_iter = addr;
	for (auto i = 14; i >= 0; i--) {
		if (addr_iter % 2 == 0) {
			bin[i] = '0';
		}
		else if (addr_iter % 2 == 1) {
			bin[i] = '1';
		}
		addr_iter >>= 1;
	}
	bin = "0" + bin;

	return bin;
}

bool isNumber(string address) {
	auto is_num = [](const char c) {
		return c >= '0' && c <= '9';
	};

	bool num = all_of(address.begin(), address.end(), is_num);

	return num;
}

string trim (string instruction) {
	boost::trim_right(instruction);
	boost::trim_left(instruction);

	return instruction;
}
