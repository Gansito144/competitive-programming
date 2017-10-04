#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main ()
{
  int n, d, h;

  scanf("%d %d %d",&n,&d,&h);

  if( d > (h*2) || (d==h && h==1 && n>2) ) puts("-1");
  else
  {
    bool ans = true;
    int pr = 1;
    int lp = 1;
    int dd = 0;
    for(int no = 2; no<=n; ++no)
    {
      if(d == 0) printf("%d %d\n",lp, no);
      else {
        if(dd == h) pr = 1;
        ++dd;
        d = max(0, d-1);
        printf("%d %d\n",pr, no);
        lp = pr;
        pr = no;
      }
    }
  }
  return 0;
}


