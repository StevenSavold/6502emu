#include <stdlib.h> 
#include "include/FRlib.h"
#include <stdio.h> 
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>


int main(int argc , char **argv){

	int read_ok = 0;
	char line[50];
	char a;
	int i=0;


    if(argc != 2){    
        return 1;
    }
    
    struct stat fileStat;
        
    if(stat(argv[1],&fileStat) < 0){  
        return 1;
    }


    printf("Information for %s\n",argv[1]);
    read_ok = test_file(fileStat); 
    printf("\n\n %d \n\n",read_ok);

    FILE *fp = fopen(argv[1],"r"); 

    while(a = fgetc(fp) != EOF){

    	fgets(line, 50, fp);
    	printf("%s\n",line);
    	i++;
    	//sleep(1);
    }





    return 0;
}

