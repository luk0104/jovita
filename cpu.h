#ifndef __CPU_H
#define __CPU_H

#include <iostream>

namespace Error {

	namespace Machine {

		class UnknownRegister { };

	}

}

namespace Machine {

class Register {

public:
	Register (void);
	~Register (void);

	unsigned long int getValue (void);
	void setValue (unsigned long int);
	void zero (void);

private:
	unsigned long int value;

};

class CPU {
	
public:
	CPU (void);
	~CPU (void);

	void dumpRegisters (void);

	Register& getRegister (int num);

private:
	Register regs[8];

};

}

#endif /* __CPU_H */
