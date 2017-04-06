#include <stdio.h>
#include <algorithm>

using namespace std;

typedef long long int i64;

const int MaxB = 1003;
i64 M[MaxB];

i64 f(i64 T, int B, int N) {
  i64 tot = 0;
  for(int i=0; i<B; ++i) {
    tot += T/M[i] + 1LL;  
  }
  return tot >= N;
}

i64 binary_search(int &B, int &N) {
  i64 ans = (1LL << 60) - 1LL;
  for(int k=59; k>=0; --k) {
    ans ^= f(ans ^ (1LL<<k), B, N) << k;
  }
  return ans;
}

int main() {
  int noCases, B, N, ans;
  i64 sec;

  scanf("%d",&noCases);
  for(int tc=1; tc<=noCases; ++tc) {
    scanf("%d %d",&B,&N);
    for(int i=0; i<B; ++i) {
      scanf("%lld",&M[i]);
    }
    // Calculate in which second you will be attended
    sec = binary_search(B,N);  
    // printf("You will be attended at %lld sec\n",sec);
    // Need to count which others will be attended in that time
    i64 before = 0;
    if(sec > 0LL) {
      --sec;
      for(int i=0; i<B; ++i) {
        before += sec/M[i] + 1LL;
      }
      ++sec;
    }
    // printf("%lld Has been attended before second %lld\n",before, sec);
    before = N - before;
    ans = -1;
    for(int i=0; i<B; ++i) {
      if(sec % M[i] == 0LL) {
        --before;
        if(before == 0LL) {
          ans = i+1;
          break;
        }
      } 
    }
    printf("Case #%d: %d\n",tc,ans);
  }
  return 0;
}


