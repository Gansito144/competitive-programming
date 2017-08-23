#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef long long int i64;

const int kMaxN = 1 << 15;
const bool debug = false;

int N;
i64 sa[kMaxN];
map <ii, int> dp;

int solve(int ini, int fin) {
  ii tup = {ini, fin};
  // Already proccessed
  if(dp.count(tup)) {
    if(debug) printf("[%d, %d] AP %d\n",ini,fin,dp[tup]);
    return dp[tup];
  }
  // Not divisible
  i64 sum = sa[fin]-sa[ini-1];
  if( (sum & 1LL) || (ini == fin)) {
    if(debug) printf("[%d, %d] ND %d\n",ini,fin,0);
    return dp[tup] = 0;
  }
  // All zeros
  if( sum == 0) {
    if(debug) printf("[%d, %d] ZS %d\n",ini,fin,fin-ini+1);
    return dp[tup] = fin - ini;
  }
  // General
  int mx = 0;
  bool ans = false;
  for(int k=ini; k<fin; ++k) {
    if( (sa[k]-sa[ini-1]) == (sum>>1) ) {
      mx = max(mx, solve(ini,k));
      mx = max(mx, solve(k+1,fin));
      ans = true;
      break;
    }
  }
  if(debug) printf("[%d, %d] GC %d\n",ini,fin,1+mx);
  return dp[tup] = mx + ans;
}

int main() {
  int tc;
  scanf("%d",&tc);
  do {
    int Ai;
    scanf("%d",&N);
    for(int i=1; i<=N; ++i) {
      scanf("%d",&Ai);
      sa[i] = sa[i-1] + Ai;
    }
    dp.clear();
    printf("%d\n", solve(1, N));
  } while(--tc);
  return 0;
}

