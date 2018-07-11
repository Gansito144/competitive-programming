#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main () {
  string a, b;
  cin >> a >> b;
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  int m = 0;
  while (m<a.size() && m<b.size() && a[m] == b[m])
    ++m;
  cout << a.size() + b.size() - m - m << endl;
  return 0;
}

