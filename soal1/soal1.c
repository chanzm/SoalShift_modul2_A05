#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <dirent.h>

const char *get_filename_ext(const char *filename) {
    const char *dot = strrchr(filename, '.');
    if(!dot || dot == filename) return "";
    return dot + 1;
}

int main() {
  pid_t pid, sid;

  pid = fork();

  if (pid < 0) {
    exit(EXIT_FAILURE);
  }

  if (pid > 0) {
    exit(EXIT_SUCCESS);
  }

  umask(0);

  sid = setsid();

  if (sid < 0) {
    exit(EXIT_FAILURE);
  }

  if ((chdir("/")) < 0) {
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

  while(1) {
    DIR *dir;
struct dirent *ent;
if ((dir = opendir ("/home/faqih/modul2/")) != NULL) {
  while ((ent = readdir(dir)) != NULL){
	if (strcmp (get_filename_ext(ent->d_name),"png") == 0){
		char sementara[100]="";
		strncpy(sementara, ent->d_name, (strlen(ent->d_name)-4));
		strcat(sementara, "_grey.png");
		char lama[100]="";
		strcpy(lama, "/home/faqih/modul2/");
		strcat(lama, ent->d_name);
		char baru[100]="";
		strcpy(baru, "/home/faqih/modul2/gambar/");
		strcat(baru, sementara);
		rename (lama, baru);
}
}
}
  closedir(dir);
  sleep(10);
  }
  exit(EXIT_SUCCESS);
}
