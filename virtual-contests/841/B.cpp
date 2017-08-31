#include <iostream>
#include <cstdio>

using namespace std;

int main() {
  int n, odd=0, even=0, x;
  scanf("%d",&n);
  for(int i=0; i<n; ++i) {
    scanf("%d",&x);
    x = (x&1) ? ++odd : ++even;
  }
  puts( odd ?"First":"Second");
  return 0;
}

