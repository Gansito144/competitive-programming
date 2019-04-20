#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

  int pA = 0, pB = 1;
  string target = "51589", recipes = "37", suffix = "37";

  cin >> target;

  while (suffix.find(target) == string::npos) {
    int new_recipe = (recipes[pA] - '0') + (recipes[pB] - '0');
    if (new_recipe >= 10) recipes += '1';
    recipes += '0' + (new_recipe % 10);
    pA = (pA + recipes[pA] - '0' + 1) % recipes.size();
    pB = (pB + recipes[pB] - '0' + 1) % recipes.size();
    suffix = recipes.substr(max(0,(int) recipes.size() - 20));
  }
  cout << recipes.find(target) << endl;
  return 0;
}

