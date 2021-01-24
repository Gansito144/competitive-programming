#include <iostream>
#include <vector>

using namespace std;

int main () {
  int target = 2020;
  int current;
  vector < int > numbers;
  while (cin >> current) numbers.push_back( current );
  for (int a = 0; a < numbers.size(); ++a) {
    for (int b = 0; b < numbers.size(); ++b) {
      for (int c = 0; c < numbers.size(); ++c) {
        if (target == (numbers[ a ] + numbers[ b ] + numbers[ c ])) {
          cout << ( numbers[ a ] * numbers[ b ] * numbers[ c ]) << endl;
          return 0;
        }
      }
    }
  }
  return 0;
}

