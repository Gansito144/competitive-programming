/*
 * Author: Ulises Mendez Martinez
 * Mail: ulisesmdzmtz@gmail.com
 * Description: Kruskal MST
*/

#include <cstdio>
#include <utility>
#include <algorithm>
#include <queue> 
#define F first
#define S second 

using namespace std;

typedef pair<int,int> ii;
typedef pair<int, ii> iii;

int p[1234];

int find(int x){
   if(x != p[x]) {
      p[x] = find(p[x]);
   }
   return p[x];
}

int main() {
   int n, m, w, u, v, ans, cc;

   while(scanf("%d %d",&n,&m)==2) {
      if(!n && !m) break;
      // initilize dsu
      cc = n;
      for(int i=0; i<n; ++i) p[i]=i;
      // read edges
      deque <iii> edges(m);
      for(int i=0; i<m; ++i) {
         scanf("%d %d %d",&edges[i].S.F,&edges[i].S.S,&edges[i].F);
      }
      sort(edges.begin(), edges.end(), greater<iii>() );
      ans = 200000000;
      for(int i=0; i<m; ++i) {
         u = edges[i].S.F;
         v = edges[i].S.S;
         w = edges[i].F;
         if(find(u)!=find(v)) {
            p[find(u)] = find(v);
            ans = min(ans, w);
            cc--;
         }
      }
      if( cc != 1) puts("IMPOSSIBLE");
      else printf("%d\n",ans);
   }
   return 0;
}