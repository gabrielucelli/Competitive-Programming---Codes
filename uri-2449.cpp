#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <map>
#include <math.h>

#define INF 0x3f3f3f
#define MAXN 1000 + 10

using namespace std;

int h[MAXN];
int n, wanted_h, ans = 0;

int main() {

	
	scanf("%d %d", &n, &wanted_h);
	
	for(int i=0; i<n; i++)
		scanf("%d", &h[i]);
	
	for(int i = 0; i < n - 1; i++) {
		int diff = wanted_h - h[i];
		h[i] += diff;
		h[i+1] += diff;
		ans += abs(diff);
	} 
		
	printf("%d\n", ans);	
	
	return 0;
}