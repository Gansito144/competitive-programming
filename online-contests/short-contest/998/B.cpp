#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
using i64 = long long int;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, ai, b;

  cin >> n >> b;
  vector <int> a(n);

  for (int &ai : a) cin >> ai;

  int o=0, e=0;
  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i=0; i<(n-1); ++i) {
    if (a[i] & 1) ++o;
    else ++e;
    if (o == e) {
      pq.push(abs(a[i] - a[i+1]));
    }
  }
  int ans = 0;
  while (!pq.empty()) {
    int c = pq.top(); pq.pop();
    if (c > b) break;
    b -= c;
    ++ans;
  }
  cout << ans << endl;
  return 0;
}


