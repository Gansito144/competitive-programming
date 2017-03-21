#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>

#define F first
#define S second

using namespace std;

typedef pair<int,int> ii;
typedef pair<ii, int> iii;

const int MaxL = 10004;
char word[MaxL << 1];

// Suffix Array
int first_suffix(int N) {
  int old = 0, now = 1;
  int P[2][(N<<1)+2];
  deque <iii> L(N);

  for(int i=0; i<N<<1; ++i) {
    P[0][i] = word[i]-'a';
  }

  for(int cnt=1; cnt<N; cnt<<=1) {
    for(int i=0; i<N; ++i) {
      L[i].F.F = P[old][i];
      L[i].F.S = P[old][i+cnt];
      L[i].S = i;
    }
    sort(L.begin(), L.end());
    for(int i=0; i<N; ++i) {
      P[now][L[i].S] = (i>0 && L[i].F==L[i-1].F) ? P[now][L[i-1].S] : i;
      P[now][L[i].S+N] = P[now][L[i].S];
    }
    swap(now,old);
  }
  // Print solution
  //for(int i=0; i<N; i++) {
  //  printf("sa[%d] = %d\n",i,L[i].S);
  //}
  return L[0].S + 1;
}

int main(){
  int N, len;
  scanf("%d",&N);
  while(N--) {
    scanf("%s",word);
    len = strlen(word);
    word[len<<1] = word[len];
    for(int i=0; i<len; ++i)
      word[i+len] = word[i];
    // Time Complexity: O( N*log^2(N) )
    printf("%d\n",first_suffix(len));
  }
  return 0;
}

