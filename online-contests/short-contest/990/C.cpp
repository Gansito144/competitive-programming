#include <iostream>
#include <algorithm>
#include <utility>
#include <map>
#include <string>

#define F first
#define S second

using namespace std;
using i64 = long long int;
using res = pair <bool, int>; 

inline res func(const string &s)
{
  bool valid = true;
  int tmp = 0;
  for (const char &c : s)
  {
    tmp += (c == '(' ? 1 : -1);
    if (tmp < 0)
      valid = false;
  }
  return {valid, tmp};
}

int main ()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, tmp, sz;
  map <int, i64> bcnt, ecnt;
  string str, rev;
  bool valid;

  cin >> n;
  while (n--)
  {
    cin >> str;
    tie (valid, tmp) = func(str);
    if (valid) ++bcnt[tmp];
    rev = "";
    sz = str.size();
    for (int i=1; i<=sz; ++i) rev += (str[sz-i]=='(')?')':'('; 
    tie (valid, tmp) = func(rev);
    if (valid) ++ecnt[tmp];
  }

  i64 ans = 0LL;
  for (const auto it : bcnt)
      ans += (it.S * ecnt[it.F]);
  cout << ans << endl;
  return 0;
}


