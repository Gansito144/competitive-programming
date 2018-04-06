#include <iostream>
#include <map>
#include <string>

using namespace std;

int main ()
{
  int n, k, cnt = 0;
  string s;
  map <int, int> L;
  cin >> n >> k;
  while (n--)
  {
    cin >> s;
    ++L[s.size()];
  }
  cin >> s;
  for (const auto &li : L)
  {
    if (li.first == s.size())
    {
      int mn = (cnt / k) * 5 + cnt + 1;
      cnt += li.second;
      int mx = ((cnt-1) / k) * 5 + cnt;
      cout << mn << " " << mx << endl;
      break;
    }
    else cnt += li.second;
  }
  return 0;
}

