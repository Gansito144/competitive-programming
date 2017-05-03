#include <stdio.h>
#include <iostream>

using namespace std;

const int kMaxN = 102;

int G[kMaxN][kMaxN];

int main() {
  int n, k, r, c, d;
  cin >> n >> k;
  
  r = 0;
  c = r + 1;
  d = 0;
  // Special case 0
  if(k > n*n) {
    cout << -1 << endl;
    return 0;
  }
  // Special case 1
  G[d][d] = (k) ? 1 : 0;
  --k; ++d;
  while(k > 0) {
    if(k > 1) { // place in next
      G[r][c] = 1;
      G[c][r] = 1;
      k -= 2;
      if( (c+1)==n ) {
        ++r;
        c = r+1;
        if(k) {
          G[d][d] = 1;
           --k;
           ++d;
        }
      } else {
        ++c;
      }
    } else {
      G[d][d] = 1;
      --k;
      ++d;
    }
  }
 
  // Print
  for(int i=0; i<n; ++i) {
    for(int j=0; j<n; ++j) {
      printf("%d%c",G[i][j]," \n"[j==n-1]);
    }
  }
  return 0;
}

