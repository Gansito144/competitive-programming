/*
 * Author: Ulises Mendez Martinez
 * Mail: ulisesmdzmtz@gmail.com
 * Description: Simulation with bitmask
*/

#include <cstdio>

using namespace std;

int sudoku[25][25];
int sqr[]={0,1,4,9,16,25};

int main() {
	int cases, n, r, bit;
	bool ok;

	scanf("%d",&cases);
	while(cases--) {
		// Read size & init ok
		scanf("%d",&n);
		ok = true;
		// Find its square root
		for(r=0; sqr[r]!=n; ++r);
		// Read sudoku
		for(int i=0; i<n; ++i) {
			for(int j=0; j<n; ++j) {
				scanf("%d",&bit);
				sudoku[i][j] = 1<<bit; 
			}
		}
		// Lets check rows and columns
		for(int i=0; i<n; ++i) {
			int rw = 0;
			int cl = 0;
			for(int j=0; j<n; ++j){
				rw |= sudoku[i][j];
				cl |= sudoku[j][i];
			}
			if(__builtin_popcount(rw) != n || __builtin_popcount(cl) != n )
			{
				ok = false;
				break;
			}
		}
		// Lets check r*r blocks
		for(int i=0; i<n && ok; i+= r) {
			for(int j=0; j<n; j+= r) {
				int msk = 0;
				for(int x=0; x<r; ++x) {
					for(int y=0; y<r; ++y) {
						msk |= sudoku[i+x][j+y];
					}
				}
				if(__builtin_popcount(msk) != n){
					ok = false;
					break;
				}
			}
		}
		if(!ok) {
			puts("no");
			continue;
		}
		puts("yes");
				
	}

	return 0;
}