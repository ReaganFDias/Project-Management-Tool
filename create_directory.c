//includes some standard libraries from C that are used throughout the code
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <linux/limits.h>

//These temp variables are used as placeholders so the system command can run the code
char temp[50];

//Function that checks if the feature already exists and creates one if it doesn't exist
int create_directory(char*name){
	/**The access function checks if a file already exists with the same name. If the access
        function returns a 0 then that means that the file can't be created because another file with
        the same name already exists and an exit status will show an error to the .*/
	if ( access(name, F_OK) == 0 ){
             printf("PROGRAM: A folder of that name already exists.  Aborting.\n");
             exit(-1);
         } else {
	        /**Here I create a parent directory called whatever the user inputed and I can create
		sub directories within the parent directory. The for loops runs until it reaches the
		end of the array called 'folders' which means that it would have created all the
		subdirectories needed by the end.*/
        	printf("PROGRAM: Creating feature %s!\n", name);
		int size = 4;
        	char *folders[] = {"bin","docs","lib","src","tests"};
        	for (int i=0; i<size; i++)
        	{
        	snprintf(temp, sizeof(temp), "mkdir -p %s/%s", name, folders[i]);
        	system(temp);
        	}
        	return 0;
	}

}


