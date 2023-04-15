#include <stdio.h>

int main(int argc, char *argv[]) {
	printf("%d arguments passed:\n", argc - 1);

	// List argument values (ignores the program name)
	for (int i = 1; i < argc; i++) {
		printf("- %s\n", argv[i]);
	}

	return 1;
}