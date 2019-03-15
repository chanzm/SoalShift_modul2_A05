# SoalShift_modul2_A05

LAPORAN MODUL1 Kelompok A5 <br>
Nama : Chaniyah Zulfa M (05111740000115) <br>
	Faqih Fathan I. (05111740000175)

 LAPORAN 2 SISOP 2019

1.) Elen mempunyai pekerjaan pada studio sebagai fotografer. Suatu hari ada seorang klien yang bernama Kusuma yang meminta untuk mengubah nama file yang memiliki ekstensi .png menjadi “[namafile]_grey.png”. Karena jumlah file yang diberikan Kusuma tidak manusiawi, maka Elen meminta bantuan kalian untuk membuat suatu program C yang dapat mengubah nama secara otomatis dan diletakkan pada direktori /home/[user]/modul2/gambar.
Catatan : Tidak boleh menggunakan crontab.
jawab=
```
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
```

Penjelasan:
	Karena tidak boleh menggunakan crontab, maka digunakan daemon sebagai penggantinya. Daemon adalah proses yang bekerja pada background. Disini kami menggunakan fungsi untuk mebaca dan mengubah titik(.) yang sebelumnya berupa ekstensi menjadi string agar bisa terbaca pada fungsi yang akan dgunakan nanti;	
const char *get_filename_ext(const char *filename) {
	const char *dot = strrchr(filename, '.');
	if(!dot || dot == filename) return "";
	return dot + 1;
}
 	Dalam mengerjakan soal ini kami juga membuat beberapa variabel didalam while dan juga menggunakan variable char yang bertipe pointer dan tidak lupa struct bertipe pointer, langkah pertama kita membuka file dengan menggunakan variabel pointer dan tidak lupa kita juga menggunakan if dengan syarat dir, dengan maksud sampai file didalam folder itu sudah habis if ((dir = opendir ("/home/faqih/modul2/")) != NULL) , lalu didalam if kita menggunakan looping dengan syarat agar dia membaca semua file yang ada pada folder tsb. Kemudian didalam while kita menggunakan if lagi yang berisi fugsi string compare untuk membandingkan satu string dengan string lainya; iif ((dir = opendir ("/home/faqih/modul2/")) != NULL) {.
	Kemudian kami menggunakan 3 array untuk meprosesnya, yang pertama kita gunakan untuk mengganti dan me-replace nama dari file, dengan cara mengurangi 4 string dari akhir. Maka ekstensi .png akan hilang lalu diganti dengan “_grey.png” dan ditaruh dalam folder bernama sementara. Kemudian yang kedua digunakan untuk memanggil alamat dari direktori png awal kita kemudain akan dimasukkan ke folder bernama lama. Terakhir berfungsi untuk memanggil direktori baru/final lalu memasukanya ke folder bernama baru, kemudian kita gunakan fungsi rename dari folder lama ke baru.


2.) Pada suatu hari Kusuma dicampakkan oleh Elen karena Elen dimenangkan oleh orang lain. Semua kenangan tentang Elen berada pada file bernama “elen.ku” pada direktori “hatiku”. Karena sedih berkepanjangan, tugas kalian sebagai teman Kusuma adalah membantunya untuk menghapus semua kenangan tentang Elen dengan membuat program C yang bisa mendeteksi owner dan group dan menghapus file “elen.ku” setiap 3 detik dengan syarat ketika owner dan grupnya menjadi “www-data”. Ternyata kamu memiliki kendala karena permission pada file “elen.ku”. Jadi, ubahlah permissionnya menjadi 777. Setelah kenangan tentang Elen terhapus, maka Kusuma bisa move on.
Catatan: Tidak boleh menggunakan crontab
jawab=
```
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
```
Penjelasan=
Karena tidak boleh menggunakan crontab, maka digunakan daemon sebagai penggantinya. Daemon adalah proses yang bekerja pada background. Pada main program, stat adalah struktur data bawaan dari c yang berisi beberapa data yang tersimpan didalamnya, seperti st_mode,st_gid, dll. 
Lalu, buat variabel untuk menyimpan data user dan group yang disimpan dalam direktori hatiku pada file elen.ku.
Kemudian, informasi dari file elen.ku dimasukkan ke fileno2.
Isi dari struct diambil informasi user dan groupnya dengan perintah getpwuid dan getgrgid.
Lalu, buat variabel pmilik[50] untuk menyimpan “www-data”.
Bandingkan www-data dengan nama dan grup pada elen.ku. Jika sama, maka file elen.ku akan terhapus.
Jadi, untuk menghapus, kita harus mengubah user dan group dalam elen.ku menjadi www-data dulu agar sama dengan melakukan perintah “chown www-data:www-data elen.ku” , lalu untuk mengubah permissionnya menjadi 777 , ketikkan “chmod 777 elen.ku” . Lalu priksa user dan group dari elen.ku dengan cara “ls -l elen.ku”, maka user dan group akan berubah menjadi www-data.
Jalankan script dengan “gcc soal2.c -o hasil2” , lalu “./hasil2” .
Terakhir, kita cek, sehingga file elen.ku telah terhapus.

3.) Diberikan file campur2.zip. Di dalam file tersebut terdapat folder “campur2”. 
Buatlah program C yang dapat :
i)  mengekstrak file zip tersebut.
ii) menyimpan daftar file dari folder “campur2” yang memiliki ekstensi .txt ke dalam file daftar.txt. 
Catatan:  
Gunakan fork dan exec.
Gunakan minimal 3 proses yang diakhiri dengan exec.
Gunakan pipe
Pastikan file daftar.txt dapat diakses dari text editor
	jawab=
