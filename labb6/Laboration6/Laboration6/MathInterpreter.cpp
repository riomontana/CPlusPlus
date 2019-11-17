#include "pch.h"
#include "MathInterpreter.h"
#include <stdlib.h>
#include <vector>
#include <regex>
#include <iostream>
#include <sstream>
#include <bitset>
#include <iomanip>
#include <unordered_map>

using namespace std;

// Tokenized expression
std::vector<std::string> tokens;

// Current position
int position = 0;

// Reserved end of expression string symbol (ETX = end-of-text)
const std::string ETX;

// Hash-map holding variables and values
unordered_map<string, int> variables;

// Constructor
MathInterpreter::MathInterpreter(std::ostream& out_stream)
{
	cout << endl << "Output:" << endl << endl;

	stringstream ss;
	ss << out_stream.rdbuf();
	string input;

	vector<string> lines_vector;

	// split input strings on linebreak
	while (getline(ss, input, '\n'))
		lines_vector.push_back(input);

	// iterate through lines
	for (auto line : lines_vector)
	{
		stringstream ss(line);
		string token;

		// split words on whitespace
		while (getline(ss, token, ' '))
			tokens.push_back(token);

		if (tokens.size() <= 1)
			cout << "error: too few arguments" << endl;
		else
			evaluate(tokens);
	}
}

//This function parses and performs all actions stated in the code
//such as storing variables, setting configurations, and making
//print - outs to the out - stream.
void MathInterpreter::evaluate(const std::vector<std::string>& tokens)
{
	string next_token = peek();

	// if first token is config
	if (next_token == "config")
	{
		// set configuration and parse statement
		string temp_config_setting = config_setting;
		config_setting = parse_Stmt();

		// if not dec, hex or bin, print error msg  
		if (!((config_setting == "dec") || (config_setting == "bin") || (config_setting == "hex")))
		{
			cout << "error: config must be dec, bin or hex" << endl;
			config_setting = temp_config_setting;
		}
	}
	// if token is print, print to out stream according to config
	else if (next_token == "print")
	{
		if (config_setting == "dec")
		{
			cout << parse_Stmt() << endl;
		}
		else if (config_setting == "bin")
		{
			int value = stoi(parse_Stmt());
			cout << bitset<32>(value).to_string() << endl;
		}
		else if (config_setting == "hex")
		{
			int value = stoi(parse_Stmt());
			cout << showbase << internal << setfill('0') << std::hex << value << endl;
		}
	}
	// if token is a variable
	else if (is_Variable(next_token))
	{
		// check if input is correct
		if (is_Variable(peek(1)))
			cout << "error: invalid input" << endl;
		// else parse statement
		else
			parse_Stmt();
	}
	// if none of the above, print error msg
	else
		cout << "error: invalid input" << endl;
}

// parses statements
string MathInterpreter::parse_Stmt()
{
	string result;
	string next_token = peek();

	// ConfigStmt
	if (next_token == "config")
	{
		consume(next_token);
		result = parse_ConfigStmt();
	}
	// PrintStmt
	else if (next_token == "print")
	{
		result = parse_PrintStmt();
	}
	// AssgStmt
	else if(is_Variable(next_token))
	{
		result = parse_AssgStmt();
	}
	// Invalid input
	else
	{
		result = "error: invalid input";
	}
	return result;
}

// Parses ConfigStmt : = "config"["dec" | "hex" | "bin” ]
string MathInterpreter::parse_ConfigStmt()
{
	string next_token = peek();
	consume(next_token);
	return next_token;
}

// Parses AssgStmt:= Variable "=" MathExp
// assigns value to a variable
string MathInterpreter::parse_AssgStmt()
{
	string result;
	string next_token = peek();
	string variable;
	int value;

	while (next_token != ETX)
	{
		if (is_Variable(next_token))
		{
			consume(next_token);
			variable = next_token;
		}
		else if (next_token == "=")
		{
			consume("=");

			try
			{
				value = parse_MathExp();
			}
			catch (exception &ex)
			{
				cout << "Error: unassigned variable" << endl;
				exit(EXIT_FAILURE);
			}

			result = (variable + " = " + to_string(value));

			// overwrite value in hash table if variable already exists
			if (variables.count(variable) > 0)
			{
				variables[variable] = value;
			}
			// else insert variable and its value in the hash map
			else
			{
				variables.insert({ variable, value });
			}
		}
		next_token = peek();
	}
	return result;
}

