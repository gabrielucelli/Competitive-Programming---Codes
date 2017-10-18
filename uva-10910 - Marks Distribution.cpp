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
#define MAXN 70 + 5 

using namespace std;

int k, n, t, p;
int memo[MAXN][MAXN];

//top-down
int f(int num_subjects, int carry) {
	
	if(carry < 0) return 0;
	if(num_subjects == 0) return carry == 0;
	if(memo[num_subjects][carry] != -1) return memo[num_subjects][carry];
	
	int ans = 0;
	
	for(int i = p; i <= carry; i++)
		ans += f(num_subjects - 1, carry - i);
		
	return memo[num_subjects][carry] = ans;
	
}

//bottom up
int bottom_up() {

	memset(memo, 0, sizeof(memo));
	memo[0][0] = 1;
	
	for(int i = 1; i <= n; i++)
	for(int j = p; j <= t; j++)
	for(int l = p; l <= j; l++)
		memo[i][j] += memo[i-1][j-l] ; 	
	
}

int main() {

	scanf("%d", &k);
	
	for(int i = 0; i < k; i++) {
		scanf("%d %d %d", &n, &t, &p);
		bottom_up();
		printf("%d\n", memo[n][t]);
		
	}
	
	return 0;
}