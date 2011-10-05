#include <iostream>
#include <cstring>
#include <readline/readline.h>
#include <readline/history.h>

int
main (int argc, char *argv[])
{
	char *cmd;

	std::cout << "Welcome to Jovita v0.01" << std::endl;

	while (cmd = readline ("> ")) {

		if (!strcasecmp (cmd, "quit") || !strcasecmp (cmd, "exit"))
			break;

		add_history (cmd);

	}

	return 0;
}
