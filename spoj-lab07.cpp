#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

#define NMAX 55
#define INF 99999999

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, m;
int map[NMAX][NMAX];

int calculate_heigth(int height, int time) {
	return (height + time)%10;
}

int time_until_can_jump(int heightA, int heightB) {

	if(heightA >= heightB - 1)
		return 1;
	else
		return 9 - heightB + 2;
}

int dijkstra() {

	priority_queue < ii, vii, greater<ii> > pq;
	pq.push(make_pair(0, 0));
	
	vi visited;
	visited.resize(m*n, false);
	
	vi dist;
	dist.resize(n*m, INF);
	dist[0] = 0;
	
	while(!pq.empty()) {
	
		ii cur = pq.top();
		pq.pop();
		
		int i = (int)(cur.second /  m); //i*w + j
		int j = cur.second % m;
		int u = cur.second;
		int time = cur.first;
		
		if(!visited[u]) {
		
			visited[u] = true;
			
			int height_now = (map[i][j] + time) % 10;

			if(i > 0) {
			
				int cost_u2v = time_until_can_jump(height_now, calculate_heigth(map[i-1][j], time));
				int v = (i-1)*m + j;
				int cost_v = dist[u] + cost_u2v;
			
				if(dist[v] > cost_v) {
					dist[v] = cost_v;
					pq.push(make_pair(cost_v, v));
				}
			}
			
			
			if(i < n - 1) {
			
				int cost_u2v = time_until_can_jump(height_now, calculate_heigth(map[i+1][j], time));
				int v = (i+1)*m + j;
				int cost_v = dist[u] + cost_u2v;
			
				if(dist[v] > cost_v) {
					dist[v] = cost_v;
					pq.push(make_pair(cost_v, v));
				}
			
			}
			
				
			if(j > 0) {
			
				int cost_u2v = time_until_can_jump(height_now, calculate_heigth(map[i][j-1], time));
				int v = i*m + j - 1;
				int cost_v = dist[u] + cost_u2v;
			
				if(dist[v] > cost_v) {
					dist[v] = cost_v;
					pq.push(make_pair(cost_v, v));
				}	
				
			}
			
			if(j < m - 1) {
				
				int cost_u2v = time_until_can_jump(height_now, calculate_heigth(map[i][j+1], time));
				int v = i*m + j + 1;
				int cost_v = dist[u] + cost_u2v;
			
				if(dist[v] > cost_v) {
					dist[v] = cost_v;
					pq.push(make_pair(cost_v, v));
				}		
				
			}		
			
		}
		
	}
	
	return dist[n*m-1];
	
}

int main() {

	scanf("%d %d", &n, &m);
	
	int temp;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m ; j++) {
			scanf("%d", &temp);
			map[i][j] = temp;
		}
	}	
	
	printf("%d\n", dijkstra());
	
	return 0;
}