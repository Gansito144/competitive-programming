#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() 
{
  string s;
  string url;
  cin >> s;

  // Protocol
  if(s[0] == 'h')
  {
    url += "http://";
    s = s.substr(4);
  }
  else
  {
    url += "ftp://";
    s = s.substr(3);
  }
  char c = s[0];
  url += c;
  s = s.substr(1);
  int pos = (int)s.find("ru");
  string domain = s.substr(0, pos);
  url += domain + ".ru";
  s = s.substr(pos+2);
  if(s.size()) url += string("/") + s;
  cout << url << endl;
  return 0;
}
