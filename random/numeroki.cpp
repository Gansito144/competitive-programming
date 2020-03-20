// Program to calculate one solution for a numeroki game.

#include <algorithm>
#include <utility>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

string solve(const vector<int> &cards, int target) {
  int N = cards.size();
  map<int, map<int, string>> sol;

  for (int i=0; i<N; ++i) {
    sol [1 << i][cards[i]] = to_string(cards[i]);
  }

  for (int a=1; a<(1<<N); ++a) {
    for (int b=1; b<(1<<N); ++b) {
      if ((a+b) == (a^b)) {
        for (const auto& [A, vA] : sol[a]) {
          for (const auto& [B, vB] : sol[b]) {
            // Addition
            if (sol[a^b].count(A+B) == 0) {
              sol[a^b][A+B] = "(" + vA + "+" + vB + ")";
            }
            // Multiplication
            if (sol[a^b].count(A*B) == 0) {
              sol[a^b][A*B] = "(" + vA + "*" + vB + ")";
            }
            // Substraction
            if (A >= B && sol[a^b].count(A-B) == 0) {
              sol[a^b][A-B] = "(" + vA + "-" + vB + ")";
            }
            // Division
            if (B && A % B == 0 && sol[a^b].count(A/B) == 0) {
              sol[a^b][A/B] = "(" + vA + "/" + vB + ")";
            }
          }
				}
      }
    }
  }

  // Check if there is solution.
 if (sol[(1<<N)-1].count(target) == 0) {
   sol[(1<<N)-1][target] = "There is no solution! :(";
 } else {
   sol[(1<<N)-1][target] += " = " + to_string(target);
 }

 return sol[(1<<N)-1][target];
}

int main() {
  // {4, 10, 15, 15, 19}; // 11
  // {5, 11, 14, 15, 21}; // 12
  vector <int> cards(5);
  int target;
  while (true) {
    for (int i=0; i<5; ++i) {
      cout << "card["<< i <<"] : ";
      cin >> cards[i];
    }
    cout << "target : ";
    cin >> target;
	  cout << "\n" << solve(cards, target) << "\n\n";
  }
  return 0;
}

