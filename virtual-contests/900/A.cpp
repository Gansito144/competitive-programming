#include <iostream>
#include <cstdio>

using namespace std;

int main ()
{
  int n, x, y, neg=0, pos=0;
  scanf("%d",&n);
  for (int i=0; i<n; ++i)
  {
    scanf("%d %d",&x,&y);
    if ( x < 0) ++neg;
    else ++pos;
  }
  string ans = "No";
  if (neg <= 1 || pos <= 1) ans = "Yes";
  printf("%s\n",ans.c_str());
  return 0;
}


