#include <iostream>
#include <algorithm>

using namespace std;
using i64 = long long int;

int main() {
  i64 k, n, w;
  cin >> k >> n >> w;
  i64 need = ((w*(w+1LL))>>1) * k;
  cout << max(need - n, 0LL) << "\n"; 
  return 0;
}

