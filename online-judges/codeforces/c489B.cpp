/*
 * Author: Ulises Mendez Martinez
 * Mail: ulisesmdzmtz@gmail.com
 * Description: Complete search
*/

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, m, b[123],g[123], ans=0;
    
    scanf("%d",&n);
    for(int i=0; i<n; ++i) {
        scanf("%d",&b[i]);
    }
    scanf("%d",&m);
    for(int i=0; i<m; ++i) {
        scanf("%d",&g[i]);
    }
    sort(b,b+n);
    sort(g,g+m);
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            if(abs(b[i]-g[j]) < 2) {
                ++ans;
                g[j]=12345;
                break;
            }
        }
    }
    printf("%d\n",ans);

	return 0;
}