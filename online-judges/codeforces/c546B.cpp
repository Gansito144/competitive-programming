#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
  int N;

  cin >> N;
  vector <int> v(N);
  for (int& vi: v) cin >> vi;
  sort(v.begin(), v.end());

  int next = v[0]+1, ans = 0;

  for (int i=1; i<N; ++i) {
    if (v[i] < next) ans += next - v[i];
    next = max(next, v[i]) + 1; 
  }
  cout << ans << endl;
  return 0;
}


