#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;

int main() {

	map<int,int> houses;
	
	int n, m, temp, ans = 0, prev = 0;
	
	scanf("%d %d", &n, &m);
	
	for(int i=0; i<n; i++) {
		scanf("%d", &temp);
		houses[temp] = i;
	}
		
	for(int i=0; i<m; i++){
		scanf("%d", &temp);
		ans += abs(prev - houses[temp]);
		prev = houses[temp];
	}	
	
	printf("%d\n", ans);	
	
	return 0;
}