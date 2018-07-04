#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
using i64 = long long int;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int z, o, x;

  cin >> z >> o >> x;

  if (o > z) {
    for (int i=1; i<x; ++i) {
      if (i&1) {
        cout << "1";
        --o;
      } else {
        cout << "0";
        --z;
      }
    }
    string os(o,'1');
    string zs(z,'0');
    if (x&1) {
      cout << os << zs << endl;
    } else {
      cout << zs << os << endl;
    }
  } else {
    for (int i=1; i<x; ++i) {
      if (i&1) {
        cout << "0";
        --z;
      } else {
        cout << "1";
        --o;
      }
    }
    string os(o, '1');
    string zs(z, '0');
    if (x&1) {
      cout << zs << os << endl;
    } else {
      cout << os << zs << endl;
    }
  }
  return 0;
}


