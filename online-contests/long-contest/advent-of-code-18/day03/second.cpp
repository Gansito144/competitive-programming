#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  const int N = 1003;
  vector<vector<int>> grid(N, vector <int>(N, 0));
  vector<vector<int>> cmds;
  int r, c, w, h, id, cnt = 0;
  while (scanf("#%d @ %d,%d: %dx%d\n",&id, &r, &c, &w, &h) != EOF) {
    for(int x=0; x<w; ++x)
      for(int y=0; y<h; ++y)
        ++grid[r+x][c+y];
    cmds.push_back({id, r, c, w, h});
  }
  for (const auto &v : cmds) {
    id = v[0]; r = v[1]; c = v[2]; 
    w = v[3]; h = v[4];
    bool can = true;
    for(int x=0; x<w; ++x)
      for(int y=0; y<h; ++y)
        if (grid[r+x][c+y] > 1)
          can = false;
    if (can) {
      cnt = id;
      break;
    }
  }
  cout << cnt << endl;
  return 0;
}

