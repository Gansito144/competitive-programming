#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using event = pair<ii, ii>; // x, type, y1, y2 

const int MAXN = 1000006;
vector <int> ft(MAXN, 0);

int read(int pos) {
  int ret = 0;
  while (pos > 0) {
    ret += ft[pos];
    pos -= (pos) & (-pos);
  }
  return ret;
}

void update(int pos, int delta) {
  while (pos < MAXN) {
    ft[pos] += delta;
    pos += (pos) & (-pos);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, xi, xf, yi, yf, type, x;
  cin >> n;
  vector <event> events;
  events.reserve( n<<1 );
  while (n--) {
    cin >> xi >> yi >> xf >> yf;
    ++yi; ++yf; // BIT doesn't support 0. 
    if (xi == xf) { // vertical
      if (yi > yf) swap(yi, yf);
      events.push_back({{xi,1},{yi, yf}});
    } else { // horizontal
      if (xi > xf) swap(xi, xf);
      events.push_back({{xi,0},{yi, yf}});
      events.push_back({{xf,2},{yi, yf}});
    }
  }
  i64 ans = 0;
  sort(events.begin(), events.end());
  for (const auto &event : events) {
    tie(x, type) = event.first;
    tie(yi, yf) = event.second;
    switch (type) {
      case 0: update(yi, +1); break;
      case 1: ans += (read(yf) - read(yi-1)) ; break;
      case 2: update(yi, -1); break;
    }
  }
  cout << ans << endl;
  return 0;
}

