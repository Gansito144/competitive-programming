#include <iostream>
#include <algorithm>

int main (){
  int s = 0, a, b, c, d, e, f;
  std::cin >> a >> b >> c >> d >> e >> f;
  s += std::max(0, d-a);
  s += std::max(0, e-b);
  s += std::max(0, f-c);
  std::cout << s << std::endl;
  return 0;
}



