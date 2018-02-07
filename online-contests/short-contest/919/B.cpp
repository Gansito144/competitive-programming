#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int K = 10001;
vector <int> ans (K);
int sz;

void check (int p)
{
  int pp = p;
  int cnt = 0;
  while (p)
  {
    cnt += p%10;
    p /= 10;
  }
  if(cnt == 10)
  {
    ans[sz] = pp;
    ++sz;
  }
}

int main ()
{
  for (int p = 19; sz < (K-1); ++p)
    check(p);
  int k;
  cin >> k;
  cout << ans[k-1] << endl;
  return 0;
}

