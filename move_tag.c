//includes some standard libraries from C that are used throughout the code
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <linux/limits.h>
#include "project_management.h"
#include "find_tag.c"


//Function that locates and moves tags and the folders they are accossicated with
void move_tag(char *tag1, char *tag2){

    //variable that is used to store the final command so it can be executed
    char cmd[1024];

    //paths used for storing the directories for both tags
    char path1[1024];
    char path2[1024];

    //Trying to find the path for the first tag and store the path in a variable called temp_path
    char *temp_path1 = find_tag(tag1);
    if (temp_path1 == NULL){
        return;
    }
    //if the path is found then the path is moved from 'temp_path1' to 'path1'
    strcpy(path1, temp_path1);

    //paths used for storing the directories for both tag
    char *temp_path2 = find_tag(tag2);
        if (temp_path2 == NULL){
            return;
    }
    //if the path is found then the path is moved from 'temp_path2' to 'path2'
    strcpy(path2, temp_path2);

    //Creates the bash command and stoes it in the variable called 'cmd'
    strcpy(cmd, "mv ");
    strcat(cmd, path1);
    strcat(cmd, " ");
    strcat(cmd, path2);

    //If the system command runs successfully then it will return a zero
    if(system(cmd) == 0){
        printf("%s moveed to %s", path1, path2);
    }
    else{
	//If the system command doesn't return a 0 then that means that there is an error
	printf("Aborting! Can't move the folder '%s' inside '%s'",path1, path2);
    }
}
