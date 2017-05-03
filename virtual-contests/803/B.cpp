#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

const int kMaxN = 212345;

bool isZero[kMaxN];
int dis[kMaxN];

int main() {
  int n, lz = -kMaxN, x;
  
  scanf("%d",&n);
  for(int i=1; i<=n; ++i) {
    scanf("%d",&x);
    isZero[i] = !x;
    if( isZero[i] ) lz = i;
    dis[i] = i-lz;
  }
  lz = kMaxN << 1;
  for(int i=n; i>0; --i) {
    if(isZero[i]) lz = i;
    dis[i] = min(dis[i], lz-i);
  }
  for(int i=1; i<=n; ++i) {
    printf("%d%c",dis[i]," \n"[i==n]);
  }
  return 0;
}

