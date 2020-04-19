#include<iostream>
#include <set>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tc;
  cin >> tc;
  while (tc--) {
    int n, x, mx, a;
    cin >> n >> x;
    set <int> s;
    while (n--) {
      cin >> a;
      s.insert(a);
    }
    mx = 0;
    for (int i=1; x>0; ++i) {
      if(s.find(i) == s.end()) {
        --x;
      }
      mx = i;
    }
    while (s.find(mx+1) != s.end()) ++mx;
    cout << mx << "\n";
  }

  return 0;
}


