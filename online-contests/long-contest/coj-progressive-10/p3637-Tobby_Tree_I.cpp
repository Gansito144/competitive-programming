/*
 * Author: Ulises Mendez Martinez
 * Mail: ulisesmdzmtz@gmail.com
 * Description: GCD + BFS
*/

#include <cstdio>
#include <utility>
#include <algorithm>
#include <queue>
#include <cstring> 

using namespace std;

typedef pair<int,int> ii;
typedef pair<int, ii> iii;

int w[502], dis[502];

int main() {
   int n, u, v, q, op;
   while(scanf("%d",&n)!=EOF) {
      for(int i=0; i<n; ++i) {
         scanf("%d",&w[i]);
      }
      deque< deque<int> > G(n);
      for(int i=1; i<n; ++i) {
         scanf("%d %d",&u,&v);
         G[u].push_back(v);
         G[v].push_back(u);
      }
      scanf("%d",&q);
      while(q--) {
         scanf("%d %d",&op,&u);
         if(1==op){
            scanf("%d",&v);
            queue<int> Q;
            memset(dis, -1, sizeof dis);
            dis[u] = w[u];
            Q.push(u);
            while(!Q.empty()) {
               u = Q.front(); Q.pop();
               if(u == v) break;
               for(int i=0; i<G[u].size(); ++i){
                  int nu = G[u][i];
                  if(-1 == dis[nu]){
                     dis[nu] = __gcd(dis[u],w[nu]);
                     //printf("u(%d) nu(%d), gcd(%d, %d):%d\n",u,nu,dis[u],w[nu],dis[nu]);
                     Q.push(nu);
                  }
               }
            }
            printf("%d\n",dis[v]);
         }else{
            scanf("%d",&w[u]);
         }
      }
   }
   return 0;
}