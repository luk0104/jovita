#include <iostream>
#include <cstring>
#include <readline/readline.h>
#include <readline/history.h>
#include "cpu.h"
#include "parser.h"

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

		if (!strncasecmp (cmd, "parse ", 6)) {
			Parser::Parser parser(cmd+6);
			Machine::OPCode *code;
			while ( (code = parser.nextOPCode ()) != NULL) {
				code->execute (cpu);
				delete code;
			}
		}
		
	}

	return 0;
}
