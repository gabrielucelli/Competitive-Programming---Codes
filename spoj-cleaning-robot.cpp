#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <vector>
#include <algorithm>

#define INF 99999999

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vector<vi> graph;
vector<int> pontos;
char map[20+5][20+5];

int pos_robot;

int minimum_cost(int start, int end) {

	queue<ii> q;
	q.push(make_pair(0, start));
	
	vi visited;
	visited.resize(graph.size(), 0);
	visited[start] = 1;
	
	while(!q.empty()) {
	
		ii cur = q.front();
		q.pop();
		
		if(cur.second == end)
			return cur.first;
		
		for(int i=0; i < graph[cur.second].size(); i++) {
		
			int elem = graph[cur.second][i];
			
			if(visited[elem] == 0) {
				q.push(make_pair(cur.first + 1, elem));
				visited[elem] = 1;
			}
		 
		}
	}
	
	return INF;
	
}

int main() {

	int w, h;
	
	while(true) {
	
		graph.clear();
		pontos.clear();
	
		scanf("%d %d", &w, &h );
		getchar();
		
		if(w == 0 && h == 0)
			return 0;
	
		graph.resize(w*h);
	
		for(int i=0; i<h; i++) {
	
			for(int j=0; j<w; j++) {
			
				char temp;
				scanf("%c", &temp);
			
				map[i][j] = temp;
			
				if(temp == 'o') {
					pos_robot = i*w + j;
				} else if(temp == '*') {
					pontos.push_back(i*w + j);
				} else if(temp == 'x') {
			
					if(i > 0)
						remove(	graph[(i-1)*w + j].begin(),
								graph[(i-1)*w + j].end(),
								i*w + j);
				
					if(j > 0)
						remove(	graph[i*w + j-1].begin(),
								graph[i*w + j-1].end(),
								i*w + j);
				
					continue;
				
				}
			
				if(i>0 && map[i-1][j] != 'x')
					graph[i*w+j].push_back((i-1)*w + j);
				
				if(i < h-1)
					graph[i*w+j].push_back((i+1)*w + j);
				
				if(j>0 && map[i][j-1] != 'x' )
					graph[i*w+j].push_back(i*w + j - 1);
				
				if(j < w-1)
					graph[i*w+j].push_back(i*w + j + 1);
			
			
			}
		
			getchar();
		
		}
	
		int somax = INF;
		int dists[11][11];
		int dist_ini[11];
	
		for(int i = 0; i<pontos.size(); i++) {
			for(int j = i+1; j<pontos.size(); j++) {
				dists[i][j] = minimum_cost(pontos[i], pontos[j]);
				dists[j][i] = dists[i][j];
			}
		}
	
		for(int i = 0; i < pontos.size(); i++) {
			dist_ini[i] = minimum_cost(pos_robot, pontos[i]);
		}
	
		vector<int> idx(pontos.size());
	
		for(int i = 0; i < idx.size(); i++) {
			idx[i] = i;
		}
	
		do {
	
			int soma = 0;
			soma += dist_ini[idx[0]];
		
			for(int i = 0; i < idx.size() - 1; i++)
				soma += dists[idx[i]][idx[i+1]];
		
			somax = min(soma, somax);
		
		} while(next_permutation(idx.begin(), idx.end()));
	

		if(somax >= INF)
			cout << "-1" << endl;
		else
			cout << somax << endl;
	}
	
	return 0;
}