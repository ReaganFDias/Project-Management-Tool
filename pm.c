// includes all the libraries from C's standard libaray
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <linux/limits.h>
#include "project_management.h"

/**This is the main function and all the other functions aren called from here*/
int main(int argc, char *argv[])
{

    //**Function that renames files - This code compares two strings, the first being 'rename'
     if (strcmp(argv[1],"rename") == 0) {
         rename_project(argv[2], argv[3]);
	 return 0;
     }

     //**Activeate the guided wizard tool
     else if (strcmp(argv[1],"wizard") == 0) {
        wizard();
        return 0;
     }

     //**Checks if there are enough arguements for running commands
     if (argc < 3) {
          printf("There aren't enough arguements\n");
          exit(-1);
     }

     //**Creates a new directory and checks if the directory already exists
     if (strcmp(argv[1],"create_project") == 0) {
         create_directory(argv[2]);
	 repository(argv[2]);
	 return 0;
         }

     //**Creates a subdirectory and checks if the directory already exists
     if (strcmp(argv[1],"create_subdirectory") == 0) {
         create_subdirectory(argv[2]);
         return 0;
         }

     //**Deletes directories
     else if (strcmp(argv[1],"delete_project") == 0) {
	delete_project(argv[2]);
	return 0;
    }

     //**Creating tags
     else if (strcmp(argv[1],"add_tag") == 0) {
        add_tag(argv[2]);
	return 0;
     }

     //**search tags
     else if (strcmp(argv[1],"search_tag") == 0) {
	search_tag(argv[2]);
        return 0;
     }

     //**moves tags
     else if (strcmp(argv[1],"move_tag") == 0) {
        move_tag(argv[2],argv[3]);
        return 0;
     }

     //**add workload
     else if (strcmp(argv[1],"add_workload") == 0) {
	add_workload(argv[2]);
	return 0;
     }

     //**create plantuml diagram
     else if (strcmp(argv[1],"create_plantuml") == 0) {
        create_plantuml(argv[2]);
        return 0;
     }

     //**Prints out a table that can help the user if they didn't enter the command properly
     printf("Command not understood\n");
     read_file();
     exit(-1);
}


