// includes all the libraries from C's standard libaray.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


//These temp variables are used as placeholders so the system command can run the code.
char temp[50];

//Function that renames the files/folders the user parses in.
int rename_project(char*oldname, char*newname){
	/*The temp variable is used a buffer and then the system command executes the command.*/
	snprintf(temp, sizeof(temp), "mv %s %s", oldname, newname);
	system(temp);
	printf("PROGRAM: renamed '%s' to '%s'\n", oldname, newname);
	return 0;
}
