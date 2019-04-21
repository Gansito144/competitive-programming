#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, ans = 0;
  cin >> N;
  vector <int> v(N);
  for (int &vi : v) cin >> vi;
  for (int i=1; i<N-1; ++i) {
    if (v[i]) continue;
    if (v[i-1] == 1 and v[i+1] == 1) {
      ++ans;
      v[i+1] = 0;
    }
  }
  cout << ans << endl;
  return 0;
}

