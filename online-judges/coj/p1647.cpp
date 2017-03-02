#include <stdio.h>
#include <iostream>
#include <utility>
#include <queue>

#define mp make_pair
#define F first
#define S second

using namespace std;
typedef pair<int,int> ii;

int G[1003][1003];
int mov[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
queue <ii> Q;
char m[1003][1003];

int main() {
  int R, C;

  // Read maze
  scanf("%d %d",&R,&C);
  for(int i=0; i<R; ++i) {
    scanf("%s",m[i]);
    for(int j=0; j<C; ++j) {
      G[i][j] = -1;
      if(m[i][j]=='F') {
        Q.push(mp(i,j));
        G[i][j] = 0;
      }
    }
  }

  // BFS on fire
  while(!Q.empty()) {
    ii now = Q.front();
    Q.pop();
    int x = now.F;
    int y = now.S;
    for(int k=0; k<4; ++k) {
      int nr = x + mov[k][0];
      int nc = y + mov[k][1];
      if(nr>=0 && nr<R && nc>=0 && nc<C) {
        if(m[nr][nc]=='.' && G[nr][nc]==-1) {
          G[nr][nc] = G[x][y]+1;
          Q.push(mp(nr,nc));
        }
      }
    }
  }

  // Search for J
  for(int i=0; i<R; ++i) {
    for(int j=0; j<C; ++j) {
      if(m[i][j] == 'J') {
        Q.push(mp(i,j));
        G[i][j] = 0;
        break;
      }
    }
  }

  int suc = 0;
  // BFS on J
  while(!Q.empty() && !suc) {
    ii now = Q.front();
    Q.pop();
    int x = now.F;
    int y = now.S;
    for(int k=0; k<4 && !suc; ++k) {
      int nr = x + mov[k][0];
      int nc = y + mov[k][1];
      if(nr<0 || nr>=R || nc<0 || nc>=C) {
        suc = G[x][y] + 1;
        break;
      }
      if(m[nr][nc]=='.' && (G[nr][nc]==-1 ||
            G[x][y]+1<G[nr][nc]) ) {
          G[nr][nc] = G[x][y]+1;
          m[x][y] = '#';
          Q.push(mp(nr,nc));
      }
    }
  }
  if(suc) printf("%d\n",suc);
  else printf("IMPOSSIBLE\n");
  return 0;
} 

