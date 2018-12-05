#include <cstdio>
#include <set>
#include <vector>

using namespace std;

int main() {
  int n, sum = 0, id = 0;
  set <int> seen;
  vector <int> values;

  while (scanf("%d\n",&n) != EOF) {
    values.push_back(n);
  }
  n = values.size();
  while (true) {
    sum += values[id];
    if (seen.find(sum) != seen.end())
      break;
    seen.insert(sum);
    id = id + 1;
    if (id == n) id = 0;
  }
  printf("%d\n",sum);
  return 0;
}

