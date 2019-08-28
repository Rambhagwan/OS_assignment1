#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char* argv[]){
    if(argc==1){
        printf("wgrep: searchterm [file ...]\n");
        return 1;
    }
    FILE* fptr;
    int i;
    size_t size = 0;
    // argv[1] will be the item to e searched
    char* searching_thing = argv[1];
    char* bufferr = NULL;
    // argc == 2 means we are taking from standrd input
    if(argc==2){
        while(getline(&bufferr, &size, stdin)!=-1){
            if(strstr(bufferr, searching_thing)!=NULL)	printf("%s", bufferr);
            
        }
    }
    else
    {
	    for(i=2; i<=argc-1; i++){
	        fptr = fopen(argv[i],"r");
	        if(fptr==NULL){
	            printf("wgrep: cannot open file\n");
	            return 1;
	        }
	        while(getline(&bufferr, &size, fptr)!=-1){
	            if(strstr(bufferr, searching_thing)!=NULL)	printf("%s", bufferr);              
	           
	        
	    	}
	    	fclose(fptr);
		}
	}
    return 0;
}