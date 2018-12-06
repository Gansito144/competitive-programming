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
  const int oo = 1400;
  int x, y, cnt = 0;
  char comma;
  vector <point> pts;
  while (cin >> x >> comma >> y) {
    pts.push_back({x,y});
  }
  vector <int> count(pts.size(), 0);
  vector <int> ord(pts.size());
  for (x=-oo; x<=oo; ++x) {
    for (y=-oo; y<=oo; ++y) {
      int d = 0;
      for (int p=0; p<pts.size(); ++p) {
        d += abs(pts[p].X - x) + abs(pts[p].Y - y);
      }
      if (d < 10000)
        ++cnt;
    }
  }

  cout << cnt << endl;

  return 0;
}

