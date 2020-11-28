#include <iostream>
#include <algorithm>
#include <vector>

int main() {
  std::ios::sync_with_stdio( 0 );
  std::cin.tie( 0 ); std::cout.tie( 0 );

  int N, K, v;
  std::cin >> K >> N;
  std::vector< int > count(K + 1);
  for (int i = 0; i < N; ++i) {
    std::cin >> v;
    ++count[ v ];
  }

  int reminder = N % K;
  int target = (reminder == 1) ? N / K : ((N + 1) / K);
  int less = 0, more = 0, last_less = 0, last_more = 0; 
  for (int i = 1; i <= K; ++i) {
    if (count[ i ] < target) {
      ++less;
      last_less = i;
    }
    else if (count[ i ] > target) {
      ++more;
      last_more = i;
    }
  }

  bool possible = true;
  ++count[last_less];
  --count[last_more];
  for (int i=1; i<=K; ++i) possible &= (count[i] == target);

  if (!possible) {
    std::cout << "*\n";
  } else {
    if (more > 0) std::cout << "-" << last_more;
    if (less > 0) std::cout << (more > 0 ? " +":"+") << last_less;
    std::cout << "\n";
  }

  return 0;
}

