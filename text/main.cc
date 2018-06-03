#include <time.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <syslog.h>
#include <errno.h>
#include <fcntl.h>
#include <stdarg.h>
#include <mysql/mysql.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <sys/resource.h>
#include <vector>
#include<queue>
int daemon_init(void)
{
	pid_t pid;
	if ((pid = fork()) < 0)
		return (-1);
	else if (pid != 0)
		exit(0); /* parent exit */


	setsid(); /* become session leader */

	chdir("/home/mika/Pictures"); /* change working directory */

	umask(0); /* clear file mode creation mask */

	close(0); /* close stdin */
	close(1); /* close stdout */
	
	close(2); /* close stderr */
	
	int fd = open( "/dev/null", O_RDWR );
	dup2( fd, 0 );
	dup2( fd, 1 );
	dup2( fd, 2 );
	if ( fd > 2 ){
		close( fd );
	}

	return (0);
}
int main()  
{  
   chdir("/home/mika/Pictures");
   int a=3;
   while(true)
   {
	  daemon_init();
      char ges[100];
      sprintf(ges,"gsettings set org.gnome.desktop.background picture-uri \"file:/home/mika/Pictures/%d.jpg\"",a++);
      system(ges);
	  puts(ges);
      if(a>10)a=1;
      sleep(10*60);
   }
}  
