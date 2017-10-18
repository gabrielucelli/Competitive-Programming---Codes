#include <iostream>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int memo_inv[10000+5];
int memo_add[10000+5];

int inverte(int a)
{

	char buffer[15];
	
	sprintf(buffer,"%d", a);
	
	char saida[15];
	
	for(int i=0; i<strlen(buffer); i++)
	{
		saida[i] = buffer[strlen(buffer) - i - 1];
	}
	
	saida[strlen(buffer)] = '\0';
	
	int out = atoi(saida);
	
	//cout << a << " inverte " << out << endl;
	
	return out;
}

int rec(int a, int b)
{
	cout << "entrou aqui " << a << " " << b << endl;

	if(a == b)
		return 0;
		
	if( a > b )
	{
		return 99999999;
	}
	
	//pode os dois
	
	int r2 = 9999999;
	
	if(memo_inv[inverte(a)] == 0)
	{
		memo_inv[inverte(a)] = 1;
		r2 = rec(inverte(a), b) + 1;
		memo_inv[inverte(a)] = 0;
	}
	
	int r1 = 9999999;
	
	if(memo_add[a+1] == 0)
	{
		memo_add[a+1] = 1;
		r1 = rec(a+1, b) + 1;
		memo_add[a+1] = 0;
	}
	
	
	return min(r1, r2);	
}



int main()
{
	int k, a, b;
	
	while(cin >> k)
	{
		memset(memo_inv, 0, sizeof(memo_inv));
		memset(memo_add, 0, sizeof(memo_add));
		
		for(int i=0; i<k; i++)
		{
			cin >> a >> b;
			
			cout << rec(a, b) << endl;
		}
	}
	
	return 0;
}