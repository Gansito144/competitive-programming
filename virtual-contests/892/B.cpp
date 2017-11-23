#include <iostream>
#include <algorithm>

using namespace std;

int dz [1234567];

int main ()
{
  int n, l, cnt = 0;
  
  scanf("%d",&n);
  for  (int i=1; i<=n; ++i)
  {
    scanf("%d",&l);
    cnt = max(0, i-l);
    --dz[cnt];
    ++dz[ i ];
  }
  cnt = 0;
  for (int i=1; i<=n; ++i)
  {
    dz[ i ] += dz[ i-1 ];
    cnt += (dz[i] >= 0);
  }
  printf("%d\n",cnt);
  return 0;
}

