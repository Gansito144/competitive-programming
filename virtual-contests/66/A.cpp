#include <iostream>
#include <string>

using namespace std;
using i64 = long long int;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  string n, ans;

  cin >> n;
  // Negative
  if(n[0] == '-') {
    n = n.substr(1);
    while (n.size() < 20) n = "0" + n;
    if      (n > "09223372036854775808") ans = "BigInteger";
    else if (n > "00000000002147483648") ans = "long";
    else if (n > "00000000000000032768") ans = "int";
    else if (n > "00000000000000000128") ans = "short";
    else                                 ans = "byte"; 
  } else {
    while (n.size() < 20) n = "0" + n;
    if      (n > "09223372036854775807") ans = "BigInteger";
    else if (n > "00000000002147483647") ans = "long";
    else if (n > "00000000000000032767") ans = "int";
    else if (n > "00000000000000000127") ans = "short";
    else                                 ans = "byte"; 
  }
  cout << ans << endl;
  return 0;
}


