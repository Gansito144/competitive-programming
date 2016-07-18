/*
 * Author: Ulises Mendez Martinez
 * Mail: ulisesmdzmtz@gmail.com
 * Description: Choose an optimal way to 
 * pick numbers gaining maximum points
 * Solution: dp
*/

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int i64;

i64 dp[123456], sum[123456];

int main() {
	int n, mx = 0, x;

	scanf("%d",&n);
	while(n--) {
		scanf("%d",&x);
		mx = max(x+1, mx);
		sum[x+1] += x;
	}
	for(int i=2; i<=mx; ++i) {
		dp[i] = max(sum[i]+dp[i-2],dp[i-1]);
	}
	// cout needed due to cf runs over win32
	cout << dp[mx] << endl;

	return 0;
}