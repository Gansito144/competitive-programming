#include <iostream>
#include <algorithm>

using namespace std;

int main () {
  int N, M, T, t, r;
  scanf("%d %d %d %d %d",&N, &M, &T, &t, &r);
  int d = 0, h = 0;
  for (; d<N && M > 0; ++d){
    if (h + t <= T) {
      h += t;
      --M;
    } else {
      h = max(0, h - r);
    }
  }
  if (M) d = -1;
  printf("%d\n",d);
  return 0;
}

