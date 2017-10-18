#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <map>
#include <math.h>
#include <vector>

#define INF 0x3f3f3f
#define MAXN 100 + 10

using namespace std;

char matriz[MAXN][MAXN];

int main() {

	int n;
	
	scanf("%d", &n);
	getchar();
	
	for(int i=0; i<n; i++) {
	
		for(int j=0; j<n; j++) {
			scanf("%c", &matriz[i][j]);
		}
		
		getchar();
	}
			
	int toogle = 0;
	int ans;
	int count = 0;
	
	for(int i=0; i<n; i++) {
	
		char temp;
	
		if(!toogle) {
			for(int j=0; j<n; j++)	{
							
				temp = matriz[i][j];
				
				//printf("%c", temp);
				
				if(temp == 'o')
					count++;
				if(temp == 'A')
					count = 0;
					
				ans = max(ans, count);		
				
			}
		} else {
			for(int j=n-1; j>=0; j--){	
						
				temp = matriz[i][j];
				
				//printf("%c", temp);
				
				if(temp == 'o')
					count++;
				if(temp == 'A')
					count = 0;	
					
				ans = max(ans, count);				
				
			}
		}
			
		toogle = !toogle;
		
	}
	
	printf("%d\n", ans);
	
	return 0;
}