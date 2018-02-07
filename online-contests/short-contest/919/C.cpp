#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>

using namespace std;

const int K = 2003;

char g[K][K];
int ra[K][K], ca[K][K];

int main ()
{
  int n, m, k;
  int ans = 0;
  scanf("%d %d %d",&n,&m,&k);
  for (int r=1; r<=n; ++r)
  {
    scanf("%s",g[r]);
    //printf("%s\n",g[r]);
    for (int c=m; c>0; --c)
      g[r][c] = g[r][c-1];
    g[r][0] = 0;
    for (int c=1; c <=m; ++c)
    {
      if (g[r][c] == '*') continue;
      //printf("%d %d %c \n",r,c,g[r][c]);
      ra[r][c] = (g[r][c] == g[r][c-1]) ? ra[r][c-1] + 1 : 1;
      ca[r][c] = (g[r][c] == g[r-1][c]) ? ca[r-1][c] + 1 : 1;
      //printf("%d %d\n",ra[r][c],ca[r][c]);
      if (ra[r][c] >= k) ++ans;
      if (k > 1 && ca[r][c] >= k) ++ans;
    }
  }
  printf("%d\n",ans);
  return 0;
}

