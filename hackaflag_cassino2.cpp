#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <vector>
#include <algorithm>

#define MAXN 1000+2 

using namespace std;

int n;
int c[MAXN];
int memo[2][MAXN][MAXN];

int dp(int player, int begin, int end) {

	if(end == 0 || begin == n-1 || begin > end) 
		return 0;
		
	if(memo[player][begin][end] != -1)
		return memo[player][begin][end];
	
	if(player == 0) {
		int first_choice = dp(1, begin + 1, end) + c[begin];
		int second_choice = dp(1, begin, end - 1) + c[end];
		return max(first_choice, second_choice);
	} else {
		//igore cost
		int first_choice = dp(0, begin + 1, end);
		int second_choice = dp(0, begin, end - 1);
		return max(first_choice, second_choice);
	}

}

int main() {
	
	scanf("%d", &n);
	
	memset(memo, -1, sizeof(memo));
	
	for(int i = 0; i < n ; i++) 
		scanf("%d", &c[i]);
	
	printf("%d\n", dp(0, 0, n-1));
		
	return 0;
}