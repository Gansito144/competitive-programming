#include <iostream>
#include <unordered_set>

using namespace std;

int main () {
  unordered_set < int > hash;
  int target = 2020;
  int current;
  while (cin >> current) {
    if (hash.find(target - current) != hash.end()) {
      cout << ( current ) * ( target - current ) << endl;
      break;
    }
    hash.insert( current );
  }
  return 0;
}

