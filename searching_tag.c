// includes all the libraries from C's standard libaray
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <linux/limits.h>
#include "check_tag.c"

//Funciton that searches directories and finds the path to a tag
/*A recursive function that will check all the directories down the tree until it finds a tag*/
char* search_tag(char *tag){
	//Calls the check_tag funciton to check the contents of the file and compares them
	char *path = check_tag(tag);
	if (path != NULL){
	    return path;
	}
	else{
	    //Checks the directories down the tree recursively until it has gone through all folders
	    DIR *dir;
	    struct dirent *entry;
	    dir = opendir(".");
	    int subfolders = 0;
	    while((entry = readdir(dir)) != NULL){
	        if (entry->d_type == DT_DIR && entry->d_name[0] != '.'){
		    subfolders++;
		    chdir(entry->d_name);
		    char *returned_path = search_tag(tag);
		    if (returned_path != NULL){
			return returned_path;
		    }
		    chdir("..");
		}
	    }
	    if (subfolders == 0){
		return NULL;
            }
	    return NULL;
        }
}

