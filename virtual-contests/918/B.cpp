#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main ()
{
  int n, m;
  cin >> n >> m;
  unordered_map <string, string> name;
  string srvr, ip, cmd;
  while (n--)
  {
    cin >> srvr >> ip;
    name[ip+";"] = string("#") + srvr;
  }
  while (m--)
  {
    cin >> cmd >> ip;
    cout << cmd << " " << ip << " " << name[ip] << endl;
  }
  return 0;
}

