#include <iostream>
#include <algorithm>
#include <cstdio>
#include <utility>
#include <map>

using namespace std;

int main ()
{
  int n, x, mn = 123456789, mx = -123456789, ans = 0;
  map <int,int> cnt;

  scanf("%d",&n);
  ans = n;
  do
  {
    scanf("%d",&x);
    mn = min(mn, x);
    mx = max(mx, x);
    ++cnt[x];
  } while(--n);
  
  if ((mx-mn) > 1)
  {
    int mid = (mn+mx) >> 1;
    int chp = min(cnt[mx], cnt[mn]);
    if (chp >= (cnt[mid]>>1))
    {
      cnt[mx] -= chp;
      cnt[mn] -= chp;
      chp <<= 1;
      ans -= chp;
      cnt[(mn + mx) >> 1] += chp;
    }
    else 
    {
      chp = cnt[mid] >> 1;
      cnt[mid] &= 1; 
      cnt[mn] += chp;
      cnt[mx] += chp;
      ans -= (chp + chp);
    }
  }

  printf("%d\n",ans);
  for (auto y : cnt)
    while(y.second--)
      printf("%d ",y.first);
  puts("");
  return 0;
}

