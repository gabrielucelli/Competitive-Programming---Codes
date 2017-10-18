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

map<string, int> memo;

int f(string s) {

	if(memo.count(s)) return memo[s];
	if(s.size() == 1) return 0;
	
	int size_group = 0;
	int pos_init_group = 0;
	int ans = 0;
	
	for(int i = 0; i < s.size(); i++) {
	
		if(i != s.size() - 1 && s[i] == s[i+1]) continue;
		
		size_group = i - pos_init_group + 1;
		
		if(size_group > 1) {
			
			string new_s = s.substr(0, i - size_group + 1) + s.substr(i + 1);
			
			/*cout << "i " << i << endl;
			cout << "init " << pos_init_group << endl;
			cout << "size group " << size_group << endl; 
			cout << s << " -> " << new_s << endl << endl;*/
		
			ans = ans || f(new_s); 
		}		
		
		pos_init_group = i + 1;
		
	}
	
	return memo[s] = ans;
	
}

int main() {

	int k;
	scanf("%d", &k);
	
	memo[""] = 1;
	
	for(int i = 0; i < k; i++) {
		string s;
		cin >> s;
		cout << f(s) << endl;
		
	}
	
	return 0;
}