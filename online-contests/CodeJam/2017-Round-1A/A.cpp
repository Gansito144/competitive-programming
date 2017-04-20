#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
  int R,C, tt, r, c;
  char G[30][30];

  scanf("%d",&tt);
  for(int tc=1; tc<=tt; ++tc) {
    printf("Case #%d:\n",tc);
    scanf("%d %d",&R,&C);
    for(int i=0; i<R; ++i) {
      scanf("%s",G[i]);
    }
    for(r=0; r<R; ++r) {
      for(c=0; c<C; ++c) {
        if(G[r][c] != '?') {
          char x = G[r][c];
          while(c < (C-1) && G[r][c+1] == '?') c++;
          for(int i=0; i<=r; ++i) {
            for(int j=0; j<=c; j++) {
              if(G[i][j] == '?') G[i][j] = x;
            }
          }
        }
      }
    }
    for(c=0; c<C; ++c) {
      for(r=R-1; r >= 0 && G[r][c] == '?'; --r);
      for(; r<R; ++r) G[r+1][c] = G[r][c];
    }
    for(int i=0; i<R; ++i) {
      printf("%s\n",G[i]);
    }
  }
  return 0;
}
