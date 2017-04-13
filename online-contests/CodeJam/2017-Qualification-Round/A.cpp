#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <string.h>

using namespace std;

int main() {
  int tests, K, len, ans;
  char pck[2003];

  scanf("%d",&tests);
  for(int tc=1; tc<=tests; ++tc) {
    scanf("%s %d\n",pck,&K);
    len = strlen(pck);
    ans = 0;
    for(int i=0; i<len; ++i) {
      if(pck[i] != '+') {
        if(i+K-1 >= len) {
          ans = -1;
          break;
        } else {
          for(int j=0; j<K; ++j) {
            pck[i+j] = (pck[i+j] == '+') ? '-' : '+';
          }
          ++ans;
        }
      }
    }
    if(ans == -1) printf("Case #%d: IMPOSSIBLE\n",tc);
    else printf("Case #%d: %d\n",tc,ans);
  }

  return 0;
}

