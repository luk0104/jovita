#ifndef __OPCODE_H
#define __OPCODE_H

#include <iostream>
#include "machine.h"
#include "cpu.h"

namespace Error {
		
	namespace Machine {

		class WrongOPCode { };

	}

}

namespace Machine {

class Parameter {

public:
	Parameter (void);
	Parameter (int value, bool reg = false);
	Parameter (Parameter &rhs);
	~Parameter (void);
	
	bool isRegister (void);
	int getValue (void);

private:
	int value;
	bool reg;

};

class OPCode {

public:
	virtual ~OPCode (void) { };

	virtual void execute (CPU&) = 0;

};

class OPCode_AND : public OPCode {

public:
	OPCode_AND (Parameter p1, Parameter p2, Parameter p3);
	~OPCode_AND (void);

	void execute (CPU&);

private:
	Parameter params[3];

};

}

#endif /* __OPCODE_H */
