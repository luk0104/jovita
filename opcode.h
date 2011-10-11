#ifndef __OPCODE_H
#define __OPCODE_H

#include <iostream>
#include <vector>
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
	typedef enum { ADD, AND, LV } OP;

public:
	OPCode (OP type);
	~OPCode (void);

	void addParameter (Parameter* rhs);

	void execute (CPU&);

private:
	void ADD_execute (CPU& cpu);
	void AND_execute (CPU& cpu);
	void LV_execute (CPU& cpu);

private:
	OP type;
	std::vector<Parameter *> params;

};

}

#endif /* __OPCODE_H */
