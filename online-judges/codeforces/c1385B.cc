#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
  int tc;
  cin >> tc;

  while (tc--) {
    int n, l = -1;
    cin >> n;
    n <<= 1;
    vector <int> v(n);
    for (int& vi : v) cin >> vi;
    for (int i=0; i<n; i++) {
      if (v[i] == -1) continue;
      cout << v[i] << " ";
      l = max(i+1, l);
      while (v[l] != v[i]) ++l;
      v[l] = -1;
    }
    cout << "\n";
  }
  return 0;
}

