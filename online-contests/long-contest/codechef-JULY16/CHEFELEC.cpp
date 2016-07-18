/*
 * Author: Ulises Mendez Martinez
 * Mail: ulisesmdzmtz@gmail.com
 * Solution: The only thing we can 
 * minimize is the gap not covered 
 * between each pair of cities with 
 * electricity
*/

#include <bits/stdc++.h>
#define N 123456 
 
using namespace std;
 
typedef long long int i64;
 
i64 h[N];
char has[N];
i64 ans;
 
int main() {
	int t, n;
	scanf("%d\n",&t);
	while(t--) {
		deque< int > dq;
        // Read cases
		scanf("%d\n",&n);
		scanf("%s",has);
        //
		dq.push_back(0);
        for(int i=1; i<=n; ++i) {
			scanf("%lld",&h[i]);
            if( has[i-1] == '1'){
                dq.push_back(i);
            }
		}
        dq.push_back(n+1);
        h[0] = INT_MIN;
		h[n+1] = INT_MAX;
        ans = 0LL;
        for(int i=1; i<dq.size(); ++i) {
            i64 mx = 0LL;
            int l=dq[i-1], r=dq[i];
            for(int j=l+1; j<=r; ++j){
                mx = max(mx, h[j]-h[j-1]);
            }
            ans += (h[r]-h[l])-mx;
        }
		printf("%lld\n",ans);
	}
	return 0;
}