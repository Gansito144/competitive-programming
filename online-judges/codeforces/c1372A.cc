#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector <int> ans(n, 1);
    for (const int &a : ans) cout << a << " ";
    cout << "\n";
  }
  return 0;
}

