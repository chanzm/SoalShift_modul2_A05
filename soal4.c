#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <time.h>
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

  int count=1;
  FILE *file_no4;
  
  while(1)
 {
   struct stat makanenak;
   stat("/home/chaniyahzm/Documents/makanan/makan_enak.txt",&makanenak);
   time_t akses_akhir=makanenak.st_atime;

   	if(difftime(time(NULL),akses_akhir) <= 30)
   	{
       		char newfile[400];
       		strcpy(newfile,"/home/chaniyahzm/Documents/makanan/makan_sehat");

	       	char ubah[256];
       		sprintf(ubah, "%d", count);
       		strcat(newfile, ubah);
       		strcat(newfile, ".txt");
       		file_no4 = fopen(newfile, "w");
       		fclose(file_no4);
   	    	count++;
   	}
    sleep(5);
   }
    exit(EXIT_SUCCESS);
}

