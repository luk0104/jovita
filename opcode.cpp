#include "opcode.h"

namespace Machine {
	
	Parameter::Parameter (int init, bool _register) : value(init), reg(_register) {

	}
	
	Parameter::Parameter (Parameter &rhs) {
		
		value = rhs.value;
		reg = rhs.reg;

	}
	
	Parameter::Parameter (void) {

	}

	Parameter::~Parameter (void) {

	}

	bool Parameter::isRegister (void) {
		return reg;
	}

	int Parameter::getValue (void) {
		return value;
	}

	OPCode_AND::OPCode_AND (Parameter p1, Parameter p2, Parameter p3) {

		params[0] = p1;
		params[1] = p2;
		params[2] = p3;

	}
	
	OPCode_AND::~OPCode_AND (void) {

	}

	void OPCode_AND::execute (CPU& cpu) {
	
		int p[2];

		if (!params[0].isRegister ()) {
			
			std::cout << "Error: Param 0 isn't register" << std::endl;
			return ;

		}

		for (int i = 0; i < 2; ++i)
		if (params[i+1].isRegister ()) {
			p[i] = cpu.getRegister (params[i+1].getValue ()).getValue ();
		} else {
			p[i] = params[i+1].getValue ();
		}

		std::cout << "Debug: AND: [0x" << std::hex << p[0] << ", 0x" << std::hex << p[1] << "]" << std::endl;

		cpu.getRegister (params[0].getValue ()).setValue (p[0] & p[1]);

	}

}
