#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
  int N, T;

  scanf("%d %d",&N,&T);
  vector <int> v(N);
  for (int &vi : v) scanf("%d",&vi);
  sort(v.begin(), v.end());
  int asc = 0, desc = 0, sa = 0, sd = 0;
  for (int i=0; i<N; ++i) {
    if (sa + v[i] < T) {
      ++asc;
      sa += v[i];
    }
  }
  for (int i=N-1; i>=0; --i) {
    if (sd + v[i] < T) {
      ++desc;
      sd += v[i];
    }
  }
  printf("%d %d\n",desc,asc);
  return 0;
}

