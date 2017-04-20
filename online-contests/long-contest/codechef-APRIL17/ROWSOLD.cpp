#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

typedef long long int i64;
char s[123456];
int cost[123456];

int main() {
  int tests, len, last;
  i64 ans, prv;

  scanf("%d",&tests);
  while(tests--) {
    scanf("%s",s);
    ans = prv = 0LL;
    last = len = strlen(s);
    cost[len] = 0LL;
    for(int i=len-1; i>=0; --i) {
      if(s[i] == '0') continue;
      //printf("i:%d l:%d c:%d\n",i,last,cost[last]);
      if(last-i > 1)
        cost[i] = ((last-i)) + cost[last];
      else 
        cost[i] = cost[last];
      ans += cost[i];
      last = i;
    }
    printf("%lld\n",ans);
  }
  return 0;
}

