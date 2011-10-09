#include <iostream>
#include <cstring>
#include <readline/readline.h>
#include <readline/history.h>
#include "cpu.h"
#include "parser.h"

void test_opcode_and (Machine::CPU&);

int
main (int argc, char *argv[])
{
	char *cmd;
	Machine::CPU cpu;

	std::cout << "Welcome to Jovita v0.01" << std::endl;

	while (cmd = readline ("> ")) {

		if (!strcasecmp (cmd, "quit") || !strcasecmp (cmd, "exit") ||
				!strcasecmp (cmd, "q"))
			break;

		if (!strlen (cmd)) {
			cpu.dumpRegisters ();
			continue ;
		}	

		add_history (cmd);

		if (!strncasecmp (cmd, "parse ", 6))
			static_cast<Parser::Parser>(std::string (cmd+6)).nextOPCode ()->execute (cpu);
		
		if (!strcasecmp (cmd, "test_and"))
			test_opcode_and (cpu);

	}

	return 0;
}
