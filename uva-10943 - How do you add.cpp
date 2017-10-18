#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <vector>
#include <algorithm>

#define INF 999999
#define MAXN 100+5
#define MOD 1000000

using namespace std;

int k, n;
long long memo[MAXN][MAXN];

int main() {

	while(true) {
		
		scanf("%d %d", &n, &k);
		
		if(n == 0 && k == 0) return 0;
		
		/* base cases */
		
		for(int i = 0; i <= k; i++) memo[0][i] = 1;
		
		for(int i = 0; i <= n; i++) { 
			memo[i][0] = 0;
			memo[i][1] = 1;
		}
		
		/* bottom up */
		
		for(int i = 1; i <= n; i++)
		for(int j = 2; j <= k; j++)
			memo[i][j] = (memo[i-1][j]%MOD + memo[i][j-1]%MOD)%MOD;
		
		printf("%lld\n", memo[n][k]);
		
	}
		
	return 0;
}