#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int v[1024];

int solve(int start, int end) {
  if (is_sorted(v+start, v+end))
    return end - start;
  int mid = (start + end) / 2; 
  int first = solve(start, mid);
  int second = solve(mid, end);
  return max(first, second);
}

int main() {
  int N;
  cin >> N;
  for (int i=0; i<N; ++i) cin >> v[i];
  cout << solve(0, N) << endl;
  return 0;
}

