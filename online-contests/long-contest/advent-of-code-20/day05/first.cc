#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
  int maximum = 0;
  int K = 7;
  string ticket;
  while (cin >> ticket) {
    int row = 0, column = 0; 
    for (int i = 0; i < K; ++i) {
      row <<= 1;
      row += (ticket[ i ] == 'B');
    }
    for (int i = K; i < ticket.size(); ++i) {
      column <<= 1;
      column += (ticket[ i ] == 'R');
    }
    maximum = max(maximum, row * 8 + column);
  }
  cout << maximum << endl;
  return 0;
}

