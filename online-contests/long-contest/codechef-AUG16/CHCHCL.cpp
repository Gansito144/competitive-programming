/*
 * Author: Ulises Mendez Martinez
 * Mail: ulisesmdzmtz@gmail.com
 * Solution: 
*/

#include <iostream>

using namespace std;

typedef long long int i64;

int main() {
  int tests;
  i64 a, b;
  cin >> tests;

  while(tests--) {
    cin >> a >> b;
    cout << (((a*b)&1LL) ? "No" : "Yes") << endl;
  }

  return 0;
}
