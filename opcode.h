#ifndef __OPCODE_H
#define __OPCODE_H

#include "machine.h"

namespace Machine {

class OPCode {

public:
	virtual ~OPCode (void) = 0;

};

class Parameter {

public:
	virtual ~Parameter (void) = 0;
	
	virtual bool isRegister (void) = 0;
	virtual unsigned int read_uint (void) = 0;
	virtual void write_uint (unsigned int) = 0;

};

class OPCode_AND : public OPCode {
	
public:
	~OPCode_AND (void);

};

class Parameter_REG : public Parameter {

public:
	~Parameter_REG (void);

private:
	int reg_num;
	int value;

};

}

#endif /* __OPCODE_H */
