#include <iostream>
#include <stdio.h>

using namespace std;

const int kMaxN = 255;

int A[kMaxN][kMaxN], mx[kMaxN][kMaxN], mn[kMaxN][kMaxN];
int dqmn[kMaxN][kMaxN], dqmx[kMaxN][kMaxN];
int frmx[kMaxN], lsmx[kMaxN], DQmx[kMaxN], FRmx, LSmx;
int frmn[kMaxN], lsmn[kMaxN], DQmn[kMaxN], FRmn, LSmn;


void solve(int N, int b) {
  // First block
  for(int c=1; c<=N; ++c) {
    frmn[c]=0, lsmn[c]=-1;
    frmx[c]=0, lsmx[c]=-1;
  }
  for(int r=1; r<=b; ++r)
    for(int c=1; c<=N; ++c) {
      while(frmn[c]<=lsmn[c] && dqmn[c][lsmn[c]]>A[r][c]) --lsmn[c];
      dqmn[c][++lsmn[c]] = A[r][c];
      while(frmx[c]<=lsmx[c] && dqmx[c][lsmx[c]]<A[r][c]) --lsmx[c];
      dqmx[c][++lsmx[c]] = A[r][c];
    }
  // Rest of matrix
  for(int r=b; r<=N; ++r) {
    FRmn=0, LSmn=-1;
    FRmx=0, LSmx=-1;
    // First B columns at the begining of each row
    for(int c=1; c<=b; ++c) {
      while(FRmn<=LSmn && DQmn[LSmn]>dqmn[c][frmn[c]]) --LSmn;
      DQmn[++LSmn]=dqmn[c][frmn[c]];
      while(FRmx<=LSmx && DQmx[LSmx]<dqmx[c][frmx[c]]) --LSmx;
      DQmx[++LSmx]=dqmx[c][frmx[c]];
    }
    // Process all raw
    for(int c=b; c<=N; ++c) {
      mn[r][c] = DQmn[FRmn];
      mx[r][c] = DQmx[FRmx];
      if(DQmn[FRmn]==dqmn[c-b+1][frmn[c-b+1]]) ++FRmn;
      if(DQmx[FRmx]==dqmx[c-b+1][frmx[c-b+1]]) ++FRmx;
      if(c<N) {
        while(FRmn<=LSmn && DQmn[LSmn]>dqmn[c+1][frmn[c+1]] ) --LSmn;
        DQmn[++LSmn]=dqmn[c+1][frmn[c+1]];
        while(FRmx<=LSmx && DQmx[LSmx]<dqmx[c+1][frmx[c+1]] ) --LSmx;
        DQmx[++LSmx]=dqmx[c+1][frmx[c+1]];
      }
    }
    // Remove last row
    for(int c=1; c<=N; ++c) {
      if(dqmn[c][frmn[c]] == A[r-b+1][c])
        frmn[c]++;
      if(dqmx[c][frmx[c]] == A[r-b+1][c])
        frmx[c]++;
    }
        
    if(r<N)
      for(int c=1; c<=N; ++c) {
        while(frmn[c]<=lsmn[c] && dqmn[c][lsmn[c]]>A[r+1][c]) --lsmn[c];
        dqmn[c][++lsmn[c]] = A[r+1][c];
        while(frmx[c]<=lsmx[c] && dqmx[c][lsmx[c]]<A[r+1][c]) --lsmx[c];
        dqmx[c][++lsmx[c]] = A[r+1][c];
      }
  }
}

int main() {
  int N, B, K, r, c, x;
  
  scanf("%d %d %d",&N,&B,&K);
  
  for(int i=1; i<=N; ++i)
    for(int j=1; j<=N; ++j) {
      scanf("%d",&A[i][j]);
    }
  
  solve(N, B);
  
  while(K--) {
    scanf("%d %d",&r,&c);
    printf("%d\n",mx[r+B-1][c+B-1]-mn[r+B-1][c+B-1]);
  }
  
  return 0;
}
