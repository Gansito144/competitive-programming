#include <iostream>

using namespace std;

const int kMax = 30;

int sa [kMax][kMax];

int main() {
  int R, C, v;
  string str;

  cin >> R >> C;
  // Read and process
  for(int r=1; r<=R; ++r) {
    cin >> str;
    for(int c=1; c<=C; ++c) {
      v = str[c-1]-'0';
      sa [r][c] = v + sa[r-1][c] +
       sa[r][c-1] -  sa[r-1][c-1];
    }
  }
  // brute force
  int ans = 0;
  for(int w=R; w>0; --w) {
    for(int h=C; h>0; --h) {
      for(int r=R; r>=w; --r) {
        for(int c=C; c>=h; --c) {
          int cnt = (sa[r][c] - sa[r-w][c]
            - sa[r][c-h] + sa[r-w][c-h]);
          if(cnt) continue;
          ans = max(ans, (w<<1)+(h<<1));
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}

