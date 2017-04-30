#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <utility>
#include <math.h>

#define pi (2.0*acos(0.0))
#define F first 
#define S second

using namespace std;

typedef long long D;
typedef pair<D, D> dd;

const bool debug = false;
const int kMaxN = 1003;
const int kNull =   -1;
const D   kInf  =  1LL << 60;

int N, K;
dd P[kMaxN];
D dp[kMaxN][kMaxN];

bool cmp(dd A, dd B) {
  return A > B;
}

int main() {
  int T;

  scanf("%d",&T);
  for(int tc=1; tc<=T; ++tc) {
    scanf("%d %d",&N,&K);
    for(int i=0; i<N; ++i) scanf("%lld %lld",&P[i].F,&P[i].S);
    
    sort(P, P+N, cmp);

    for(int i=0; i<N; ++i) {
      dp[1][i] = (P[i].F * P[i].F) + ((P[i].S*P[i].F)<<1LL);
      if(debug) printf("dp[%d, %d]=%lld\n",1,i,dp[1][i]);
    }

    for(int k=2; k<=K; ++k) {
      for(int p=k-1; p<N; ++p) {
        {
          dp[k][p] = 0LL;
          for(int o=0; o<p; ++o) {
            dp[k][p] = max(dp[k][p], dp[k-1][o]);
          }
          dp[k][p] += ((P[p].S*P[p].F)<<1LL);
        }
       if(debug) printf("dp[%d, %d]=%lld\n",k,p,dp[k][p]);
      }
    }

    D ans = 0LL;
    for(int i=K-1; i<N; ++i) {
      ans = max(ans, dp[K][i]);
      if(debug) printf("dp[%d, %d]=%lld\n",K,i,dp[K][i]);
    }
    printf("Case #%d: %.10lf\n",tc, pi*ans);
  }
  return 0;
}

