#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	FILE* fptr;
	char c;
	if(argc==1)
	{
		return 0;
	}

	for(int i = 1; i<argc; i++)
	{
		fptr = fopen(argv[i], "r");
		if(fptr==NULL)
		{
			printf("wcat: cannot open file\n");
			exit(1);
		}
		else
		{
			c = fgetc(fptr);
			while(c!=EOF)
			{
				printf("%c",c);
				c = fgetc(fptr);
			}


		}
		fclose(fptr);
	}
	return 0;
}