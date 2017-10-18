#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm> 

using namespace std;

bool compare(char* a, char* b) { 

	int la = strlen(a);
	int lb = strlen(b);
	
	return la > lb; 
}

int main() {

	int n;
	vector<char*> words;
	
	scanf("%d", &n);
	getchar();
	
	for(int i=0; i<n; i++)
	{
	
		char line[55*55];
		
		scanf("%[^\n]", line);
		getchar();
		
		int j;
		
		char* w = strtok (line," ");
		
		for ( j=0; w != NULL; j++)
		{
			words.push_back(w);
			//printf(">>%s<<\n", w);
			w = strtok (NULL, " ");
		}
		
		stable_sort(words.begin(), words.end(), compare);
		
		for(j = 0; j < words.size() - 1; j++)
		{
			printf("%s ", words[j]);
		}
		
		printf("%s\n", words[words.size() - 1]);
		
		words.clear();
		
	}

	
	return 0;
}