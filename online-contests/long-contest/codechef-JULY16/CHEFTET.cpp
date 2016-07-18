/*
 * Author: Ulises Mendez Martinez
 * Mail: ulisesmdzmtz@gmail.com
 * Solution: Consider all scenarios 
 * and choose the best.
*/
#include <bits/stdc++.h>
#define N 10004
 
using namespace std;
 
typedef long long int i64;
i64 A[N],B[N];
 
int main() {
    i64 sum, avg;
    int t, n, fit;
    
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        avg = (i64)(n);
        sum = 0LL;
        for(int i=1; i<=n; ++i) {
            scanf("%lld",&B[i]);
            sum += B[i];
        }
        for(int i=1; i<=n; ++i) {
            scanf("%lld",&A[i]);
            sum += A[i];
        }
        if(sum % avg != 0LL){
            avg = -1LL;
        }else{
            avg = sum/avg;
            B[0] = B[n+1] = 0LL;
            for(int i=1; i<=n; ++i) {
                // Try with only 1
                int a = i-1;
                int b = i;
                int c = i+1;
                if((A[i]+B[a]) == avg){
                    A[i] = avg;    
                    B[a] = 0LL;
                    continue;
                }
                if((A[i]+B[a]+B[b]) == avg){
                    A[i] = avg;
                    B[a] = B[b] = 0LL;
                    continue;
                }
                if((A[i]+B[a]+B[c]) == avg){
                    A[i] = avg;
                    B[a] = B[c] = 0LL;
                    continue;
                }
                if((A[i]+B[a]+B[b]+B[c]) == avg){
                    A[i] = avg;
                    B[a] = B[b] = B[c] = 0LL;
                    continue;
                }
                if((A[i]+B[b]) == avg){
                    A[i] = avg;
                    B[b] = 0LL;
                    continue;
                }
                if((A[i]+B[b]+B[c]) == avg){
                    A[i] = avg;
                    B[b] = B[c] = 0LL;
                    continue;
                }
                if((A[i]+B[c]) == avg){
                    A[i] = avg;
                    B[c] = 0LL;
                    continue;
                }
            }
            for(int i=1; i<=n; ++i) {
                if(A[i] != avg || B[i] != 0LL ) {
                    avg = -1LL;
                    break;
                }
            }
        }
        printf("%lld\n",avg);
    }
    return 0;
} 