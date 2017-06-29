#include <iostream>
#include <algorithm>

using namespace std;

string no[12] = {"C","C#","D",
               "D#","E","F",
               "F#","G","G#",
               "A","B","H"};

int main() {
  int p[3], da, db;
  string n[3];
  int o[3] = {0,1,2};
  cin >> n[0] >> n[1] >> n[2];
  for(int i=0; i<12; ++i) {
    for(int k=0; k<3; ++k) {
      if(n[k] == no[i]) p[k] = i+1;
    }
  }
  string ans = "strange";
  do {
    da = (p[o[1]]<p[o[0]]) ? 12-p[o[0]]+p[o[1]]:p[o[1]]-p[o[0]];
    db = (p[o[2]]<p[o[1]]) ? 12-p[o[1]]+p[o[2]]:p[o[2]]-p[o[1]];
    if((db==3)&&(da==4)) ans = "major";
    if((db==4)&&(da==3)) ans = "minor";
  } while(next_permutation(o,o+3) && ans =="strange");
  cout << ans << endl;
  return 0;
}

