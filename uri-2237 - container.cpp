#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int expect[8];
int old[8];

typedef struct {
	vi v;
	int cost;
} state;

typedef bool (*comp)(state, state);

bool compare(state a, state b){
    return a.cost > b.cost;
}

bool is_over(vi actual){
    for (int i = 0; i < 8; i++)
        if (actual[i] != expect[i]) return false;
    return true;
}

int a[] = {0, 0, 1, 1, 2, 2, 3, 4, 5, 6};
int b[] = {4, 1, 5, 2, 6, 3, 7, 5, 6, 7};

priority_queue<state, vector<state>, comp> pq(compare);

map<vi, int> dist;
map<vi, bool> visited;


int main() {

	for(int i=0; i<8; i++) scanf("%d", &old[i]);
	for(int i=0; i<8; i++) scanf("%d", &expect[i]);
	
	state init;
	
	init.v.resize(8);
	init.cost = 0;
	
	for(int i = 0; i < 8; i++) init.v[i] = old[i];
	
	pq.push(init);
	
	int ans = -1;
	
	while(!pq.empty()) {
	
		state u = pq.top();
		pq.pop();
		
		if(!visited[u.v]) {
			
			visited[u.v] = true;
			
			if(is_over(u.v)) {
				ans = u.cost;
				break;
			}
		
			for(int i = 0; i < 10; i++) {
			
				state v;
				v.cost = u.cost + u.v[a[i]] + u.v[b[i]];
				v.v.assign(u.v.begin(), u.v.end());
				swap(v.v[a[i]], v.v[b[i]]);
				
				if(!dist.count(v.v) || dist[v.v] > v.cost) {
					dist[v.v] = v.cost;
					pq.push(v);
				}
			
			}
		
		}
	
	}
	
	cout << ans << endl;
	
	return 0;
}