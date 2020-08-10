#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <set>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int N, ai;
  cin >> N;
  vector <int> cnt(100001);
  multiset <int, greater<int>> t;
  for (int i=0; i<N; ++i) {
    cin >> ai;
    ++cnt[ai];
  }
  for (const int &c : cnt) t.insert(c);
  int Q, a, b, c;
  string op;
  cin >> Q;
  while (Q--) {
    cin >> op >> ai;
    t.erase(t.find(cnt[ai]));
    cnt[ai] += (op == "+") ? 1 : -1;
    t.insert(cnt[ai]);
    string ans = "NO\n";
    a = *t.begin(); t.erase(t.begin());
    b = *t.begin(); t.erase(t.begin());
    c = *t.begin(); t.erase(t.begin());
    if (a >= 8 || (a >= 6 && b >= 2) || (a >= 4 && (b >= 4 || c >= 2)))
      ans = "YES\n";
    cout << ans ;
    t.insert(a); t.insert(b); t.insert(c);
  }
  return 0;
}

