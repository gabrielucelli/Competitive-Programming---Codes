#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <vector>
#include <algorithm>

#define INF 999999
#define MAXVALUE 50000+5
#define MAXN 100+5 

using namespace std;

int n, m;
int coins[MAXN];
/*int dp[MAXN][MAXVALUE];

int rec(int i, int value) {
	if(value == 0) return 0;
	if(value < 0) return INF;
	if(i > n - 1) return INF;
	if(dp[i][value] != -1) return dp[i][value];
	return dp[i][value] = min(rec(i, value - coins[i]) + 1, rec(i+1, value));
}*/

int interative() {

	int memo[m + 1];
	memset(memo, INF, sizeof(memo));
	
	memo[0] = 0;

	for(int i = 1; i <= m ; i++) {
		
		for(int j = 0; j < n ; j++) {
		
			if(i - coins[j] >= 0)
				memo[i] = min(memo[i], memo[i - coins[j]] + 1);
						
		}
		
	}
	
	return memo[m];

}


int main() {

	while(true) {
		
		scanf("%d", &m);
		
		if(m == 0) return 0;
		
		scanf("%d", &n);
		
		for(int i = 0; i < n ; i++) scanf("%d", &coins[i]);
		
		//memset(dp, -1, sizeof(dp));
	
		int ans = interative();
		
		if(ans >= INF) printf("Impossivel\n");
		else printf("%d\n", ans);
		
	}
		
	return 0;
}