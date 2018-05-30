#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

class Instruction {
public:
	string comp(string);
	string dest(string);
	string jump(string);
	string aIns(string);
};
