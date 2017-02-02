/*
 * Problem: OmegaUp Tanques
 */

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 5003;

int px[N], py[N], x[N][2], y[N][2];
int dp[N][2];

int main() {
    int n, pX, pY;
    
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) {
        scanf("%d %d",&px[i],&py[i]);
        // Keep in X side
        pX = dp[i-1][0] + abs(x[i-1][0] - px[i]);
        pY = dp[i-1][1] + abs(x[i-1][1] - px[i]);
        if(pX < pY){
            dp[i][0] = pX;
            y[i][0] = y[i-1][0];
        } else {
            dp[i][0] = pY;
            y[i][0] = y[i-1][1];
        }
        x[i][0] = px[i];

        // Keep in Y side
        pX = dp[i-1][0] + abs(y[i-1][0] - py[i]);
        pY = dp[i-1][1] + abs(y[i-1][1] - py[i]);
        if(pX <= pY){
            dp[i][1] = pX;
            x[i][1] = x[i-1][0];
        } else {
            dp[i][1] = pY;
            x[i][1] = x[i-1][1];
        }
        y[i][1] = py[i];
    }
    printf("%d\n",min(dp[n][0], dp[n][1]));
    return 0;
}