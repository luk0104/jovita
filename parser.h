#ifndef __PARSER_H
#define __PARSER_H

#include <string>
#include "opcode.h"
#include "machine.h"

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
