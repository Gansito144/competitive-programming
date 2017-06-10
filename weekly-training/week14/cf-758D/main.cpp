#include <iostream>

using namespace std;

typedef long long int i64;

int main() {
  string big;
  i64 n, ans = 0LL, base = 1LL, pot;

  cin >> n;
  cin >> big;
  
  int li = big.size()-1;
  for(int i=big.size()-1; i>=0; ) {
    i64 part = 0;
    i64 pot = 1LL;
    while(i>=0 && (pot < n) &&
      ((part + (pot*(big[i]-'0'))) < n))
    {
      part += pot*(big[i]-'0');
      --i;
      pot *= 10LL;
    }
    while(i+1<li && big[i+1]=='0') {
      ++i;
    }
    li = i;
    ans += part * base;
    base *= n;
  }
  cout << ans << endl;
  return 0;
}

