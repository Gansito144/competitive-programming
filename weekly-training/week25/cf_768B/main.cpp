#include <iostream>
#include <utility>
#include <algorithm>
#include <map>

#define Nums first
#define Ones second

using namespace std;
using i64 = long long int;
using ii  = pair<i64, i64>;

map <i64, ii> dp;

ii solve(i64 n, i64 need)
{
  ii ret = make_pair(0LL, 0LL);
  // Memoization
  if(dp.count(n) && dp[n].Nums <= need)
    return dp[n];

  if(need <= 0) return ret;

  if(n <= 1LL)
  {
      ret =  make_pair(1LL, n);
      dp[n] = ret;
      return ret;
  }
  else 
  {
    ret = solve(n>>1, need);
    if(ret.Nums < need)
    {
      ret.Ones += (n&1LL);
      ret.Nums +=    1LL;
    }
    if(ret.Nums < need)
    {
      ii sol = solve(n>>1, need - ret.Nums);
      ret = make_pair(ret.Nums+sol.Nums, ret.Ones+sol.Ones);
    }
  }
  if(!dp.count(n)) dp[n] = ret;
  return ret;
}

int main ()
{
  i64 n;
  i64 l, r;
  cin >> n >> l >> r;
  ii R = solve(n, r);
  ii L = solve(n, l-1LL);
  cout << (R.Ones - L.Ones) << endl;
  return 0;
}

