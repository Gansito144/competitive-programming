#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int tests, n, ans1, ans2, m[1003], mxdiff;
  
  scanf("%d",&tests);
  for(int tst=1; tst<=tests; ++tst) {
    scanf("%d",&n);
    mxdiff = -1;
    ans1 = ans2 = 0;
    for(int i=1; i<=n; ++i) {
      scanf("%d",&m[i]);
      if(i > 1) {
        ans1  += max(m[i-1]-m[i], 0); 
        mxdiff = max(mxdiff, m[i-1]-m[i]);
      }
    }
    for(int i=1; i<n; ++i) {
      ans2 += min(m[i], mxdiff);
    }
    printf("Case #%d: %d %d\n",tst,ans1,ans2);
  }
  return 0;
}

