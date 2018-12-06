#include <iostream>
#include <algorithm>
#include <climits>
#include <utility>
#include <set>
#include <map>
#include <vector>

#define X first
#define Y second

using namespace std;
using point = pair<int,int>;

int main() {
  int x, y, ans;
  char comma;
  // Read input
  vector <point> pts;
  while (cin >> x >> comma >> y) {
    pts.push_back({x,y});
  }

  vector <int> prv(pts.size(), -1);
 
  // Try with different pts
  for (int oo = 1000; oo <1010; ++oo) {
    vector <int> count(pts.size(), 0);
    vector <int> ord(pts.size());
    for (int i=0; i<pts.size(); ++i) ord[i] = i;
    for (x=-oo; x<=oo; ++x) {
      for (y=-oo; y<=oo; ++y) {
        int best = INT_MAX, id = -1, cnt = 0;
        for (int p=0; p<pts.size(); ++p) {
          int d = abs(pts[p].X - x) + abs(pts[p].Y - y);
          if (d <= best) {
            if (d < best) cnt = 0;
            ++cnt;
            best = d;
            id = p;
          }
        }
        if (cnt == 1)
          ++count[id];
      }
    }

    //sort(ord.begin(), ord.end(), [&](int a, int b) -> bool {
    //    return count[a] > count[b];
    //    });

    int diff = 0;
    for (int i=0; i<pts.size(); ++i) {
      if (prv[i] == -1) {
        prv[i] = count[i];
        continue;
      }
      if (count[i] > prv[i]) {
        continue;
      }
      diff = max(diff, count[i]);
    }
    ans = diff;
  }
  cout << ans << endl;
  return 0;
}

