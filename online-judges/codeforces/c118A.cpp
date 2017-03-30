#include <iostream>
#include <cctype>
#include <string>
#include <stdio.h>

using namespace std;

inline bool is_vowel(char c) {
  return c == 'a' 
     ||  c == 'e' 
     ||  c == 'i'
     ||  c == 'o'
     ||  c == 'u'
     ||  c == 'y';
}

int main() {
  string src, tgt;

  cin >> src;
  for(int i=0; i<src.size(); ++i) {
    src[i] = tolower(src[i]);
    if(is_vowel(src[i])) continue;
    printf(".%c",src[i]);
  }
  puts("");
  return 0;
}

