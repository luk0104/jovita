#ifndef __PARSER_H
#define __PARSER_H

#include <string>
#include "opcode.h"
#include "machine.h"

#define BEGIN_PARSER(x,y) \
	if (!strcasecmp (word.c_str (), #x)) { \
	std::cout << "Parsing '" << #x << "' opcode" << std::endl; \
	return parse_opcode (Machine::OPCode::x, y); }
#define OP_PARSER(x,y) else BEGIN_PARSER(x,y)
#define END_PARSER() \
	else { std::cout << "Unknown opcode" << std::endl; break; } 

#define OPS_PARSER() \
	BEGIN_PARSER(AND,3) \
	OP_PARSER(LV,2) \
	OP_PARSER(ADD,3) \
	OP_PARSER(SUB,3) \
	OP_PARSER(NOOP,0) \
	END_PARSER()

namespace Error {

	namespace Parser {

		class SyntaxError { };

	}

}

namespace Parser {

class Parser {

public:
	static const char _NEWLINE = 0x1;
	static const char SEMICOLON = 0x2;
	static const char WORD = 0x3;
	static const char COMMA = 0x4;
	
protected:
	static const char EOS = 0x0;

public:
	Parser (std::string str);
	Machine::OPCode * nextOPCode (void);

private:
	int parseParameters (int num, Machine::Parameter* p[]);
	Machine::Parameter * nextParameter (void);
	Machine::OPCode * parse_opcode (Machine::OPCode op, int params);

protected:
	bool isData (void);
	char nextToken (void);

private:
	void skipWs (void);

private:
	std::string str;
	std::string::iterator itr;
	std::string word;

};

}

#endif /* __PARSER_H */
