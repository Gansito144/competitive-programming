#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

char G[303][303];

using namespace std;

int main ()
{
  int R, C, k;
  sscanf(gets(G[0]), "%d %d %d", &R, &C, &k);
  
  for (int i=0; i<R; ++i) gets(G[i]);
  int idx=0, x=-1, y=-1, rd = 1, mn=min(R,C); 
  for (; rd<mn; ++rd)
  {
    int mv[][2] = {{-rd,0},{rd,0},{0,-rd},{0,rd}};
    for (int i=rd; ((i+rd)<R) && (idx<k); ++i)
    {
      for (int j=rd; ((j+rd)<C) && (idx<k); ++j)
      {
        if(G[i][j] != '*') continue;
        if(G[i-rd][j] != '*') continue;
        if(G[i+rd][j] != '*') continue;
        if(G[i][j+rd] != '*') continue;
        if(G[i][j-rd] != '*') continue;
        ++idx;
        x=i; y=j;
      }
    }  
    if(k == idx) break;
  }
  if(idx == k)
  {
    printf("%d %d\n",x+1,y+1);
    printf("%d %d\n",x-rd+1,y+1);
    printf("%d %d\n",x+rd+1,y+1);
    printf("%d %d\n",x+1,y-rd+1);
    printf("%d %d\n",x+1,y+rd+1);
  }
  else printf("-1\n");
  return 0;
}

