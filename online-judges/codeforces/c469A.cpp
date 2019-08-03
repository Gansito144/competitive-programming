#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int levels, level;
  cin >> levels;
  vector <int> passed(levels+1);
  int Xn, Xy;
  cin >> Xn;
  while(Xn--) {
    cin >> level;
    passed[level] = 1;
  }
  cin >> Xy;
  while(Xy--) {
    cin >> level;
    passed[level] = 1;
  }
  if (accumulate(passed.begin(), passed.end(), 0) == levels)
    cout << "I become the guy.\n";
  else
    cout << "Oh, my keyboard!\n";
  return 0;
}

