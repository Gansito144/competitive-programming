#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
using i64 = long long int;

inline i64 sz(const string &s)
{
  return s.size();
} 

int main ()
{
  const string f0  = "What are you doing at the end of the world? Are you busy? Will you save us?";
  const string fi1 = "What are you doing while sending \"";
  const string fi2 = "\"? Are you busy? Will you send \"";
  const string fi3 = "\"?";

  i64 MX = 1e6;
  int q;
  cin >> q;
  while (q--)
  {
    i64 n, p;
    cin >> n >> p;
    vector < i64 > sa(n + 1LL);
    sa [0] = sz(f0);
    for (int i=1; i<=n; ++i)
    {
      sa[i] = sz(fi1) + sa[i-1] + sz(fi2) + sa[i-1] + sz(fi3);
      sa[i] = min(p, sa[i]);
    }
    char ans = 0;
    while (true) 
    {
      if (p > sa[n]) 
      {
        ans = '.';
        break;
      }
      if (n == 0)
      {
        ans = f0[p-1];
        break;
      }
      if(p <= sz(fi1))
      {
        ans = fi1[p-1];
        break;
      }
      p -= sz(fi1);
      if (p <= sa[n-1])
      {
        --n;
        continue;
      }
      p -= sa[n-1];
      if (p <= sz(fi2))
      {
        ans = fi2[p-1];
        break;
      }
      p -= sz(fi2);
      if(p <= sa[n-1])
      {
        --n;
        continue;
      }
      p -= sa[n-1];
      ans = fi3[p-1];
      break;
    }
    cout << ans;
  }
  cout << endl;
  return 0;
}


