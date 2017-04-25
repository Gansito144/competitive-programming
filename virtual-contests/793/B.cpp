#include <stdio.h>
#include <iostream>
#include <queue>
#include <utility>
#include <memory>

#define mp make_pair
#define F first
#define S second

using namespace std;

const int MN = 1003;
const int oo = 1 << 29;

typedef pair<int,int> ii;
typedef pair<int , ii> iii;
typedef pair<ii,ii> node;

char G[MN][MN];
int dis[MN][MN];

int mov[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

int main() {
  int R, C, u, v;
  
  scanf("%d %d\n",&R,&C);
  priority_queue < node, deque<node>, greater<node> > DQ;
  // Read input
  for(int i=0; i<R; ++i) {
    gets(G[i]);
    for(int j=0; j<C; ++j) {
      if(G[i][j] == 'S') {
        DQ.push(mp(mp(0,0),mp(i,j)));
        DQ.push(mp(mp(0,1),mp(i,j)));
        DQ.push(mp(mp(0,2),mp(i,j)));
        DQ.push(mp(mp(0,3),mp(i,j)));
        dis[i][j] = 0;
      } else {
        if(G[i][j] == 'T') {
          u = i;
          v = j;
        }
        dis[i][j] = oo;
      }
    }
  }
  while(!DQ.empty()) {
    int w = DQ.top().F.F;
    int t = DQ.top().F.S;
    int x = DQ.top().S.F;
    int y = DQ.top().S.S;
    DQ.pop();
    if( w != dis[x][y] ) continue; 
    //printf("x:%d y:%d d:%d t:%d\n",x,y,t,dis[x][y]);
    for(int i=0; i<4; ++i) {
      int nx = x + mov[i][0];
      int ny = y + mov[i][1];
      int inc = (i==t) ? 0 : 1;
      if(nx>=0 && nx<R && ny>=0 && ny<C && 
         G[nx][ny] != '*' && (dis[x][y]+inc < dis[nx][ny])) {
         dis[nx][ny] = dis[x][y] + inc;
         DQ.push(mp(mp(dis[nx][ny],i),mp(nx,ny)));
       }
    }
  }
  // printf("d:%d\n",dis[u][v]);
  printf("%s\n",(dis[u][v]>2)?"NO":"YES");
  return 0;
}

