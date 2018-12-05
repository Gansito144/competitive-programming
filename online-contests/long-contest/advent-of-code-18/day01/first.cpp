#include <cstdio>

int main() {
  int n, sum = 0;
  while (scanf("%d\n",&n) != EOF) {
    sum += n;
  }
  printf("%d\n",sum);
  return 0;
}

