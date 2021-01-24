#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  string line;
  vector <string> Graph;
  while (cin >> line) Graph.push_back( line );
  int Rows = Graph.size();
  int Columns = Graph[0].size();
  int total = 0;
  for (int r = 0; r < Rows; ++r) {
    int c = (r * 3) % Columns;
    total += Graph[ r ][ c ] == '#';
  }
  cout << total << endl;
  return 0;
}

