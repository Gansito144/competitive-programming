#include <iostream>

using namespace std;

const int kMax = 30;

int sa [kMax][kMax];

int main() {
  int N, M, v;
  string str;

  cin >> N >> M;
  // Read and process
  for(int r=1; r<=N; ++r) {
    cin >> str;
    for(int c=1; c<=M; ++c) {
      v = str[c-1]-'0';
      sa [r][c] = v + sa[r][c-1];
    }
  }
  // brute force
  int ans = 0;
  for(int L=0; L<M; ++L) {
    for(int R=M; R>L; --R) {
      int H = 0;
      for(int r=1; r<=N; ++r) {
        H = (sa[r][R]-sa[r][L]) ? 0 : H+1;
        if(H) ans = max(ans, (H*2)+((R-L)*2));
      }
    }
  }
  cout << ans << endl;
  return 0;
}

