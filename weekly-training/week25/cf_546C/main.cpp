#include <iostream>
#include <set>
#include <algorithm>
#include <stdio.h>
#include <utility>
#include <memory.h>

using namespace std;
using ss = pair<string, string>;
using cc = set <ss>;

int main ()
{
  int N, f, s, d;
  string df, ds;
  cin >> N;
  cin >> f;
  while(f--)
  {
    cin >> d;
    df += '0'+d-1;
  }
  cin >> s;
  while(s--)
  {
    cin >> d;
    ds += '0'+d-1;
  }
  int ans = -1;
  int cnt = 0;
  cc seen;
  while(true)
  {
    // Already seen
    if(seen.find(make_pair(df,ds)) != seen.end())
      break;
    // Check if solution
    if(df == "" || ds == "")
    {
      ans = (df == "") ? 2 : 1;
      break;
    }
    seen.insert(make_pair(df, ds));
    ++cnt;
    char cf = df[0];
    char cs = ds[0];
    df.erase(df.begin());
    ds.erase(ds.begin());
    if(cs > cf)
    {
      ds += cf;
      ds += cs;
    }
    else
    {
      df += cs;
      df += cf;
    }
  }
  if(ans != -1)
    cout << cnt << " " << ans << endl;
  else
    cout << ans << endl;
  return 0;
}

