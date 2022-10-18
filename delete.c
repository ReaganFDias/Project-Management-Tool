// includes all the libraries from C's standard libaray
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//These temp variables are used as placeholders so the system command can run the code
char temp2[100];

//Function delets a project
int delete_project(char*name){
	/*The temp variable is used a buffer and then the system command executes the command.*/
	printf("Deleting directory %s!\n", name);
        snprintf(temp2, sizeof(temp2), "rm -rf  %s", name);
        system(temp2);
        return 0;
}


