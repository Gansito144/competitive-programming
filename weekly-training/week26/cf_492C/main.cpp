#include <iostream>
#include <stdio.h>
#include <utility>
#include <algorithm>

#define F first
#define S second

using namespace std;
using i64 = long long int;
using ii  = pair<i64, i64>;

const int kMax = 100005;
ii Note[kMax];
int n;
i64 r, avg, already;

i64 solve(i64 ess)
{
  i64 cnt = already;
  for(int i=0; i<n; ++i)
  {
    if(ess <= 0) break;
    if(Note[i].F > ess) break; 

    i64 need = (r - Note[i].S);
    i64 can = min(need, ess / Note[i].F);
    //cout << i << " | " << need << " | " << can << endl;
    cnt += can;
    ess -= (can * Note[i].F);
  }
  //cout << ess << " - " << cnt << " -- " << avg << endl;
  return (cnt >= avg);
}

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> r >> avg; 
  avg *= (i64) n;
  for(int i=0; i<n; ++i)
  {
    cin >> Note[i].S >> Note[i].F;
    already += Note[i].S;
  }
  sort(Note, Note + n);
  i64 ans = (1LL<<60) - 1LL;
  for(int k=59; k>=0; --k)
  {
    ans ^= solve(ans ^ (1LL<< k)) << k;
  }
  cout << ans << endl;
  return 0;
}

