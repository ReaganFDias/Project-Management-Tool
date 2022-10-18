//Includes standard libraries from C
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include "list_plantuml.c"

//This function will format and write the content needed to produce a wbs file so plantuml can run
int create_plantuml(char *name){
    //A new file called 'DrawUML.txt' is created and it will be written to
    FILE* fp = fopen("DrawUML.txt", "w");
    char content[2000];
    // start of the plantumlfile
    strcpy(content,"@startwbs\n");
    strcat(content,"* ");
    strcat(content,name);
    strcat(content,"\n");
    fputs(content, fp);
    fclose(fp);
    list_plantuml(name,2);
    fopen("DrawUML.txt","a");
    //end of the plantuml file
    fputs("@endwbs", fp);
    fclose(fp);
    char temp101[200];
    //Runs the command to create a svg file
    snprintf(temp101, sizeof(temp101), "plantuml -tsvg DrawUML.txt");
    system(temp101);
    return 0;
}
