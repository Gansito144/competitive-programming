#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long i64;
typedef double decimal;

decimal const eps = 1e-12;

int main() {
  int N, tsts;
  decimal D, pos[1003], speed[1003], ans;
  
  cin >> tsts;
  for(int tc=1; tc<=tsts; ++tc) {
    cin >> D >> N;
    ans = 1LL << 62;
    for(int i=0; i<N; ++i) {
      cin >> pos[i] >> speed[i];
      if(pos[i] >= D) continue;
      decimal th = (D - pos[i]) / speed[i];
      decimal ns = (D + eps) / th;
      if( ns < ans ) ans = ns;
    }
    printf("Case #%d: %.6lf\n",tc,ans);
  }
  return 0;
}
