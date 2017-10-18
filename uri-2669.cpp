#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <vector>

#define MAXN 100000 + 5

using namespace std;

char entrada[MAXN];
char ans[26*MAXN];

int main() {

    scanf("%s", entrada);
    
    memset(ans, 0, sizeof(ans));
   
    for(int i = 0; i < strlen(entrada); i++) {
       
        int sum = entrada[i] - 'a' + 1;
        
        ans[sum] = 1;
       
        for(int j = i+1; j < strlen(entrada); j++) {
            sum += entrada[j] - 'a' + 1;
            ans[sum] = 1;
        }
    }    
   
   	long long int sum = 0;
   	
   	for(int i = 0; i < MAXN; i++) {
   		sum += ans[i];
   	}
   	
    printf("%lld\n", sum);

    return 0;
}
