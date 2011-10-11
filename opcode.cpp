#include <cstdlib>
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
	
	OPCode::OPCode (OP t) : type(t) {
		
	}
	
	OPCode::~OPCode (void) {

		std::vector<Machine::Parameter *>::iterator i = params.begin ();
		for (;i < params.end (); ++i)
			delete *i;

	}

	void OPCode::execute (CPU& rhs) {
	
		OPS_OPCODE(type)
	
	}

	
	void OPCode::addParameter (Parameter* rhs) {

		params.push_back (rhs);

	}
	
	void OPCode::ABS_execute (CPU& cpu) {

		if (params.size () != 2 || !params[0]->isRegister () || !params[1]->isRegister ()) {
			std::cout << "Not enough parameters!" << std::endl;
			return ;
		}

		

	}
	
	void OPCode::ADD_execute (CPU& cpu) {

		int p[2];

		if (params.size () != 3 || !params[0]->isRegister ()) {
			std::cout << "Not enough parameters!" << std::endl;
			return ;
		}

		for (int i = 0; i < 2; ++i)
		if (params[i+1]->isRegister ())
			p[i] = cpu.getRegister (params[i+1]->getValue ()).getValue ();
		else
			p[i] = params[i+1]->getValue ();

		cpu.getRegister (params[0]->getValue ()).setValue (p[0] + p[1]);

	}
	
	void OPCode::SUB_execute (CPU& cpu) {

		int p[2];

		if (params.size () != 3 || !params[0]->isRegister ()) {
			std::cout << "Not enough parameters!" << std::endl;
			return ;
		}

		for (int i = 0; i < 2; ++i)
		if (params[i+1]->isRegister ())
			p[i] = cpu.getRegister (params[i+1]->getValue ()).getValue ();
		else
			p[i] = params[i+1]->getValue ();

		cpu.getRegister (params[0]->getValue ()).setValue (p[0] - p[1]);

	}

	void OPCode::AND_execute (CPU& cpu) {
	
		int p[2];

		if (params.size () != 3) {
			std::cout << "Not enough parameters!" << std::endl;
			return ;
		}

		if (!params[0]->isRegister ()) {
			
			std::cout << "Error: Param 0 isn't register" << std::endl;
			return ;

		}

		for (int i = 0; i < 2; ++i)
		if (params[i+1]->isRegister ()) {
			p[i] = cpu.getRegister (params[i+1]->getValue ()).getValue ();
		} else {
			p[i] = params[i+1]->getValue ();
		}

		std::cout << "Debug: AND: [0x" << std::hex << p[0] << ", 0x" << std::hex << p[1] << " reg: 0x" << params[0]->getValue () << "]" << std::endl;

		cpu.getRegister (params[0]->getValue ()).setValue (p[0] & p[1]);

	}

	void OPCode::LV_execute (CPU& cpu) {
		
		if (params.size () != 2 || !params[0]->isRegister () || params[1]->isRegister ()) {
			std::cout << "Wrong Parameters!" << std::endl;
			return ;
		}

		cpu.getRegister (params[0]->getValue ()).setValue (params[1]->getValue ());

	}
	
	void OPCode::NOOP_execute (CPU& cpu) {

		if (params.size () != 0) {
			std::cout << "Wrong Parameters!" << std::endl;
			return ;
		}
		
		std::cout << "NOOP!" << std::endl;

	}

}
