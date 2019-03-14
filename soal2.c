#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <errno.h>

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

  if ((chdir("/home/chaniyahzm/sisop/modul2")) < 0) {
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

  while(1) {
    struct stat fileno2;
    char sakit[250] = "/home/chaniyahzm/sisop/modul2/hatiku/elen.ku";
    stat(sakit, &fileno2);

    struct passwd *user = getpwuid(fileno2.st_uid);
    struct group *grup = getgrgid(fileno2.st_gid);
    char pmilik[50] = "www-data";

    int own = strcmp(user->pw_name, pmilik); 
    int gru = strcmp(grup->gr_name, pmilik);

   if(own==0 && gru==0) remove(sakit);
   sleep(30);
  }
  
  exit(EXIT_SUCCESS);
 return 0;
}
