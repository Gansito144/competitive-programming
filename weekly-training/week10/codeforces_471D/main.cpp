#include "bits/stdc++.h"

#if ( WIN32 || __WIN32_ )
   #define lld I64d
#endif

using namespace std;

typedef long long int i64;

#define N 1000006

int s[N], z[N];

int solve( int n , int m )
{
  int sz = n+m;    
  int L=0, R=0, ret=0, k;

  for(int i=1; i<sz; ++i) {
    if(R<i) {
      R = L = i;
      while(R<sz && s[R-L]==s[R]) {
        ++R;
      }
      z[i] = R-L;
      R--;
    } else {
      k = i - L;
      if(z[k]<(R-i+1)) {
        z[i] = z[k];
      } else {
        L = i;
        while(R<sz && s[R-L]==s[R]) {
          R++;
        }
        z[i] = R-L;
        --R;
      }
    }
    if(i<m) continue;
    if(z[i]>=m) ++ret;
  }
  return ret;
}

int main()
{
  int n , m , now, before;
    
  scanf("%d %d",&n,&m);
  if(m==1) {
    printf("%d\n",n);
  } else {
    for(int i=0; i<n; ++i) {
      scanf("%d",&z[i]);
    }
    for(int i=0; i<m; ++i) {
      scanf("%d",&now);
      if(i>0) {
        s[i-1] = now-before;
      }
      before = now;
    }
    for(int i=1; i<n; ++i) {
      s[m+i-2] = z[i]-z[i-1];
    }
    printf("%d\n",solve(n-1, m-1));
  }
  return 0;
}
