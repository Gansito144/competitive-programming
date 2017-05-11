#include <stdio.h>
#include <limits.h>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long int i64;

i64 dp[201][300001], sa[300001], ans;
int b[201];
bool seen[201][300001];

i64 solve(int m, int k, int op) {
  i64 &r = dp[m][k], ret, dif;
  if(seen[m][k]) {
    return r;
  }
  seen[m][k] = true;
  dif = (sa[k] - sa[k-b[m]]);
  dif = (op) ? -dif : dif;
  if(m > 1) {
    r = (op) ? LONG_MIN : LONG_MAX;
    for(int i = k-b[m]+b[m-1]+1; i<k; ++i) {
      ret = solve(m-1, i, op^1);
      r = op ? max(r, ret) : min(r, ret);
    }
    return r = dif + r;
  }
  return r = dif;
}

int main() {
  int T, N, M;

  scanf("%d",&T);
  while(T--) {
    scanf("%d %d",&N, &M);
    for(int i=1; i<=N; ++i) {
      scanf("%lld",&sa[i]);
      sa[i] += sa[i-1];
      for(int j=1; j<=M; ++j) {
        seen[j][i] = false;
      }
    }
    for(int i=M; i>0; --i) scanf("%d",&b[i]);
    ans = LONG_MIN;
    for(int i=b[M]; i<=N; ++i) {
      i64 ret = solve(M, i, 0);
      ans = max(ans, ret); 
    }
    printf("%lld\n",ans);
  }
  return 0;
}