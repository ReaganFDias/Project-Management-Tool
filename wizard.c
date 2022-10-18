//Includes standard libraries from C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <linux/limits.h>
#include "project_management.h"

//wizard program that helps the user break down tasks with a UI
int wizard(){

    //the menu for the wizard will be displayed to the user
    read_menu();
    printf("ENTER YOUR OPTION:");
    //the users choice will be stored in a variable
    int wizard_option;
    scanf("%d", &wizard_option);

    //depending on the users choice these are the possible commands they can run
    switch(wizard_option)
    {
	case 1:
	    printf("PROGRAM:creating subdirectory\n");
	    char subdirname[50];
	    printf("Enter the name of the subdirectory:");
	    scanf("%49s",subdirname);
	    create_subdirectory(subdirname);
	    wizard();
	    break;
	case 2:
	    printf("PROGRAM:deleting item\n");
            char deleting[50];
            printf("Enter the name of the item you want to delete:");
            scanf("%49s",deleting);
            delete_project(deleting);
            wizard();
	case 3:
	    printf("PROGRAM: searching tag:\n");
            char searchtag[50];
            printf("Enter the tag you want to search for:");
            scanf("%49s",searchtag);
            search_tag(searchtag);
            wizard();
	case 4:
            printf("PROGRAM: adding tag:\n");
            char adding_tag[50];
            printf("What is the tag name you want to create:");
            scanf("%49s",adding_tag);
            add_tag(adding_tag);
            wizard();
	case 5:
            printf("PROGRAM: moving tag:\n");
            char oldtag[50];
	    char newtag[50];
            printf("What is the name of the tag you want to move from:");
            scanf("%49s", oldtag);
	    printf("What is the name of the tag you want to move to:");
            scanf("%49s", newtag);
            move_tag(oldtag, newtag);
            wizard();
	case 6:
            printf("PROGRAM: creating directory:\n");
            char dir_name[50];
            printf("What is the name of the project you want to create:");
            scanf("%49s", dir_name);
            create_directory(dir_name);
	    repository(dir_name);
            wizard();
	case 7:
	    printf("PROGRAM: adding workload:\n");
            char workload_time[50];
            printf("How much time is this task going to take:");
            scanf("%49s", workload_time);
            add_workload(workload_time);
            wizard();
	case 8:
            printf("PROGRAM: creating plantuml wbs diagram:\n");
            char name_plantuml[50];
            printf("What is the name of the folder that you want to create a diagram for:");
            scanf("%49s",name_plantuml);
            create_plantuml(name_plantuml);
            wizard();
	case 9:
            printf("PROGRAM: moving files:\n");
            char file1[50];
	    char file2[50];
            printf("What is the path of the first file you want to move:");
            scanf("%49s",file1);
	    printf("What is the path of the second file you want to move:");
	    scanf("%49s",file2);
            moving_file(file1,file2);
            wizard();
	case 10:
            printf("PROGRAM: renaming files:\n");
            char oldname[50];
            char newname[50];
            printf("What is the name of the file you want to change names:");
            scanf("%49s",oldname);
            printf("What do you want to change it too:");
            scanf("%49s",newname);
            moving_file(oldname,newname);
            wizard();
	default:
	    printf("Hello");
	    break;
    }

    return 0;

}
