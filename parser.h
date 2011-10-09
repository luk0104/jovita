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
	Parser (std::string str);
	Machine::OPCode * nextOPCode (void);

private:
	Machine::Parameter * nextParameter (void);
	Machine::OPCode * parse_AND (void);

protected:
	static const char EOS = 0x0;
	char nextChar (void);
	std::string nextString (void);
	bool isEOS (void);

private:
	void skipWs (void);

private:
	std::string str;
	std::string::iterator itr;

};

}

#endif /* __PARSER_H */
