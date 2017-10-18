#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <vector>
#include <algorithm>

#define INF 999999
#define MAXN 55+5

using namespace std;
int n, m, k;
long long int memo[MAXN][MAXN];

long long int top_down(int position, int carry) {

	if(carry < 0) return 0;
	if(position == 0) return carry == 0;
	if(memo[position][carry] != -1) return memo[position][carry];
	
	long long int ans = 0;
	
	for(int j = 1; j <= m; j++) {
		ans += top_down(position - 1, carry - j);
	}	
	
	return memo[position][carry] = ans;
	
}

long long int bottom_up() {

	memset(memo, 0, sizeof(memo));
	memo[0][0] = 1;
	
	for(int i = 1; i <= k; i++)
	for(int j = 1; j <= n; j++)
	for(int l = 1; l <= m && j - l >= 0; l++)
		memo[i][j] += memo[i-1][j-l];
		
	return memo[k][n];	

}

int main() {

	while(scanf("%d %d %d", &n, &k, &m) != EOF) {
			
		memset(memo, -1, sizeof(memo));
		
		printf("%lld\n", bottom_up());
		
	}
		
	return 0;
}