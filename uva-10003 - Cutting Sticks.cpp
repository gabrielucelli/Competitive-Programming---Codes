#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <vector>
#include <algorithm>

#define INF 999999
#define MAXN 50+2 

using namespace std;

int l, n;
int c[MAXN];
int t[MAXN];
int dist[MAXN][MAXN];
int memo[MAXN][MAXN];

/* top down */
int rec(int u, int v) {

	if(u == v) return 0;
	
	if(memo[u][v] != -1) return memo[u][v];
	
	int aux = INF;
	
	for(int i = u + 1; i <= v; i++) {
		aux = min(aux, rec(u, i - 1) + rec(i, v) + dist[u][v]);	
	}
	
	return memo[u][v] = aux;
	
}

int bottom_up() {

	for(int i = 0; i < n + 1; i++) memo[i][i] = 0;
	
	for(int stubs = 2; stubs <= n + 1; stubs++)
	for(int u = 0; u <= n + 1 - stubs; u++) {
	
		int v = u + stubs - 1;
		memo[u][v] = INF;
		
		for(int k = u; k < v; k++) {
			memo[u][v] = min(memo[u][v], memo[u][k] + memo[k+1][v] + dist[u][v]);
		}
		
	}
	
	return memo[0][n];
	
}

int main() {

	while(true) {
		
		scanf("%d", &l);
		
		if(l == 0) return 0;
		
		scanf("%d", &n);
		
		for(int i = 0; i < n ; i++) 
			scanf("%d", &c[i]);
		
		/* t is the vector with sizes of stubs */
		t[0] = c[0];
		t[n] = l - c[n-1];
		
		for(int i = 1; i < n; i++) 
			t[i] = c[i] - c[i-1];
		
		memset(dist, 0, sizeof(dist));
		
		/* save the dist between the stubs */
		for(int i = 0; i < n+1; i++)
		for(int j = 0; j < n+1; j++)
		for(int l = i; l < j+1; l++) 
			dist[i][j] += t[l];
			
		//memset(memo, -1, sizeof(memo));
		
		printf("The minimum cutting is %d.\n", bottom_up());
		
	}
		
	return 0;
}