// Parses PrintStmt : = "print" MathExp
string MathInterpreter::parse_PrintStmt()
{
	string result;
	string next_token = peek();

	if (next_token == "print")
	{
		consume("print");
		result = to_string(parse_MathExp());
	}
	return result;
}

// Parses MathExp
int MathInterpreter::parse_MathExp()
{
	return(parse_SumExp());
}

// Parses SumExp
int MathInterpreter::parse_SumExp()
{
	int result = parse_ProductExp();
	string next_token = peek();

	while (1)
	{
		if (next_token == "+")
		{
			consume("+");
			result = (result + parse_ProductExp());
		}
		else if (next_token == "-")
		{
			consume("-");
			result = (result - parse_ProductExp());
		}
		else
			break;

		next_token = peek();
	}
	return result;
}

// Parses ProductExp
int MathInterpreter::parse_ProductExp()
{
	int result = stoi(parse_PrimaryExp());
	string next_token = peek();

	while (1)
	{
		if (next_token == "*")
		{
			consume("*");
			result = (result * stoi(parse_PrimaryExp()));
		}
		else if (next_token == "/")
		{
			consume("/");
			result = (result / stoi(parse_PrimaryExp()));
		}
		else
			break;

		next_token = peek();
	}
	return result;
}

// Parses PrimaryExp
string MathInterpreter::parse_PrimaryExp()
{
	string value;
	string next_token = peek();

	// if next token is int
	if (is_Int(next_token))
	{
		value = next_token;
		consume(next_token);
	}
	// if next token is a variable
	else if (is_Variable(next_token))
	{
		// if a variable already exists in the hash map
		if (variables.count(next_token) > 0)
		{
			// overwrite existing variable
			value = to_string(variables[next_token]);
		}
		// else set value to next_token
		else
		{
			value = next_token;
		}
		consume(next_token);
	}
	// Parenthesis expression: ( MathExp )
	else if (next_token == "(")
	{
		consume("(");
		value = to_string(parse_MathExp());
		if (peek() == ")")
		{
			consume(")");
		}
		else
		{
			cout << "Expected: )" << endl;
			exit(EXIT_FAILURE);
		}
	}
	// No valid PrimaryExp found, which is an error
	else
	{
		cout << "input error: expected int or ( )" << endl;
		exit(EXIT_FAILURE);
	}
	return value;
}

// Check if token is a variable
bool MathInterpreter::is_Variable(const string &token)
{
	bool isVariable = false;
	regex reg("[a-zA-Z][a-zA-Z0-9]*");

	string variable = token;

	if (regex_match(variable, reg))
	{
		isVariable = true;
	}
	return isVariable;
}

// Check if token is int
bool MathInterpreter::is_Int(const string &token)
{
	bool isInt = false;
	regex reg("-?[0-9]+");

	string integer = token;

	if (regex_match(integer, reg))
	{
		isInt = true;
	}
	return isInt;
}

//peek-function to identify statements and expressions from tokens before parsing them
// Return current token
std::string MathInterpreter::peek()
{
	return peek(0);
}

// Return token @steps ahead
std::string MathInterpreter::peek(int steps)
{
	if (position + steps >= tokens.size()) return ETX;
	return tokens[position + steps];
}

// consume - function to remove or step past tokens as they are processed.
// Advance to the next token.
// @token is a safeguard to make sure the caller knows what is being consumed.
void MathInterpreter::consume(const std::string& token)
{
	std::string next_token = peek();
	if (next_token == ETX)
		throw std::runtime_error("Consumed past last token\n");
	if (next_token != token)
		throw std::runtime_error("Could not consume token " + token + "\n");
	++position;
}

MathInterpreter::MathInterpreter(){}

MathInterpreter::~MathInterpreter(){}
