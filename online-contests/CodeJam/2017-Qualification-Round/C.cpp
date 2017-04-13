#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

priority_queue< int, vector<int> > PQ;

int main() {
  int tests, N, K, gap, a, b;
  
  scanf("%d",&tests);
  for(int tc=1; tc<= tests; ++tc) {
    scanf("%d %d",&N,&K);
    while(!PQ.empty()) PQ.pop();
    PQ.push(N);
    while(--K) {
      gap = PQ.top();
      PQ.pop();
      PQ.push(gap >> 1);
      PQ.push((gap-1) >> 1);
    }
    gap = PQ.top();
    a = gap >> 1;
    b = (gap-1) >> 1;
    printf("Case #%d: %d %d\n",tc,a,b);
  }
  return 0;
}