```
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
```
Penjelasan:
	Disini kami menggunakan 3 proses exec berupa child, child pertama digunakan untuk meng-unzip file “campur2.zip”, kemudian yang kedua digunakan untuk touch/ atau membuat file daftar.txt, yang terakhir digunakan untuk me-list dari file campur2 ke daftar.txt. Tidak lupa kami menggunakan wait agar proses tidak berjalan bersamaan, sehingga semua proses dapat berjalan sebagaimana mestinya. Kemudian kami menggunakan pipe, lalu FILE* temp = fdopen(fd[0], "r"); digunakan untuk membuka dan memmbaca file dan disimpan di temp. FILE *daftar = fopen("daftar.txt", "w"); fungsi ini digunakan untuk menyimpan dan menulis pada daftar.txt. Kemudian program akan melakukan perulangan ketika jumlah array yang terisi tidak kosong.Lalu jika ditemukan file ber-ekstensi .txt maka akan di print didalam daftar.
	

4.) Dalam direktori /home/[user]/Documents/makanan terdapat file makan_enak.txt yang -berisikan daftar makanan terkenal di Surabaya. Elen sedang melakukan diet dan seringkali tergiur untuk membaca isi makan_enak.txt karena ngidam makanan enak. Sebagai teman yang baik, Anda membantu Elen dengan membuat program C yang berjalan setiap 5 detik untuk memeriksa apakah file makan_enak.txt pernah dibuka setidaknya 30 detik yang lalu (rentang 0 - 30 detik).
Jika file itu pernah dibuka, program Anda akan membuat 1 file makan_sehat#.txt di direktori /home/[user]/Documents/makanan dengan '#' berisi bilangan bulat dari 1 sampai tak hingga untuk mengingatkan Elen agar berdiet.

Contoh:
File makan_enak.txt terakhir dibuka pada detik ke-1
Pada detik ke-10 terdapat file makan_sehat1.txt dan makan_sehat2.txt
Catatan: 
dilarang menggunakan crontab
Contoh nama file : makan_sehat1.txt, makan_sehat2.txt, dst
	Jawab=
```	
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
```
Penjelasan :
Count adalah variabel untuk increment, file_no4 adalah pointer file untuk membuka dan menutupnya.
Stat adalah struktur data c yang menyimpan banyak data didalamnya.
Informasi yang didapat dari makan_enak di masukkan ke makanenak.
Lalu mengecek, jika time sekarang-waktu akhir dibuka file makan_enak masih dalam rentang 0-30 detik, maka membuat file baru dengan nama makan_sehat1,makan_sehat2,dll.
Kemudian, meng copy makan_sehat yang terbuat dan dimasukkan dalam newfile.
Sprintf adalah syntax untuk mengubah integer ke string.
Strcat adalah untuk menggabungkan angka yang diubah ke string tadi dan juga menggabungkan “.txt” ke newfile, sehingga, hasil akhirnya adalah makan_sehat1.txt, makan_sehat2.txt., dll.

Jalankan kodingan, lalu masuk ke Documents/makanan/. Didalamnya terdapat file makan_enak.txt.
Lalu lakukan perintah “touch -a makan_enak.txt” , lalu ls. Maka akan ke create Makan_sehat1.txt, makan_sehat2.txt, dll setiap 5 detik jika file terakhir di akses masih dalam rentang 1-30 detik.
Touch -a sendiri adalah untuk membuka makan_enak.txt.
Setelah itu untuk mengecek daemon jalan atau tidak dan melihat pid lakukan perintah “ps -e | grep hasil4”.
Akan muncul pid, lalu lakukan kill dengan cara “kill (pid)”.

5.) Kerjakan poin a dan b di bawah:
Buatlah program c untuk mencatat log setiap menit dari file log pada syslog ke /home/[user]/log/[dd:MM:yyyy-hh:mm]/log#.log
Ket:
Per 30 menit membuat folder /[dd:MM:yyyy-hh:mm]
Per menit memasukkan log#.log ke dalam folder tersebut
‘#’ : increment per menit. Mulai dari 1
Buatlah program c untuk menghentikan program di atas.
NB: Dilarang menggunakan crontab dan tidak memakai argumen ketika menjalankan program.
jawab:
5a

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <syslog.h>
#include <stdlib.h>
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

  if ((chdir("/")) < 0) {
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);
mkdir("/home/faqih/log", 0700);
while(1) {
	 time_t timer;
    char buffer[26];
    struct tm* tm_info;

    time(&timer);
    tm_info = localtime(&timer);

    strftime(buffer, 26, "%d:%m:%Y-%H:%M", tm_info);


        char dir[100];
        char nama[100];
        sprintf(nama,"%s", buffer);
        printf("%s", nama);
        sprintf(dir, "/home/faqih/log/%s", nama);
        mkdir(dir, 0700);
	int i;
        for(i=1; i<30; i++){
                FILE *file_lama, *file_baru;
                file_lama = fopen("/var/log/syslog", "r");
                char file[100];
                sprintf(file, "/home/faqih/log/%s/log%d.log", nama, i);
                file_baru = fopen(file, "w");
                char cr;
                while(fscanf(file_lama, "%c", &cr) != EOF)
                {fprintf(file_baru, "%c", cr);}
                fclose(file_lama);
                fclose(file_baru);
                sleep(60);
        }
 }
  exit(EXIT_SUCCESS);
}
penjelasan:
cari jam dimana program berjalan
jam diperuntukkan sebagai nama folder 
lakukan looping 30 menit untuk folder dan tiap menit untuk file
isi file diambil dari direktori /var/log/syslog

5b
#include <stdio.h>
#include <unistd.h>

int main() {
	execlp("killall", "killall", "script5a", NULL);

	return(0);
}

digunakan kill all dan nama file yang akan di kill

