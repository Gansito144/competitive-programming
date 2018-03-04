#include <iostream>
#include <deque>
#include <bitset>

using namespace std;

const int MaxN = 31624;
bitset <MaxN> ip;
deque <int> pr;

void sieve() {
  ip.set();
  for (int cp=2; cp<MaxN; ++cp)
    if (ip.test(cp)) {
      pr.push_back(cp);
      for (int np=cp+cp; np<MaxN; np += cp)
        ip.reset(np);
    }
}

bool test (int n, int p)
{
  for (int &cp : pr)
  {
    if (cp >= n || cp > p) break;
    if (n%cp == 0)
      return false;
  }
  return true;
}

int main () {
  sieve();
  int p, y, ans = -1;
  cin >> p >> y;
  while ( y>p )
  {
    if (test(y, p))
    {
      ans = y;
      break;
    } 
    --y;
  }
  cout << ans << endl;
  return 0;
}


