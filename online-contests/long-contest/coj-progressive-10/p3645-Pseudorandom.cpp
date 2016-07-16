/*
 * Author: Ulises Mendez Martinez
 * Mail: ulisesmdzmtz@gmail.com
 * Description: Could be solvable using
 * Floyd Cycle Find Algorithm
 * but due to m < 1001 lets simulate it.
*/

#include <cstdio>
#include <cstring>

using namespace std;

int main() {
	int pos[1003], a, c, m, x0, x, i;
	while(scanf("%d %d %d %d",&a,&c,&m,&x0)!=EOF ) {
		memset(pos, -1, sizeof pos);
		x = x0, i = 0; // None has appeared
		pos[x0] = i++;
		while(true) {
			x = ((a * x) + c) % m;
			if( pos[x] != -1 ) break;
			pos[x] = i++;
		}
		printf("%s %d %d %d\n",(i-pos[x] == m)?"YES":"NO",i,pos[x],i-pos[x]);
	} 
	return 0;
}