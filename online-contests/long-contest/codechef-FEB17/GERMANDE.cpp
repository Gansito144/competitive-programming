#include <stdio.h>
#include <iostream>

using namespace std;

int dp[2000001];
int d[2000001];

int main() {
	int T, o1, o2, N, N2;
	int can = 0, cnt, mid, may;
	scanf("%d",&T);
	while(T--) {
		scanf("%d %d",&o1,&o2);
		N = o1 * o2;
		for(int i=0; i<N; ++i) {
			scanf("%d",&d[i]);
			d[i+N] = d[i];
		}
		N2 = N << 1;
		for(int i=1; i<N2; ++i) d[i] += d[i-1];
		can = 0;
		mid = o2 >> 1;
		may = o1 >> 1;
		for(int i=0; i<o2; ++i) {
			cnt = 0;
			for(int j=0, x=i+o2; j<o1; ++j, x+=o2) {
				if( d[x]-d[x-o2] > mid) cnt++;
			}
			if(cnt > may) {
				//printf("%d - %d\n",i,cnt);
				can = true;
				break;
			}
		}
		for(int i=1; i<N2; ++i) d[i] = 0;
		printf("%d\n",can);
	}

	return 0;
}