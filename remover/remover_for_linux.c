#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void t(char* f);

int main() {
	while (1) {
		char p[60] = { '\0' }, m[5] = { '\0' };
		FILE* f = NULL;
		printf(">");
		scanf("%s", p, (int)sizeof(p));
		if (strcmp(p, "e") == 0) {//
			break;
		}
		else if (strcmp(p, "help") == 0) {
			printf("usage:\nenter file path\n");
		}
		else {
			if (sizeof(p) <= 100) printf("starting...\n");
			else { printf("buffer error"); return -1; }
			t(p);
			f = fopen(p, "w");
			if (f != 0) { printf("file open error"); return -1; }
			fwrite("1", strlen("1"), strlen("1"), f);
			fclose(f);
			remove(p);
			printf("success\n");
		}
	}
}

void t(char* f)
{
	if (access(f, F_OK) == 0) {
		printf("file exist\n");
	}
	else {
		printf("the file is not exist");
		exit(0);
	}
}