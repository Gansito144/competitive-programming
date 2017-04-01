#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <memory.h>


using namespace std;

const int MaxL =  1003;
const int   oo = 1<<30;
const int    Z =    27;

char     s[MaxL];
int  dp[MaxL][Z];
int cnt[MaxL][Z];
int chunks[MaxL];

int main() {
  int  cases,  K,  size;
  int  bucket, ans, can;

  scanf("%d",&cases);
  while(cases--) {
    scanf("%d %s",&K,s);
    size = strlen(s);
    bucket = 0;
    for(int i=0; i<size; ++i) {
      if(i%K == 0) {
        ++bucket;
        memset(cnt[bucket], 0, sizeof cnt[bucket]);
      }
      ++cnt[bucket][s[i]-'a']; 
    }
    for(int i=1; i<=bucket; ++i) {
      chunks[i] = 0;
      for(int j=0; j<Z; ++j) {
        chunks[i] += (cnt[i][j] > 0);
      }
    }
    // DP Table
    for(int i=1; i<=bucket; ++i) {
      for(int j=0; j<Z; ++j) {
        ans = oo;
        if(cnt[i][j] != 0) {
          for(int k=0; k<Z; ++k) {
            if(cnt[i][k]==0 || cnt[i-1][k]==0) {
              ans = min(ans, dp[i-1][k] + chunks[i]);
            } else {
              can = (k==j) ? (K==cnt[i][k]) : 1;
              ans = min(ans, dp[i-1][k] + chunks[i] - can);
            }
          }
        }
        dp[i][j] = ans;
      }
    }

    ans = oo;
    for(int i=0; i<Z; ++i) {
      ans = min(ans, dp[bucket][i]);
    }
    printf("%d\n",ans);
  }

  return 0;
}

