/*
 * Author: Ulises Mendez Martinez
 * Mail: ulisesmdzmtz@gmail.com
 * Description: Use cumulative sums
 * and check all ranges i,j possible
*/

#include <cstdio>
#include <algorithm>

using namespace std;

int O[123];

int main() {
	int n , b , ans = 0;
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) {
        scanf("%d",&b);
        O[i]=O[i-1]+b;
    }
    ans = 0;
    for(int L=1; L<=n; ++L) {
        for(int R=L; R<=n; ++R) {
            ans=max(ans,R-L+1+O[n]+((O[L-1]-O[R])<<1));
        }
    }
    printf("%d\n",ans);
	return 0;
}