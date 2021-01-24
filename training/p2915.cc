#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int N, ans = 0;
  cin >> N;
  vector <int> p( N );
  for (int &pi : p) cin >> pi;
  for (int i = 1; i < N; ++i) ans += (p[ i-1 ] < p[ i ]);
  cout << ans + 1 << endl;

  return 0;
}

