#include<iostream>
#include<algorithm>

using namespace std;

typedef long long int i64;

const int MaxN = 34;

int main(){
  int N, old = 1, now = 0, prv = MaxN-1;
  i64 sa[2][MaxN] = {0}, a[MaxN];

  cin >> N;
  for(int i=0; i<N; ++i) cin >> a[i];
  sort(a, a+N);
  sa[now][MaxN-1] = 1LL;
  for(int k=N-1; k>=0; --k) {
    swap(old, now);
    for(int n=1; n<=a[k]; ++n) {
      sa[now][n] =  sa[old][prv] - sa[old][n-1];
      sa[now][n] += sa[now][n-1];
    }
    prv = a[k];
  }
  cout << sa[now][prv] << endl;
  return 0;
}

