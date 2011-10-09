#include <cctype>
#include <cstring>
#include "parser.h"

namespace Parser {

	Parser::Parser (std::string str) {

		this->str = str;
		itr = this->str.begin ();

	}
	
	Machine::OPCode * Parser::nextOPCode (void) {

		char ch;
		std::cout << "OPCode: " << str << std::endl;

		while (!isEOS ()) {
			
			std::string str = nextString ();

			std::cout << "[" << str << "]" << std::endl;
			
			if (!strcasecmp (str.c_str (), "and")) {
				std::cout << "Parsing 'AND' opcode" << std::endl;
				return parse_AND ();
			} else {
				std::cout << "Unknown opcode" << std::endl;
				break;
			}

		}

		return NULL;

	}

	Machine::OPCode * Parser::parse_AND (void) {

		Machine::Parameter *params[3];

		for (int i = 0; i < 3; ++i) {
			
			params[i] = nextParameter ();
			std::cout << "char: " << *itr << std::endl;
			if (i < 2 && *itr != ',')
				throw new Error::Parser::SyntaxError ();
			++itr;

		}

		std::cout << "New AND OPcode" << std::endl;
		Machine::OPCode * ret = new Machine::OPCode_AND (*params[0], *params[1], *params[2]);
		for (int i = 0; i < 3; ++i)
			delete params[i];

		return ret;

	}

	Machine::Parameter * Parser::nextParameter (void) {

		bool reg = false;
		char ch;
		unsigned long int val = 0;

		if (tolower (ch = nextChar ()) == 'r') {
			reg = true;
			ch = nextChar ();
		}

		if (!isdigit (ch)) {
			throw new Error::Parser::SyntaxError ();
		}

		do {
			val = val * 10 + ch - '0';
			ch = nextChar ();
		} while (isdigit (ch));

		std::cout << "New parameter: 0x" << std::hex << val << ", " << reg << std::endl;
		--itr;

		return new Machine::Parameter (val, reg);

	}

	bool Parser::isEOS (void) {
		
		return !(itr < str.end ());

	}

	void Parser::skipWs (void) {
		
		while (isspace (*itr))
			++itr;

	}

	char Parser::nextChar (void) {
	
		skipWs ();

		if (itr < str.end ())
			return *itr++;
		else
			return Parser::EOS;

	}
	
	std::string Parser::nextString (void) {

		char ch;
		std::string ret;

		skipWs ();

		while (!isspace (*itr) && itr < str.end ()) {
			
			ret.push_back (*itr);
			++itr;
		
		}

		return ret;
		
	}

}
