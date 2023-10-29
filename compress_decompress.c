#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compress(FILE *inputfile, FILE *outputfile){
    char ch, lastchar;
    int count = 1;

    lastchar = fgetc(inputfile);
    while ((ch = fgetc(inputfile))!= EOF){
        if(ch == lastchar){
            count++;
        }
        else{
            fprintf(outputfile, "%c%d", lastchar, count);
            lastchar = ch;
            count = 1;
        }
    }
    fprintf(outputfile, "%c%d", lastchar, count);
}

void decompress(FILE *inputfile, FILE *outputfile){
    char ch;
    int count;
    while((ch = fgetc(inputfile))!= EOF){
        count = fscanf(inputfile,"%d" , &count);
        for(int i = 0 ; i < count; i++){
            fprintf(outputfile, "%c", ch);
        }
    }
}

int main (){
    FILE *inputfile, *outputfile;
    int choice;

    //open inputfile in read mode 
    inputfile = fopen("input.txt", "r");
    if(inputfile==NULL){
        printf("Error: Cannot open input file\n");
        return 1;
    }

    //open output file in write mode 
    outputfile = fopen("output.txt", "w");
    if(outputfile==NULL){
        printf("Error: Can not create output file\n");
        fclose(inputfile);
        return 1;
    }

    //create menu 
    printf("What do you like to do ?\n");
    printf("1. Compress\n2. Decompress\nEnter your choice here:\n");
    scanf("%d", &choice);

    //do the opreations based of user choice
    if(choice==1){
        compress(inputfile, outputfile);
        printf("File compressed successfully\n");

    }
    else if(choice==2){
        decompress(inputfile, outputfile);
        printf("File decompressed successfully\n");
    }
    else{
        printf("Invalid choice\n");
    }
    
    return 0;
}