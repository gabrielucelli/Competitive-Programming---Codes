#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main() {

	int n;
	char line[100 + 5];
	
	scanf("%d", &n);
	getchar();
	
	for(int i=0; i<n; i++)
	{
		scanf("%[^\n]", line);
		getchar();
		//gets(line);
		
		//printf("lido: %s\n", line);
		
		int size = strlen(line);
		char temp[size+1];
		
		//first half
		for(int j = size/2 - 1, k = 0; j>=0; j--, k++)
			temp[k] = line[j];
			
		//last half
		for(int j = size - 1, k = size/2; j >= size/2; j--, k++)
			temp[k] = line[j];
		
		temp[size] = '\0';
			
		printf("%s\n", temp);
		
	}

	
	return 0;
}