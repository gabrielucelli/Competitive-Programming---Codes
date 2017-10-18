#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

#define INF 999999
#define MAXN 10000 + 5 

using namespace std;

int n, t;
int memo[MAXN];
int square[102];

int bottom_up() {
	
	for(int i = 0; i <= 101; i++)
		square[i] = i*i;
		
	for(int i = 0; i < MAXN; i++)
		memo[i] = INF;
		
	memo[0] = 0;
	memo[1] = 1;

	for(int j = 2; j < MAXN; j++) 
	for(int i = 0; square[i] <= j; i++)
		memo[j] = min(memo[j], memo[j-square[i]] + 1);
	

}

int main() {

	scanf("%d", &t);
	
	bottom_up();
	
	for(int i = 0; i < t; i++) {
		scanf("%d", &n);
		printf("%d\n", memo[n]);
		
	}
	
	return 0;
}