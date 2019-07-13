#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int R, C;
  cin >> R >> C;

  vector <vector <int>> m(R+1, vector<int> (C+1));

  for (int r=1; r<=R; ++r) {
    for (int c=1; c<=C; ++c) {
      cin >> m[r][c];
      m[r][c] += m[r][c-1];
    }
  }
  int ans = 0LL;

  for (int c=1; c<=C; ++c) {
    for (int w=0; w+c<=C; ++w) {
      int H = 0;
      int a = 0;
      for (int r=1; r<=R; ++r) {
        a += m[r][c+w] - m[r][c-1];
        if (!a) {
          ++H;
          ans = max(ans, (H<<1)+((w+1)<<1));
        } else H = 0;
        a = 0;
      }
    }
  }
  cout << ans << "\n";
  return 0;
}

