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
  int t11 = 0, t31 = 0, t51 = 0, t71 = 0, t12 = 0;
  for (int r = 0; r < Rows; ++r) {
    int c1 = (r * 1) % Columns;
    t11 += Graph[ r ][ c1 ] == '#';
    if ((r << 1) < Rows) {
      t12 += Graph[ r << 1 ][ c1 ] == '#';
    }
    int c3 = (r * 3) % Columns;
    t31 += Graph[ r ][ c3 ] == '#';
    int c5 = (r * 5) % Columns;
    t51 += Graph[ r ][ c5 ] == '#';
    int c7 = (r * 7) % Columns;
    t71 += Graph[ r ][ c7 ] == '#';
  }
  int total = t11 *t31 * t51 * t71 * t12;
  cout << total << endl;
  return 0;
}

