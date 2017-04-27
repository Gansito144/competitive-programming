#include <iostream>
#include <string>

using namespace std;

int main() {
  int cnt = 0;
  string s;
  char pr = '*';
  
  cin >> s;
  for(int i=0; i<s.size(); ++i) {
    cnt = (s[i] == pr) ? cnt+1 : 1 ;
    pr = s[i];
    if(cnt == 7){ cnt = -1; break;} 
  }
  cout << (cnt==-1?"YES":"NO") << endl;
  return 0;
}
