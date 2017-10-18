#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
	
	char line[200];
	int i;
	int flag;
	char c;
	int a;
		
	while(scanf("%[^\n]", line) != EOF)
	{
	
		getchar();
		
		flag = 1;
		
		for(i=0; i < strlen(line); i++)
		{
	
			if(!isalpha(line[i]))
				continue;
			
			if(flag == 1)
			{
				if(!isupper(line[i]))
					line[i] = toupper(line[i]);
					
				flag = 0;
					
			} 
			else 
			{
				if(!islower(line[i]))
					line[i] = tolower(line[i]);
				
				flag = 1;
			}			
			
		}
		
		printf("%s\n", line);
		
	}
	
	
	return 0;
}