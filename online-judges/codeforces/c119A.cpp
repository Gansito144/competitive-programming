#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

int main() {
  int heap;
  int player[2];
  cin >> player[0] >> player[1] >> heap;
  int winner = 1;
  for (int i=0; ; i++) {
    int p = i & 1;
    int g = gcd(player[p], heap);
    if (g > heap) {
      winner = 1 - p;
      break;
    }
    heap -= g;
  }
  cout << winner << endl;
  return 0;
} 

