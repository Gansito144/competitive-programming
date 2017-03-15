#include <iostream>
#include <algorithm>
#include <limits.h>
#include <stdio.h>

using namespace std;

typedef long long int i64;

const int MAXM = 100005;
const int MAXN = 5003;
const i64 oo = 1LL << 30;

int cows[MAXN];
int cost[MAXM];
i64  dp [MAXN];
int minToCover[MAXM];

i64 solve(int N) {
  for(int now=1; now<=N; ++now) {
    int L = 0;
    dp[now] = oo;
    for(int pre=1; pre<=now; ++pre) {
      int need_cover = cows[now] - cows[pre] + 1;
      int real_cover = minToCover[need_cover];
      i64 ncost = cost[real_cover];
      while( L+1<now && cows[L+1]+real_cover <= cows[now]) L++;
      dp[now] = min(dp[now], ncost + dp[L]);
      //printf("n(%d) p(%d) n(%d) r(%d) L(%d)\n",cows[now],cows[pre],need_cover,real_cover,L);
      //printf("nCost(%lld) dp[now](%lld)\n",ncost,dp[now]);
    }
  }
  return dp[N];
}

int main() {
  int n, m, xcow, size;
  i64 ans = LONG_MAX;

  scanf("%d %d",&n,&m);

  for(int i=1; i<=n; ++i) {
    scanf("%d",&cows[i]);
  }
  sort(cows+1, cows+n+1);

  for(int i=1; i<=m; i++) {
    scanf("%d",&cost[i]);
  }
  // Update costs
  int minStall = m;
  for(int i=m; i>0; --i) {
    if(cost[i] < cost[minStall]) minStall = i;
    minToCover[i] = minStall;
  }
  // Solve the problem
  printf("%lld\n",solve(n));
  return 0;
}

