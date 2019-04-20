#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using i64 = long long int;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, m, h;

  cin >> n >> m >> h;
  vector <int> row(n);
  vector <int> col(m);

  for (int &c : col) cin >> c;
  for (int &r : row) cin >> r;

  for (int r=0; r<n; ++r) {
    for (int c=0; c<m; ++c) {
      int z;
      cin >> z;
      cout << (z == 0 ? 0 : min(row[r], col[c])) << " ";
    }
    cout << endl;
  }
  return 0;
}

