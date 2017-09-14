#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
using i64 = long long int;


int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int queries;
  
  cin >> queries;
  while (queries--) 
  {
    i64 L, R, ans;
    cin >> L >> R;
    ans = L;
    for(int k=0; k<63; ++k) 
    {
      if( (ans|(1LL<<k)) > R) continue;
      ans |= (1LL<<k);
    }
    cout << ans << endl;
  }
  return 0;
}

