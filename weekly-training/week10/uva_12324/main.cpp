#include <iostream>
#include <queue>
#include <utility>
#include <stdio.h>
 
#define mp make_pair
 
using namespace std;
 
const int kMaxN = 102;
int T[kMaxN], B[kMaxN];
 
int main() {
  int n, sum, ans;
  while(scanf("%d",&n), n) {
    ans = sum = 0;
    for(int i=1; i<=n; ++i) {
      scanf("%d %d",&T[i],&B[i]);
      sum += B[i];
    }

    priority_queue < pair<int,int> > PQ;
    for(int i=n; i>0; --i) {
      while(B[i]-- && !PQ.empty()) {
        int idx = PQ.top().second;
        int cost = PQ.top().first;
        PQ.pop();
        ans += cost >> 1;
        T[idx] = 0;
      }
      PQ.push(mp(T[i],i));
    }

    for(int i=1; i<=n; ++i) {
      ans += T[i];
    }
    printf("%d\n",ans);
  }
  return 0;
}
