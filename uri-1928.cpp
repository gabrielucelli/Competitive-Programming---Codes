#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#define MAXN 10000
#define INF 0x3f3f3f

using namespace std;


unsigned short int cards[MAXN];
unsigned char graph[MAXN][MAXN];
unsigned char visitado[MAXN];
int n, ans;
int card_wanted, initial_position;
unsigned char cards_flipped[MAXN];

int dfs(int no) {

 	visitado[no] = 1;
  
	if(initial_position != no && card_wanted == cards[no]) {
		cards_flipped[no] = 1;
		//printf("flipped: %d\n", no);
		return 0;
	}
  
  	int temp = -INF;
  	
	for(int i=0; i < n; i++) {
		//printf("visitado[%d] = %d\n", i, visitado[i] );
		//printf("graph[%d][%d] = %d\n\n", no, i, graph[no][i] );
		if(visitado[i] != 1 && graph[no][i] == 1) {
			//printf(">> indo %d para %d\n", no, i);
			temp = max(dfs(i) + 1, temp);
		}
	}
      
	return temp;
  
}

void clear_vistados() {
	for(int i=0; i<n; i++)
		visitado[i] = 0;
}



int main() {

	int a, b;
	
	memset(graph, 0, sizeof(graph));
	memset(cards_flipped, 0, sizeof(cards_flipped));
	
	scanf("%d", &n);
	getchar();
	
	for(int i=0; i<n; i++)
		scanf("%hi", &cards[i]);
		
	for(int i=0; i<n; i++){
		scanf("%d %d", &a, &b);
		graph[a-1][b-1] = 1;
		graph[b-1][a-1] = 1;
	}
	
	/*clear_vistados();
	card_wanted = cards[1];
	initial_position = 1;
	dfs(1);*/
	
	for(int i = 0; i < n; i++) {
	
		if(cards_flipped[i] == 1) {
			continue;
		}
			
		//printf("flipped: %d\n", i);
		clear_vistados();
		card_wanted = cards[i];
		initial_position = i;
		int temp = dfs(i);
		//printf("%d, %d: %d\n\n", i, card_wanted, temp);
		ans += temp;
		cards_flipped[i] = 1;
	}
	
	printf("%d\n", ans);	
	
	return 0;
}