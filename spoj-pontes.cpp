#include <cstdio>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <queue>
#include <algorithm>

#define INF 99999999

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> graph;

int n, m, s, t, b;

int dijkstra(int start, int end) {

	priority_queue < ii, vii, greater<ii> > pq;
	pq.push(make_pair(0, start));
	
	vi visited;
	visited.resize(n+2, false);
	
	vi dist;
	dist.resize(n+2, INF);
	dist[start] = 0;
	
	while(!pq.empty()) {
	
		int u = pq.top().second; //minimum of heap (minimum cost)
		pq.pop();
		
		if(!visited[u]) {
		
			visited[u] = true;
			
			for(int i = 0; i < graph[u].size(); i++) {
			
				int v = graph[u][i].second;
				int cost = graph[u][i].first;
				int cost_now = dist[u] + cost;
				
				if(dist[v] > cost_now) {
					
					dist[v] = cost_now;
					pq.push(make_pair(cost_now, v));
				}
					
			}		
			
		}
		
	}
	
	return dist[end];
		
	
}

int main() {

	scanf("%d %d", &n, &m);
	
	graph.resize(n + 2);
	
	for(int i = 0; i < m; i++) {
	
		scanf("%d %d %d", &s, &t, &b);
		graph[s].push_back(make_pair(b, t)); //pair(cost, dst)
		graph[t].push_back(make_pair(b, s));
		
	}
	
	cout << dijkstra(0, n+1) << endl;	
	
	return 0;
}