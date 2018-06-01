#include <string>
using namespace std;

class Instruction {
public:
	string comp(string);
	string dest(string);
	string jump(string);
	string aIns(string);
};

bool isNumber(string);
