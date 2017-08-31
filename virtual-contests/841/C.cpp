#include <iostream>
#include <algorithm>
#include <cstdio>
#include <utility>

using namespace std;

const int kMaxN = 200005;
int A[kMaxN], B[kMaxN], O[kMaxN];
int ans[kMaxN];

bool cmp(int a, int b) {
  return B[a] < B[b];
}

int main() {
  int N;
  scanf("%d",&N);
  for(int i=0; i<N; ++i) scanf("%d",&A[i]);
  for(int i=0; i<N; ++i) {
    scanf("%d",&B[i]);
    O[i] = i;
  }

  sort(A, A+N);
  stable_sort(O, O+N, cmp);

  for(int i=0; i<N; ++i) {
    //printf("%d %d | ", O[i],B[O[i]]);
    ans[O[i]] = A[N-i-1];
  }
  //puts("");
  for(int i=0; i<N; ++i) {
    printf("%d ",ans[i]);
  }
  printf("\n");
  return 0;
}

