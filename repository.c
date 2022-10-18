// includes all the libraries from C's standard libaray
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <linux/limits.h>

//These temp variables are used as placeholders so the system command can run the code
char temp15[100];
char temp16[100];
char temp17[100];
char temp18[100];

//Function that creates a repository the user
int repository(char*name){
	printf("Creating git repository %s!\n", name);
        snprintf(temp15, sizeof(temp15), "git init %s", name);
        system(temp15);
	chdir(name);
	snprintf(temp16, sizeof(temp16), "echo 'repository created' > readme.md");
	system(temp16);
	snprintf(temp17, sizeof(temp17), "git add readme.md");
	system(temp17);
	snprintf(temp18, sizeof(temp18), "git commit -m 'repository created'");
	system(temp18);
	chdir("..");
        return 0;
}
