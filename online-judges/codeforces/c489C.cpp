/*
 * Author: Ulises Mendez Martinez
 * Mail: ulisesmdzmtz@gmail.com
 * Description: Greedy + imp
*/

#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int m, s, ss;
    char num[123];
    scanf("%d %d",&m,&s);
    if((s == 0 && m > 1) || s > (m*9) ) printf("-1 -1\n");
    else {
        // Print minimum
        ss = s;
        for(int i=(m-1); i > 0; --i) {
            num[i] = ((ss > 9) ? 9 : ss-1 )+'0';
            ss -= num[i]-'0';
            //printf("%d %c %d\n",i,num[i],ss);
        }
        num[m] = 0;
        num[0] = ss+'0';
        printf("%s ",num);

        // Print maximum
        for(int i=0; i<m; ++i) {
            printf("%c",(min(9,s)+'0'));
            s = max(0,s-9); 
        }
        printf("\n");
    }
	return 0;
}