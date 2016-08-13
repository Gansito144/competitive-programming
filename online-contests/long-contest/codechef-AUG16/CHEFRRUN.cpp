/*
 * Author: Ulises Mendez Martinez
 * Mail: ulisesmdzmtz@gmail.com
 * Solution: Detect cycles
*/

#include <iostream>
#define N 123456

using namespace std;

int main() {
  int tests, cnt, now;
  int n, a[N], seen[N];

  scanf("%d",&tests);
  while(tests--) {
    scanf("%d",&n);
    cnt = 0;
    for(int i=0; i<n; ++i) {
      scanf("%d",&a[i]);
      a[i] %= n;
      seen[i] = 0;
    }
    for(int i=0; i<n; ++i) {
      if(0 == seen[i]){
        now = i;
        while(0 == seen[now]){
          seen[now] = i+1;
          now = (now + 1 + a[now]) % n;
        }
        while(seen[now] > i) {
          seen[now] = -1;
          now = (now + 1 + a[now]) % n;
        }
      }
      //printf("seen[%d]: %d\n",i,seen[i]);
      cnt += (-1 == seen[i]);
    }
    printf("%d\n",cnt);
  }

  return 0;
}
