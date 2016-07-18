/*
 * Author: Ulises Mendez Martinez
 * Mail: ulisesmdzmtz@gmail.com
 * Solution: Run two BFS's, then for 
 * each position use the maximum
*/

 #include <bits/stdc++.h>
 
#define N 102
#define M 2
 
#define mp make_pair
 
using namespace std;
 
typedef pair<int,int> ii;
 
 
int R, C;
 
int d[M][N][N], p[M];
bool g[N][N];
 
void readG() {
	int can;
	for(int i=0; i<R; ++i) {
		for(int j=0; j<C; ++j){
			scanf("%d",&can);
			g[i][j] = can;
		}
	}
}
 
bool bfs(int k, int r, int c) {
	queue< ii > Q;
	d[k][r][c] = 0;
	Q.push( mp(r,c) );
	while( !Q.empty() ) {
		r = Q.front().first;
		c = Q.front().second;
		Q.pop();
		// Children
		for(int i = -p[k]; i <= p[k]; ++i) {
			for(int j = -p[k]; j <= p[k]; ++j) {
				if( abs(i) + abs(j) > p[k] ) continue;
				int nr = r + i;
				int nc = c + j;
				if( nr >= 0 && nr < R && nc >= 0 && nc < C ) {
					if( !g[nr][nc] && (d[k][nr][nc] == -1)) {
						d[k][nr][nc] = d[k][r][c] + 1;
						Q.push( mp(nr,nc) );
					}
				}
			}
		}
	}
}
 
int main() {
	int t, ans;
	scanf("%d",&t);
	while(t--) {
		memset(d, -1, sizeof d);
		scanf("%d %d %d %d",&R,&C,&p[0],&p[1]);
		readG();
		bfs(0, 0,  0);
		bfs(1, 0, C-1);
		ans = -1;
		for(int i=0; i<R; ++i)
			for(int j=0; j<C; ++j)
				if(d[0][i][j] != -1 && d[1][i][j] != -1) {
					if(ans == -1) ans = max(d[1][i][j], d[0][i][j]);
					ans = min( ans, max(d[1][i][j], d[0][i][j]) );
				}
				
		printf("%d\n",ans);
	}
	return 0;
} 