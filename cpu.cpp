#include "cpu.h"

namespace Machine {

	Register::Register (void) {

	}

	Register::~Register (void) {

	}

	unsigned long int Register::getValue (void) {
		
		return value;

	}

	void Register::setValue (unsigned long int val) {

		value = val;

	}

	void Register::zero (void) {

		value = 0;

	}

	CPU::CPU (void) {

	}

	CPU::~CPU (void) {

	}

	void CPU::dumpRegisters (void) {
		
		std::cout << "Dumping registers:" << std::endl;
		for (int i = 0; i < sizeof (regs) / sizeof (*regs); ++i) {

			std::cout << i << ": 0x" << std::hex << regs[i].getValue () << std::endl;
		
		}
		std::cout << "Done" << std::endl;

	}

	Register& CPU::getRegister (int num) {

		if (num > sizeof (regs) - 1)
			throw new Error::Machine::UnknownRegister ();

		return regs[num];

	}

}
