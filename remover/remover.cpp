#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>

void t(char* f);

int main() {
	while (1) {
		char p[60] = { '\0' }, m[5] = { '\0' };
		FILE* f = NULL;
		errno_t e;
		int i;
		printf(">");
		scanf_s("%s", p, (int)sizeof(p));
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
			e = fopen_s(&f, p, "w");
			if (e != 0) { printf("file open error"); return -1; }
			if (fwrite("1", strlen("1"), strlen("1"), f) != strlen("1")) { printf("file writing error"); return -1; }
			e = fclose(f);
			if (e != 0) { printf("file close error"); return -1; }
			i = remove(p);
			if (i != 0) { printf("file removed error"); return -1; }
			printf("success\n");
		}
	}
}

void t(char* f) 
{	
	if (_access(f, 0) == 0) {
		printf("file exist\n");
	}
	else {
		printf("the file is not exist");
		exit(0);
	}
}