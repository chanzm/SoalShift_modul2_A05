#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  pid_t child_1;
  pid_t child_2;
  pid_t child_3;
  int status;
  int fd[2];
  int buff;
  pipe(fd);

  	child_1 = fork();
	if (child_1 == 0) {

	execlp("unzip", "unzip", "campur2.zip", NULL);
	  }

  	else {
	child_2 = fork();
	if (child_2 == 0) {
        execlp("touch", "touch", "daftar.txt", NULL);
	}

	else {
	child_3 = fork();
		if (child_3 == 0) {
		dup2(fd[1], 1);
		execlp("ls", "ls", "campur2", NULL);
		} else {
	while(wait(&status)>0);
	char buff [1000];

	close(fd[1]);
	FILE* temp = fdopen(fd[0], "r");
	FILE *daftar = fopen("daftar.txt", "w");
	int i=0;
	while (fgets(buff, sizeof(buff), temp) != NULL) {
	if (strstr(&buff[strlen(buff)-5], ".txt") != NULL)
	fprintf(daftar, "%s", buff);
	}
fclose(daftar);
waitpid(-1, NULL, 0);
waitpid(-1, NULL, 0);
waitpid(-1, NULL, 0);
}
}
}
}
