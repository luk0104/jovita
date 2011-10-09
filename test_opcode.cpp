#include "cpu.h"
#include "opcode.h"

void test_opcode_and (Machine::CPU& c)
{
	Machine::Parameter p1(0, true), p2(2), p3(6);
	Machine::OPCode *op = new Machine::OPCode_AND (p1, p2, p3);

	op->execute (c);	
}
