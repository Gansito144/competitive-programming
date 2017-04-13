#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef long long int i64;

int main() {
  int tests, idx, len;
  char num[22];

  scanf("%d",&tests);
  for(int tc=1; tc<=tests; ++tc) {
    scanf("%s",num);
    // puts(num);
    len = strlen(num);
    for(idx = 1; idx < len; ++idx) {
      if(num[idx] < num[idx-1]) {
        do {
          --num[--idx];
        } while (idx > 0 && num[idx] < num[idx-1]);
        break;
      }
    }
    for(++idx; idx<len; ++idx) num[idx] = '9';
    printf("Case #%d: %lld\n",tc,atoll(num));
  }

  return 0;
}

