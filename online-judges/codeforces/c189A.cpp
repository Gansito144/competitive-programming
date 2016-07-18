/*
 * Author: Ulises Mendez Martinez
 * Mail: ulisesmdzmtz@gmail.com
 * Description: Use dp to review 
 * the maximum ribbon pieces
 * Special case: exact sum
*/

#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n, d[3], dp[4003]={0};
    
    scanf("%d %d %d %d",&n,&d[0],&d[1],&d[2]);
    dp[d[0]]=dp[d[1]]=dp[d[2]] = 1;
    for(int i=1; i<=n; ++i) {
        for(int j=0; j<3; ++j) {
            if(i-d[j]<0) continue;
            if(dp[i-d[j]] > 0){
                dp[i] = max(dp[i],dp[i-d[j]] + 1);
                //printf("%d %d %d %d\n",i,j,d[j],dp[i]);
            }
        }
    }
    printf("%d\n",dp[n]);

	return 0;
}