#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <vector>
#include <algorithm>

#define MAXVALUE 100000+5
#define MAXM 1000+5 

using namespace std;

int v, m;
int coins[MAXM];
/* int dp[MAXM][MAXVALUE];

int rec(int i, int value) {
	if(dp[i][value] != -1) return dp[i][value];
	if(value == 0) return true;
	if(value < 0) return false;
	if(i > m - 1) return false;
	return dp[i][value] = rec(i+1, value - coins[i]) || rec(i+1, value);	
} */

int interative() {

	int possible_values[v + 1];
	memset(possible_values, 0, sizeof(possible_values));
	
	possible_values[0] = true;

	for(int i = 0; i < m ; i++) {
		
		for(int j = v; j >= coins[i]; j--) {
		
			if(possible_values[j-coins[i]])
				possible_values[j] = true;
			
		}
		
	}
	
	return possible_values[v];

}


int main() {

	scanf("%d %d", &v, &m);
	
	//memset(dp, -1, sizeof(dp));
	
	for(int i = 0; i < m; i++)
		scanf("%d", &coins[i]);
	
	printf("%c\n", interative() == 1 ? 'S' : 'N' );
		
	return 0;
}