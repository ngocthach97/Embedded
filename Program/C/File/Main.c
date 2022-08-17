#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/stat.h>
#include <utime.h>
#include <time.h>
#include <fcntl.h>

struct tm *tm_atime, *tm_mtime, *tm_ctime;

struct stat st;

struct utimbuf utb;

char *pathname = "/home/nguyen/Embedded/Basic/File/File.txt";

int main(int argc, const char *argv[])
{
	if (stat(pathname, &st) < 0)
	{
		printf("Cannot Retrieving File Information !\n");
	}
	// File type
	switch (st.st_mode & S_IFMT)
	{
	case S_IFREG:
		printf("Regular file !\n");
		break;
	case S_IFDIR:
		printf("Directory !\n");
		break;
	case S_IFCHR:
		printf("Character device !\n");
		break;
	case S_IFBLK:
		printf("Block device !\n");
		break;
	case S_IFIFO:
		printf("FIFO or pipe !\n");
		break;
	case S_IFSOCK:
		printf("Socket !\n");
		break;
	case S_IFLNK:
		printf("Symbolic link \n");
		break;
	default:
		break;
	}
	// Checking File Accessibility
	if (access(pathname, F_OK) < 0)
	{
		printf("Cannot check file accessibility \n");
	}
	else
	{
		printf("File accessibility mode F_OK (Does the file exist ?)\n");
	}
	// File timestamps
	printf("Time of last file access = %ld \n", st.st_atime);
	tm_atime = gmtime(&st.st_atime);
	printf("%s\n", asctime(tm_atime));

	printf("Time of last file modification = %ld \n", st.st_mtime);
	tm_mtime = gmtime(&st.st_mtime);
	printf("%s\n", asctime(tm_mtime));

	printf("Time of last status change = %ld \n", st.st_ctime);
	tm_ctime = gmtime(&st.st_ctime);
	printf("%s\n", asctime(tm_ctime));
	// File Ownership
	printf("User ID of file owner = %d \n", st.st_uid);

	printf("Group ID of file owner = %d \n", st.st_gid);
	// Permissions on Regular Files
	printf("check permission User-read file %d \n", st.st_mode & S_IRUSR);
	
	printf("check permission User-execute file %d \n", st.st_mode & S_IXUSR);
	return 0;
}
