#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int p[1123], t[1123];

int main ()
{
  int n, c;

  scanf("%d %d",&n,&c);
  for(int i=0; i<n; ++i)
    scanf("%d",&p[i]);
  for(int i=0; i<n; ++i)
    scanf("%d",&t[i]);
  int pL=0, pR = 0, x = 0;
  
  // Limak
  for(int i=0; i<n; ++i)
  {
    x += t[i];
    pL += max(0, p[i]-c*x);
  }
  // Radewoosh
  x = 0;
  for(int i=n-1; i>=0; --i)
  {
    x += t[i];
    pR += max(0, p[i]-c*x);
  }
  if(pL > pR) puts("Limak");
  else if(pR > pL) puts("Radewoosh");
  else puts("Tie");
  return 0;
}

