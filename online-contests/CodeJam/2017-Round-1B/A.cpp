#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long i64;
typedef double decimal;

int main() {
  int N, tsts;
  decimal D, pos[1003], speed[1003];
  
  cin >> tsts;
  for(int tc=1; tc<=tsts; ++tc) {
    cin >> D >> N; 
    for(int i=0; i<N; ++i) cin >> pos[i] >> speed[i];
    decimal lo = 0.0, up = (1LL<<62);
    for(int stp = 0; stp < 1000; ++stp) {
      decimal mid = lo + (up-lo)/(2.0f);
      bool can = true;
      for(int i=0; i<N; ++i) {
        decimal th = (D-pos[i]) / speed[i];
        decimal ns = (D)/(th);
        if(ns < mid) {
          can = false;
          break;
        }
      }
      if(can) lo = mid;
      else up = mid;
    } 
    printf("Case #%d: %.6lf\n",tc,lo);
  }
  return 0;
}
