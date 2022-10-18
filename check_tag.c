// includes all the libraries from C's standard libaray
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <linux/limits.h>

//Function that reads the contents of the tag and compares it to the users input
char* check_tag(char *tag){
    /*A file pointer is created and the file called '.pm_tag' is opened and read from*/
    FILE *filepointer;
    filepointer = fopen(".pm_tag", "r");

    /*If the file pointer does not equal 'NULL' then the program checks the contents of the '.pm_tag'
    file and compares it to the users input*/
    if(filepointer != NULL){
	/*fgets reads a line from the file pointer which is equal to the file and then stores the
	contents in a variable called 'tag_name'*/
	char tag_name[100];
	fgets(tag_name, sizeof tag, filepointer);

	/*This compares two strings 'tag_name' which is the content from the file called '.pm_tag'
	and the tag that the user is looking for. If both the strings are the same then 0 will be
	returned. If the strings are the same then the '.pm_tag' file will be closed and the
	current working directory will be saved in a variable called 'path'.Path is then saved in 
	another varibale called 'final_path'*/
        if (strcmp(tag_name, tag) == 0){
	    fclose(filepointer);
	    char path[2024];
	    getcwd(path, sizeof path);
	    char *final_path = path;
	    printf("Tag %s found in:%s\n",tag, final_path);
	    return final_path;
	}
        else{
	    fclose(filepointer);
            return NULL;
	}
    }
    else{
	return NULL;
	}
}


