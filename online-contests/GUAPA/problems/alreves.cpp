#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

int is_pal(int &n)
{
  char tmp[10];
  sprintf(tmp,"%d",n);
  string A = tmp, B = tmp;
  reverse(A.begin(), A.end());
  return A ==  B;
}

void sieve(vector<int> &sum)
{
  for (int n=1; n<sum.size(); ++n)
    sum[n] = sum[n-1] + is_pal(n);
}

int main ()
{
  const int MX = 1000002;
  vector <int> sum(MX, 0);
  sieve(sum);
  int n, a, b;
  scanf("%d",&n);
  while (n--)
  {
    scanf("%d %d",&a,&b);
    printf("%d\n",sum[b]-sum[a-1]);
  }
  return 0;
}

