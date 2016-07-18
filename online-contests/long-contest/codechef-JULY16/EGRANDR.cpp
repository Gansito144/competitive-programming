/*
 * Author: Ulises Mendez Martinez
 * Mail: ulisesmdzmtz@gmail.com
 * Solution: Implementaion
*/

 #include <cstdio>
 
using namespace std;
 
int main() {
	int t, n, sum, gr;
	bool has_F, has_A;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		sum = n << 2;
		has_F = has_A = false;
		while(n--) {
			scanf("%d",&gr);
			has_F |= gr == 2;
			has_A |= gr == 5;
			sum -= gr;
		}
		puts((!has_F && has_A && sum<=0)?"Yes":"No");
	}
	return 0;
} 