#include <cctype>
#include <cstring>
#include "parser.h"

namespace Parser {

	Parser::Parser (std::string str) {

		this->str = str;
		itr = this->str.begin ();

	}
	
#define BEGIN(x,y) \
	if (!strcasecmp (word.c_str (), #x)) { \
	std::cout << "Parsing '" << #x << "' opcode" << std::endl; \
	return parse_opcode (Machine::OPCode::x, y); }
#define OP(x,y) else BEGIN(x,y)
#define END() \
	else { std::cout << "Unknown opcode" << std::endl; break; } 

	Machine::OPCode * Parser::nextOPCode (void) {

		char ch;
		std::cout << "OPCode: " << str << std::endl;

		while (isData ()) {
			
			switch (nextToken ())
			{
				case Parser::WORD:
		 			std::cout << "[" << word << "]" << std::endl;
			
					BEGIN(AND,3)
					OP(LV,2)
					OP(ADD,3)
					END()
					
					break;

				case Parser::SEMICOLON:
					while (isData () && nextToken () != Parser::_NEWLINE) ;
			}

		}

		return NULL;

	}

#undef BEGIN
#undef OP
#undef END

	Machine::OPCode * Parser::parse_opcode (Machine::OPCode op, int params) {

		Machine::Parameter *p[params];
	
		if (parseParameters (params, p) != params)
			throw new Error::Parser::SyntaxError ();

		std::cout << "New [?] OPcode" << std::endl;
		Machine::OPCode * ret = new Machine::OPCode (op);
		for (int i = 0; i < params; ++i)
			ret->addParameter (p[i]);

		return ret;

	}

	int Parser::parseParameters (int num, Machine::Parameter* p[]) {
		
		int i;
		for (i = 0; i < num; ++i) {
	
			if (nextToken () != Parser::WORD) {
				std::cout << "Expected word" << std::endl;
				throw new Error::Parser::SyntaxError ();
			}

			p[i] = nextParameter ();

			if (i < num - 1 && nextToken () != Parser::COMMA) {
				std::cout << "Expected comma" << std::endl;
				throw new Error::Parser::SyntaxError ();
			}

		}

		return i;

	}

	Machine::Parameter * Parser::nextParameter (void) {

		bool reg = false;
		char ch;
		unsigned long int val = 0;
		std::string::iterator i = word.begin ();

		if (*i == 'r' || *i == 'R') {
			reg = true;
			++i;
		}
		
		if (!isdigit (*i)) {
			std::cout << "Expected digit" << std::endl;
			throw new Error::Parser::SyntaxError ();
		}
			
		while (i < word.end () && isdigit (*i)) {
			val = val * 10 + *i - '0';
			++i;
		}

		std::cout << "New parameter: 0x" << std::hex << val << ", " << reg << std::endl;

		return new Machine::Parameter (val, reg);

	}

	bool Parser::isData (void) {
		
		return (itr < str.end ());

	}

	void Parser::skipWs (void) {
		
		while (isspace (*itr) && isData ())
			++itr;

	}

	char Parser::nextToken (void) {

		char ch;
		std::string ret;

		skipWs ();

		switch (*itr)
		{
			case ';':
				++itr;
				return Parser::SEMICOLON;

			case '\n':
				++itr;
				return Parser::_NEWLINE;

			case ',':
				++itr;
				return Parser::COMMA;
		}

		if (!isalnum (*itr))
			throw new Error::Parser::SyntaxError ();

		word.clear ();
		while (isalnum (*itr) && isData ()) {
			
			word.push_back (*itr);
			++itr;
		
		}

		return Parser::WORD;
		
	}

}
