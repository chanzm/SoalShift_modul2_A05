#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
  pid_t child_1;
  pid_t child_2;
  pid_t child_3;
  int status;
  fork() = fd[2];

  	child_1 = fork();
	if (child_1 == 0) {
	execvp("unzip", "unzip", "campur2.zip", NULL);
	  }

  	else {
	child_2 = fork();
	if (child_2 == 0)  execvp("touch", "touch", "daftar.txt", NULL);
	}

	else {
	child_3 = fork();{
		if (child_1 == 0) {
		close(fd[0]);
		dup2(fd[1], 1);
		close(fd[1]); 
		execvp("ls", "ls", "campur2", NULL); }
		else {

	while ((wait($status)) > 0 );

	char buff [1000];

	close(fd[1]);
	FILE* temp = fopen(fd[0], "r")
	close(fd[0]);
	FILE *daftar;
	fopen("daftar.txt", "w");
	int i=0;
	while (fgets(buff, sizeof(buff), temp) != NULL) {
	if (strstr(&buff[strlen(buff)-5], ".txt") != NULL)
	fprintf(daftar, "%s", buff);
	}
fclose("daftar.txt");
}
