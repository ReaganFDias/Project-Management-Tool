//Includes libraries from C
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <dirent.h>

//This function finds the folders in a directory and saves them in a file
void list_plantuml(const char* dirname, int level) {
    //FILE* fp = fopen("PlantUML.txt", "w");
    DIR* dir = opendir(dirname);
    if (dir == NULL) {
        return;
    }

    struct dirent* entity;
    entity = readdir(dir);
    while (entity != NULL) {
        char cwd[PATH_MAX];
        //char *forward = "/";
	char str1[100] = "file:/";
        char str2[100] = "/";
        if (getcwd(cwd,sizeof(cwd)) != NULL) {
            //char str1[100] = "file:/";
            //char str2[100] = "/";
	    //char final_link_path = "";
            strcat(str1, str2);
            strcat(str1,cwd);
            strcat(str1,dirname);
	    str1[strlen(str1)-1] = '\0';
	    //strcat(str1,"\n");
	    //strcpy(final_link_path,str1);
            //printf("%s",str1);
        } else {
            perror("getcwd() error\n");
            return;
	}
	//if (entity->d_type){
        //fprintf(fp,"%s/%s\n", dirname, entity->d_name);
	//printf("%s/%s\n", dirname, entity->d_name);
        if (entity->d_type == DT_DIR && strcmp(entity->d_name, ".") != 0 && strcmp(entity->d_name, "..") != 0) {
	    char str_level[150];
	    strcpy(str_level,"");
	    for (int i =0;i < level; i++){
		strcat(str_level,"*");
	    }
	    //printf("%s %s\n",str_level,entity->d_name);
	    char content[2000];
	    strcpy(content,str_level);
	    strcat(content," ");
	    //entity->d_name[strlen(entity->d_name)-1] = '\0';
	    strcat(content,entity->d_name);
	    strcat(content, " ");
	    strcat(content, "[[");
	    // str1[strlen(str1)-1] = '\0';
	    strcat(content, ("%s",str1));
	    strcat(content, "/");
	    // entity->d_name[strlen(entity->d_name)-1] = '\0';
	    strcat(content,entity->d_name);
	    strcat(content, "]]");
	    strcat(content,"\n");
	    FILE* fp = fopen("DrawUML.txt","a");
	    fputs(content,fp);
	    fclose(fp);
            char path[100] = { 0 };
            strcat(path, dirname);
            strcat(path, "/");
            strcat(path, entity->d_name);
	    //level ++;
            list_plantuml(path,level+1);
        }
        entity = readdir(dir);
    }

    closedir(dir);
    //fclose(fp);
}
