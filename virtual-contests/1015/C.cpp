#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
using i64 = long long int;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  i64 cap, s = 0LL, a, b;

  cin >> n >> cap;
  priority_queue <i64> pq;

  while (n--) {
    cin >> a >> b;
    pq.push(a - b);
    s += a;
  }

  n = 0;
  while (s > cap && !pq.empty()) {
    s -= pq.top();
    pq.pop();
    ++n;
  }

  if (s > cap) n = -1;
  cout << n << endl;

  return 0;
}

