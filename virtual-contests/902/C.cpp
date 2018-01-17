#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int p[2][212345];
int a[112345];

int main ()
{
  int n;
  cin >> n;
  bool can = false;
  for (int i=0; i<=n; ++i)
  {
    scanf("%d",&a[i]);
    if ( (i) && (a[i]>1) && (a[i-1]>1))
      can = true;
  }
  if (can)
  {
    puts("ambiguous");
    int cnt = 0;
    for (int i=0; i<=n; ++i)
    {
      for (int j=0; j<a[i]; ++j)
      {
        printf("%d ",cnt);
      }
      cnt += a[i];
    }
    puts("");
    cnt = 0;
    for (int i=0; i<=n; ++i)
    {
      bool pr = false;
      if (i && (a[i]>1) && (a[i-1]>1))
      {
        printf("%d ",cnt-1);
        pr = true;
      }
      for (int j=pr; j<a[i]; ++j)
      {
        printf("%d ",cnt);
      }
      cnt += a[i];
    }
    puts("");
  }
  else
    puts("perfect");
  return 0;
}

