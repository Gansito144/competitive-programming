#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
  const int K = 7, MX = 1024;
  string ticket;
  vector < bool > seen ( MX );
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
    seen[ row * 8 + column ] = true;
  }
  for (int id = 1; id < MX - 1; ++id) {
    if ( !seen[ id ] && seen[id - 1] && seen[id + 1]){
      cout << id << endl;
      break;
    }
  }
  return 0;
}

