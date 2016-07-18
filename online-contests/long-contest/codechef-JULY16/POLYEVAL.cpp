/*
 * Author: Ulises Mendez Martinez
 * Mail: ulisesmdzmtz@gmail.com
 * Solution: Use Horner's method
 * https://en.wikipedia.org/wiki/Horner%27s_method
*/

 #include <cstdio>
#define N 1000006
 
using namespace std;
 
typedef long long int i64;
const i64 md = 786433LL;
i64 a[N], ans, x;
 
int main() {
	int n, q;
	
	scanf("%d",&n);
	for(int i=0; i<=n; ++i) {
        scanf("%lld",&a[i]);
	}
    scanf("%d",&q);
    while(q--) {
        scanf("%lld",&x);
        ans = 0LL;
        for(int i=n; i>=0; --i) {
            ans = (a[i]+(x*ans)%md)%md;
            //printf("%d %lld\n",i,ans);
        }
        printf("%lld\n",ans);
    }
	return 0;
} 