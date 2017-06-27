#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

const int Mx=10004, alpha=26;
int cnt[alpha][Mx], need[alpha], N, chr, n;
string S, T, ANS;

inline bool check(int i) {
  if(i<1) return false;
  for(int k=0; k<alpha; k++)
    if(need[k] > cnt[k][i])
      return false;
  return true;
}

int main() {
    
  // Read input
  cin >> S;
  N = S.size();
  // Compute the cumulative frequencies
  for(int i=1; i<=N; i++) {
    for(int k=0; k<alpha; k++)
      cnt[k][i] = cnt[k][i-1];
    chr = S[i-1]-'a'; 
    cnt[chr][i]++;
    need[chr]++;
  }
    
  // Set what is needed and the target
  for(int k=0; k<alpha; k++) {
    need[k] /= 2;
    string nw(need[k],'a'+k);
    T += nw;
    n += need[k];
  }

  //Find left boundary
  int L = 1, R = N;
  while(!check(L)) L++;
    
  // Lets create the string
  while(ANS.size() < n) {
    for(int k=0; k<n; k++) {
      if(T[k] == '*') continue;
      chr = T[k] - 'a';
      if(cnt[chr][R] - cnt[chr][L-1]) {
        ANS += T[k];
        // Set the new boundaries
        need[chr]--;
        while(check(L-1)) L--;
        while(S[R-1] != T[k] ) R--;
        R--;
        //cout << "Added " << k << " " << T[k] << " L "<< L << " R " << R << endl;
        T[k] = '*';
        break;
      }
    }
  }
  cout << ANS << endl;
  return 0;
}

