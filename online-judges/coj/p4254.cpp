#include <cstdio>
#include <vector>

using namespace std;

int main () {
  int C;

  scanf("%d",&C);
  vector <int> v(C);
  for (int &vi : v) {
    scanf("%d",&vi);
    vi += 4;
    vi /= 5;
  }

  int Q, p;

  scanf("%d",&Q);
  while (Q--) {
    scanf("%d",&p);
    printf("%d\n",v[p-1]);
  }
  return 0;
}

