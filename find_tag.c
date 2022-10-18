// includes all the libraries from C's standard libaray
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <linux/limits.h>
#include "project_management.h"

//Function that finds the paths the tags
char * find_tag(char *tag){
    char sole_path[2024];
    char final_path[2024];
    char home_path[2024];

    //gets the current working directory
    getcwd(home_path, 2024);

    //runs the search_tag function
    char *path = search_tag(tag);

    //If there isn't a NULL from search_tag then it will return the path to the user
    if (path != NULL){
        for (int n = 0; path[strlen(home_path)+n-1] != '\0'; n++){
            sole_path[n] = path[strlen(home_path)+n];
	}
	//this will display to the user the final path of the tags
	strcpy(final_path,".");
        strcat(final_path, sole_path);
	printf("%s found in %s",tag, final_path);
	chdir(home_path);
	char *p_final_path = final_path;
	return p_final_path;
    }
    else{
	printf("%s not found", tag);
	return NULL;
     }
}
