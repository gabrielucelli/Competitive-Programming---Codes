#include <iostream>
#include <cmath>

using namespace std;

int mdc(int a, int b)
{

  if (b == 0)
      return a;
  else
      return mdc(b, a % b);
}



int main()
{

	int a, b, c;
	
	while(cin >> a >> b >> c)
	{
		if( (a*a + b*b == c*c) || (a*a + c*c == b*b) || (c*c + b*b == a*a) )
		{
			if(mdc(a,b) == 1 && mdc(a,c) == 1 && mdc(c,b))
			{
				cout << "tripla pitagorica primitiva" << endl;
			}
			else
			{
				cout << "tripla pitagorica" << endl;
			}
		}
		else
		{
			cout << "tripla" << endl;
		}
	}
	
	return 0;
}