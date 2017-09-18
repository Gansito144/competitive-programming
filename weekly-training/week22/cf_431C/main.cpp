#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;
using i64 = long long int;

class kTree
{
  private:
    static const int kMaxN = 111;
    static const int kMod = 1000000007LL;
    i64 dp[kMaxN][kMaxN][2];
    int n, k, d;
  public:
    kTree (int n, int k, int d)
     : n(n), k(k), d(d)
    {
      memset(dp, -1, sizeof dp);
    }
    i64 solve(int lev, int sum, bool sol)
    {
      //cout <<lev<<" "<<sum<<" "<<sol<<endl;
      if(dp[lev][sum][sol] >= 0) 
        return dp[lev][sum][sol];

      i64 &ret = dp[lev][sum][sol];
      if(sum==n) return ret = (int)(sol);
      ret = 0LL;
      for(int p=1; p<=k; ++p)
      {
        if(sum+p>n) break;
        ret += solve(lev+1, sum+p, sol||(p>=d));
        ret %= kMod; 
      }
      return ret;
    }
    i64 countPaths()
    {
      return solve(0, 0, false);
    }

};

int main()
{
  int n, k, d;
  cin >> n >> k >> d;
  kTree kt(n, k, d);
  cout << kt.countPaths() << endl;
  return 0;
}

