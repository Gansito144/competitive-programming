#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  const int N = 1003;
  vector<vector<int>> grid(N, vector <int>(N, 0));
  int r, c, w, h, id, cnt = 0;
  while (scanf("#%d @ %d,%d: %dx%d\n",&id, &r, &c, &w, &h) != EOF) {
    for(int x=0; x<w; ++x)
      for(int y=0; y<h; ++y)
        ++grid[r+x][c+y];
  }
  for (const auto &row : grid)
    for (const int &cell : row)
      cnt += cell >= 2;
  cout << cnt << endl;
  return 0;
}

