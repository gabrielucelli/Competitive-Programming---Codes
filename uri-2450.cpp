#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <map>
#include <math.h>
#include <vector>

#define INF 0x3f3f3f
#define MAXN 100000 + 10
#define MAXM 500 + 10

using namespace std;

int matriz[MAXN][MAXM];
int columns_zeros[MAXM];

void return_not() {
	printf("N\n");
	exit(0);
}

int main() {

	int n, m;
	
	scanf("%d %d", &n, &m);
	
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			scanf("%d", &matriz[i][j]);
			
	memset(columns_zeros, 0, sizeof(columns_zeros));
	
	int zeros = false;
	
	for(int i=0; i<n; i++) {
	
		int only_zeros = true;
		int first = true;
	
		for(int j=0; j<m; j++){
		
			if(zeros && matriz[i][j] != 0) {
				//printf("linha deveria ser zerada [%d, %d]\n", i, j);
				return_not();
			}
			
			if(matriz[i][j] != 0)
				only_zeros = false;
				
			if(columns_zeros[j] == 1 && matriz[i][j] != 0) {
				//printf("coluna deveria ser zerada [%d,%d]\n", i, j);
				return_not();
			}
				
			if(matriz[i][j] != 0 && first) {
				if(matriz[i][j-1] == 0 || j == 0){
					first = false;
					columns_zeros[j] = 1;
					if(j > 0) columns_zeros[j-1] = 1;
				}
			}							
			
		}
		
		zeros = only_zeros;
	}
		
	printf("S\n");	
	
	return 0;
}