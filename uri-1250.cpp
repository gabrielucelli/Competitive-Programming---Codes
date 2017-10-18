#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main() {

	int n, t;
	char actions[50 + 5];
	int heights[50 + 5];
	scanf("%d", &n);
	getchar();
	
	for(int i=0; i<n; i++)
	{
		scanf("%d", &t);
		
		for(int j=0; j<t; j++)
			scanf("%d", &heights[j]);
		
		getchar();
		
		for(int j=0; j<t; j++)
			scanf("%c", &actions[j]);
		
		int ans = 0;
		
		for(int j=0; j<t; j++){
		
			//printf("[%d, %c]\n", heights[j], actions[j]);
		
			if(heights[j] > 2 && actions[j] == 'J')
				ans++;
			else if(heights[j] <= 2 && actions[j] == 'S')
				ans++;
			
		}
		
		printf("%d\n", ans);	
		
	}
	
	return 0;
}