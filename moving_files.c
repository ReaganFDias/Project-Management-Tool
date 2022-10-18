// includes all the libraries from C's standard libaray
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <linux/limits.h>

//These temp variables are used as placeholders so the system command can run the code
char temp4[100];

//Function that moves files from one place to another
int moving_file(char*oldpath, char*newpath){
        snprintf(temp4, sizeof(temp4), "mv %s %s", oldpath, newpath);
        system(temp4);
        printf("feature moved from '%s' to '%s'\n", oldpath, newpath);
        return 0;
}

