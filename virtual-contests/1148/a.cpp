#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
using i64 = long long int;


int main() {
  i64 a, b, c;
  cin >> a >> b >> c;
  
  // First put all c´s
  i64 tot = c << 1;

  // then work with prefix
  i64 pre = min(a, b);
  tot += pre << 1;
  a -= pre; b -= pre;
  // if there is one more b use it
  if (b) {++tot; --b;}

  // then work with suffix
  i64 suf = min(a, b);
  tot += suf << 1;
  a -= suf; b -= suf;
  // If there is one more a use it
  if (a) {++tot; --a;}

  cout << tot << endl;
  return 0;
}
