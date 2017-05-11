#include <stdio.h>
#include <memory.h>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int i64;

const int kMaxN = 2003;

i64 sum[kMaxN][kMaxN];

int main() {
  int R, C, Q, x, y, r, n;
  
  scanf("%d %d",&R,&C);
  // Read first half
  for(int i=1; i<=R; ++i) {
    x=i; y=R-i+1;
    for(int j=1; j<=C; ++j) {
      scanf("%lld",&sum[x][y]);
      ++x; ++y;
    }
  }
  
  // Calculate prefix sum
  int nR = R<<1, nC = C<<1;
  int nN = max(nR, nC);
  for(int i=1; i<=nN; ++i) {
    for(int j=1; j<=nN; ++j) {
      sum[i][j] += sum[i-1][ j ];
      sum[i][j] += sum[ i ][j-1];
      sum[i][j] -= sum[i-1][j-1];
      // printf("%03lld ",sum[i][j]);
    }
    // printf("\n");
  }

  scanf("%d",&Q);
  while(Q--) {
    scanf("%d %d %d",&x,&y,&r);
    int rx = x+y+1, ry = R-x+y;
    int ux = rx+r, uy = ry+r;
    int lx = rx-r, ly = ry-r;
    lx = max(lx, 1); ux = min(ux, nN);
    ly = max(ly, 1); uy = min(uy, nN);
    i64 ans = sum[ux][uy] + sum[lx-1][ly-1];
    ans -= (sum[ux][ly-1] + sum[lx-1][uy]);
    printf("%lld\n",ans);
  }

  return 0;
}
