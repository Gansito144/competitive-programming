#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int t, n, pr, now, old, dp[2][2], b[123456];
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        memset(dp,0,sizeof dp);
        // initialize
        now = 1, old=0;
        for(int i=1; i<=n; ++i) {
            scanf("%d",&b[i]);
            if(i == 1) continue;
            dp[now][0] = max(dp[old][0], dp[old][1]+b[i-1]-1);
            dp[now][1] = max(dp[old][0]+b[i]-1, dp[old][1]+abs(b[i]-b[i-1]));
            swap(old,now);
        }   
        printf("%d\n",max(dp[old][0],dp[old][1]));
    }
    return 0;
}