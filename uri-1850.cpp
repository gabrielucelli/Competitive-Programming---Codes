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
int visitados[MAXN][MAXN];
int keys[7];

int n;

int rec(int x, int y) {
		
	char temp = matriz[y][x];
	
	printf("%c\n", temp);

	if(temp == '#')
		return INF;
		
	if(temp == '*')
		return 0;	

	if(temp >= 'A' && temp <= 'G') {
		if(keys[temp - 'A'] != 1)
			return INF;
	}
	
	
	if(temp >= 'a' && temp <= 'g') {
		keys[temp - 'A'] = 1;
	}
		
	visitados[y][x] = 1;
	
	int ans = INF;
	
	//cima
	if(y - 1 >= 0 && visitados[y-1][x] == 0) {
		ans = min(rec(x, y-1)+1, ans);
	}
	
	//baixo
	if(y + 1 < n && visitados[y+1][x] == 0) {
		ans = min(rec(x, y+1) + 1, ans);
	}
	
	//direita
	if(x+1 < n && visitados[y][x+1] == 0) {
		ans = min(rec(x+1, y)+1, ans);
	}
	
	//esquerda
	if(x-1 >= 0 && visitados[y][x-1] == 0) {
		ans = min(rec(x-1, y)+1, ans);
	}
	
	visitados[y][x] = 0; 
	 
	if(temp >= 'a' && temp <= 'g') {
		keys[temp - 'A'] = 0;
	}
	
	return ans;
	
}

int main() {

	
	int x0, y0;
	
	memset(visitados, 0, sizeof(visitados));
	memset(keys, 0, sizeof(keys));
		
	scanf("%d", &n);
	getchar();
	
	for(int i=0; i<n; i++) {
	
		for(int j=0; j<n; j++) {
			scanf("%c", &matriz[i][j]);
			if(matriz[i][j] == '@'){
				x0 = j;
				y0 = i;
			}
		}
		
		getchar();
	}
	
	printf("%d\n", rec(x0, y0));
	
	return 0;
}