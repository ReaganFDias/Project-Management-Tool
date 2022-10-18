// includes all the libraries from C's standard libaray.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *filename1 = ".pm_tag";

//Function that adds a '.pm_tag' to a directory and checks if a directory already has one.
int add_tag(char*name){
	/*The access function checks if a file already exists with the same name. If the access
        function returns a 0 then that means that the file can't be created because another file with
        the same name already exists and an exit status will show an error to the.*/
	if (access(filename1, F_OK) == 0) {
            printf("PROGRAM: A tag already exists for this folder!\n");
	    exit(-1);
      } else {
		 /*A new file called '.pm_tag' will be created within the current directory and it
		 will contain the contents that the user typed in.*/
                 FILE *fp;
                 fp = fopen(".pm_tag", "w");
                 fprintf(fp,"%s", name);
                 fclose(fp);
		 printf("PROGRAM: Tag %s created",name);
                 return 0;
             }
	}
