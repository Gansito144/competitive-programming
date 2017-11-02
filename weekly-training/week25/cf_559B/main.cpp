#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>

#define all(a) (a).begin(), (a).end() 

using namespace std;

void check (string &sa, string &sb)
{
  if(sa.size() % 2 == 0)
  {
    int m = sa.size() >> 1;
    string sa1 = sa.substr(0, m);
    string sa2 = sa.substr(m);
    string sb1 = sb.substr(0,m);
    string sb2 = sb.substr(m);

    check(sa1, sb1);
    check(sa2, sb2);

    if(sa1 > sa2) swap(sa1, sa2);
    if(sb1 > sb2) swap(sb1, sb2); 
    
    sa = sa1 + sa2;
    sb = sb1 + sb2;
  }
}

int main ()
{
  int n;
  string sa, sb;
  cin >> sa >> sb;
  check(sa, sb);
  printf("%s\n",(sa == sb)?"YES":"NO");
  return 0;
}
