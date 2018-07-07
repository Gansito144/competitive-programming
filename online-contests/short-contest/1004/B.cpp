#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
using i64 = long long int;

int main () {

  int n, m, l, r;
  i64 ans = 0; 
  cin >> n >> m;
  string s(n, '0');
  for (int i=0; i<n; ++i)
    s[i] = '0' + (i&1);
  cout << s << endl; 
  return 0;
}

