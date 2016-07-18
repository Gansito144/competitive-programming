/*
 * Author: Ulises Mendez Martinez
 * Mail: ulisesmdzmtz@gmail.com
 * Description: BFS in 3D
*/

#include <cstdio>
#include <cstring>
#include <utility>
#include <queue> 
#define N 102
#define F first
#define S second 
#define mp make_pair

using namespace std;

typedef pair<int,int> ii;
typedef pair<int, ii> iii;

char g[N][N][N], dummy[N];
int dis[N][N][N];

int main() {
	int mv[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
	int R, C, H, r, c, h, x, y, w;

	while (scanf("%d %d %d\n", &R,&C,&H) != EOF){
		if(R==0 && C==0 && H==0) break;
		// Read
		for(int k=0; k<H; ++k) {
			for(int i=0; i<R; ++i) {
				gets(g[k][i]);
				for(int j=0; j<C; ++j) {
					if(g[k][i][j]=='S') {
						r = i;
						c = j;
						h = k;
					} else if (g[k][i][j]=='E') {
						x = i;
						y = j;
						w = k;
					}
				}
			}
			gets(dummy);
		}
		// Run BFS
		queue< iii > Q;
		memset(dis, -1, sizeof dis);
		Q.push(mp(h,mp(r,c)));
		dis[h][r][c] = 0;
		while(!Q.empty()) {
			h = Q.front().F;
			r = Q.front().S.F;
			c = Q.front().S.S;
			Q.pop();
			// lets move in the same floor
			for(int k = 0; k<4; ++k) {
				int nr = r + mv[k][0];
				int nc = c + mv[k][1];
				// If valid
				if(nr>=0 && nr<R && nc>=0 && nc<C) {
					if(g[h][nr][nc]!='#' && dis[h][nr][nc]==-1) {
						dis[h][nr][nc] = dis[h][r][c]+1;
						Q.push(mp(h,mp(nr,nc)));
					}
				}
			}
			// In elevators
			if(g[h][r][c]=='-'){
				// Move up
				if((h+1)<H && g[h+1][r][c]=='-' && dis[h+1][r][c]==-1) {
					dis[h+1][r][c] = dis[h][r][c]+1;
					Q.push(mp(h+1,mp(r,c)));
				}
				// Move down
				if(h>0 && g[h-1][r][c]=='-' && dis[h-1][r][c]==-1) {
					dis[h-1][r][c] = dis[h][r][c]+1;
					Q.push(mp(h-1,mp(r,c)));
				}
			}
		}
		printf("%d\n",dis[w][x][y]);
	}
}