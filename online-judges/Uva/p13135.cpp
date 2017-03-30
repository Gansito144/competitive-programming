#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

inline int gauss(int n) {
  return (n&1) ? ((n+1)>>1)*n : (n>>1)*(n+1) ;
}

int main() {
  int n, s, ans;
  
  scanf("%d",&n);
  while(n--) {
    scanf("%d",&s);
    ans = (1 << 14)-1;
    for(int k=13; k>= 0; k--) {
      ans ^= (gauss(ans^(1<<k))>=s) << k;
    } 
    if(gauss(ans) != s) puts("No solution");
    else printf("%d\n",ans-1);
  }
  return 0;
}

