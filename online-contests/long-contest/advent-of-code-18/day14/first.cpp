#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

  int pA = 0, pB = 1, target = 9;
  vector <int> recipes = {3, 7};

  cin >> target;

  while (recipes.size() < target + 10) {
    int new_recipe = recipes[pA] + recipes[pB];
    if (new_recipe >= 10) recipes.push_back(1);
    recipes.push_back(new_recipe % 10);
    pA = (pA + recipes[pA] + 1) % recipes.size();
    pB = (pB + recipes[pB] + 1) % recipes.size();
  }
  for (int i=0; i<10; ++i) {
    cout << recipes[target + i];
  }
  cout << endl;
  return 0;
}

