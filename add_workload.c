// includes all the libraries from C's standard libaray
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <string.h>

//This character string holds the name of the file that is going to be created
char *filename = ".workload";

//This function will add a file called '.workload' to the current directory
int add_workload(char*number){
	/*The access function checks if a file already exists with the same name. If the access
        function returns a 0 then that means that the file can't be created because another file with
        the same name already exists and an exit status will show an error to the .*/
        if (access(filename, F_OK) == 0) {
            printf("A workload already exists for this folder!\n");
            exit(-1);
      } else {
		 /*If the files doesn't exist then a new file will be created and it will hold the
		 number the user entered inside of it*/
                 FILE *fp;
                 fp = fopen(".workload", "w");
                 fprintf(fp,"%s", number);
                 fclose(fp);
                 return 0;
             }
        }

