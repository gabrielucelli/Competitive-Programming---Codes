#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
	int k, n;
	set<string> set;
	
	cin >> k;
	
	while(cin >> n)
	{
		set.clear();
		
		for(int i = 0; i<n; i++)
		{
			string idioma;
			cin >> idioma;
			set.insert(idioma);
		}
		
		if(set.size() > 1)
		{
			cout << "ingles" << endl;
		}
		else
		{
			cout << *(set.begin()) << endl;
		}
	}
	
	return 0;
}