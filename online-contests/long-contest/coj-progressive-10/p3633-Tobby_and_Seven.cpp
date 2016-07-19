/*
 * Author: Ulises Mendez Martinez
 * Mail: ulisesmdzmtz@gmail.com
 * Description: Bitmask + Complete search
*/

#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long int i64;

i64 n, nn, ans, sol;
int k, p[22], ones;

void backtrack(int msk, int m, int o) {
   // If we had fill all positions
   if(m == k) {
      sol = nn;
      for(int b=0; b<k; ++b) {
         if( (msk>>b)&1 )
            sol |= 1LL << p[b];
      }
      if(sol % 7LL == 0LL){
         ans = max(sol, ans);
      }
   }
   else {
      // Place a one if possible
      if(ones > o) {
         backtrack(msk|(1<<m),m+1,o+1);
      }
      // place a zero if possible
      if((k-m)>(ones-o)){
         backtrack(msk, m+1, o);
      }
   }
}

int main() {
   while(scanf("%lld",&n)!=EOF) {
      scanf("%d",&k);
      ones = 0;
      nn = n;
      for(int i=0; i<k; ++i) {
         scanf("%d",&p[i]);
         ones += (n & (1LL<<p[i])) >> p[i];
         nn &= ~(1LL<<p[i]); 
      }
      ans = 0LL;
      backtrack(0,0,0);
      printf("%lld\n",ans);
   }
   return 0;
}