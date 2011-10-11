#ifndef __OPCODE_H
#define __OPCODE_H

#include <iostream>
#include <vector>
#include "machine.h"
#include "cpu.h"

#define BEGIN_OPCODE(x) switch (x) {
#define OP_OPCODE(x) case x: x##_execute (rhs); break;
#define END_OPCODE() }

#define OPS_OPCODE(x) \
	BEGIN_OPCODE (x) \
	OP_OPCODE(AND) \
	OP_OPCODE(ADD) \
	OP_OPCODE(LV) \
	OP_OPCODE(SUB) \
	OP_OPCODE(NOOP) \
	END_OPCODE()

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
	typedef enum { ADD, SUB, AND, NOOP, LV } OP;

public:
	OPCode (OP type);
	~OPCode (void);

	void addParameter (Parameter* rhs);

	void execute (CPU&);

private:
	void ABS_execute (CPU& cpu);
	void ADD_execute (CPU& cpu);
	void SUB_execute (CPU& cpu);
	void AND_execute (CPU& cpu);
	void LV_execute (CPU& cpu);
	void NOOP_execute (CPU& cpu);

private:
	OP type;
	std::vector<Parameter *> params;

};

}

#endif /* __OPCODE_H */
