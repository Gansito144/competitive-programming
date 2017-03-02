#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <utility>

#define F first
#define S second
#define mp make_pair

using namespace std;

typedef pair <int,int> ii;
typedef pair <int,ii> iii;

int dis[102][102], m[102][102];
int mv[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

int main() {
  int R,C, ans;
  priority_queue<iii, deque<iii>, greater<iii> > pq;

  scanf("%d %d",&R,&C);

  for(int i=0; i<R; ++i) {
    for(int j=0; j<C; ++j) {
      scanf("%d",&m[i][j]);
    }
  }
  memset(dis,-1,sizeof dis);

  for(int i=0; i<R; ++i) {
    pq.push(mp(m[i][0], mp(i,0)));
    dis[i][0] = m[i][0];
  }

  while(!pq.empty()) {
    iii now = pq.top();
    pq.pop();
    int d = now.F;
    int r = now.S.F;
    int c = now.S.S;
    if(c == C-1) {
      ans = d;
      break;
    }
    if(d != dis[r][c]) continue;
    for(int i=0; i<4; ++i) {
      int nr = r + mv[i][0];
      int nc = c + mv[i][1];
      if(nr>=0 && nr<R && nc>=0 && nc<C) {
        if(dis[nr][nc]==-1 || d+m[nr][nc]<dis[nr][nc]){
          dis[nr][nc] = d+m[nr][nc];
          pq.push(mp(dis[nr][nc],mp(nr,nc)));
        }
      }
    }
  }
  printf("%d\n",ans);
  return 0;
}

