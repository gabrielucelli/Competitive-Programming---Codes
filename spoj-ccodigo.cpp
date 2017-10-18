#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>

#define MAXN 1000+5 

using namespace std;

int main() {

	char in[MAXN];
	int v[MAXN];
	
	while(true) {
	
		scanf("%[^\n]", in);
		getchar();
		
		if(in[0] == '*') return 0;
		
		int ans = 0;
	
		for(int i = 0; i < strlen(in); i++) {
			v[i] = in[i] - 'a';
			if(v[i] >= 13) v[i] -= 26;
		}	
		
		
		for(int i = 0; i < strlen(in); i++) {
			printf("%d ", v[i]);
		}
		
		printf("\n\n");	
	
		for(int i = 0; i < strlen(in); i++) {
	
			if(v[i] == 0) continue;
		
			int hasToDown = v[i] > 0;
			int flag = i;
		
			for(int j = i + 1; j < strlen(in) + 1; j++) {
				flag = j;
				if(v[j] == 0) break;
				if(hasToDown && v[j] < 0) break;
				if(!hasToDown && v[j] > 0) break;
			
			}
			
			int temp = abs(v[i]);
			ans += temp;
			
			printf("i = %d flag = %d v = %d haveToDown = %s \n", i, flag, temp, hasToDown ? "sim" : "não");
		
			for(int j = i; j < flag; j++) {
				if(hasToDown) v[j] -= temp;
				else v[j] += temp;	
			}
			
			for(int j = 0; j < strlen(in); j++) {
				printf("%d ", v[j]);
			}
		
			printf("\n\n");	
			
		}
		
		printf("%d\n", ans);
	}
		
	return 0;
}