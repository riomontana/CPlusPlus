#pragma once
#include <stdlib.h>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class MathInterpreter
{
public:
	MathInterpreter(std::ostream& out_stream);
	MathInterpreter();
	~MathInterpreter();

	void evaluate(const std::vector<std::string>& tokens);

	// Return current token
	std::string peek();
	
	// Return token @steps ahead
	std::string peek(int steps);

	void consume(const std::string& token);

	string parse_Stmt();
	string parse_ConfigStmt();
	string parse_AssgStmt();
	string parse_PrintStmt();
	int parse_MathExp();
	int parse_SumExp();
	int parse_ProductExp();
	string parse_PrimaryExp();
	bool is_Variable(const string &token);
	bool is_Int(const string &token);

private:
	string config_setting = "dec";
	unordered_map<string, int> variables;

	// Tokenized expression
	std::vector<std::string> tokens;

	// Current position
	int position;

	// Reserved end of expression string symbol (ETX = end-of-text)
	const std::string ETX = "\u0003";

};


