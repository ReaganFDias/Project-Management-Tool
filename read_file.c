//Includes some standard libraries from C
#include <stdio.h>
#include <stdlib.h>

//This function reads the files called 'menu.txt' and it will display the contents of the file
int read_file(){
    //opens the files called 'menu.txt'
    FILE *the_file = fopen("menu.txt", "r");
    if (the_file == NULL){
        perror("unable to open file");
        exit(1);
    }
    //while the line number is less than the line count for for the file it will run this code
    char line[100];
    while (fgets(line, sizeof(line), the_file)) {
    printf("%s",line);
    }
    fclose(the_file);
    return 0;
}
