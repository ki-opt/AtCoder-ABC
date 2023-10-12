#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <queue>

using ull=unsigned long long;
using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	vector<vector<int>> c(3, vector<int>(3));
	rep(i,3) rep(j,3) cin >> c[i][j];

	//*
	int total = 0;
	int gakkari = 0;
	vector<int> nums {0,1,2,3,4,5,6,7,8};
	do {
		total++;
		rep(i,7) {
			// yoko
			int y = nums[i] / 3, x = nums[i] % 3;
			int y1 = nums[i+1] / 3, x1 = nums[i+1] % 3;
			int y2 = nums[i+2] / 3, x2 = nums[i+2] % 3;
			if (y == y1 && y1 == y2) {
				if (c[y][x] == c[y1][x1]) { gakkari++; break; }
			} else if (x == x1 && x1 == x2) {
				if (c[y][x] == c[y1][x1]) { gakkari++; break; }
			} else if (x != x1 && y != y1 && ((nums[i] == 2 && nums[i+1] == 4) || (nums[i] == 4 && nums[i+1] == 2) ||
														 (nums[i] == 2 && nums[i+1] == 6) || (nums[i] == 6 && nums[i+1] == 2) ||
														 (nums[i] == 4 && nums[i+1] == 6) || (nums[i] == 6 && nums[i+1] == 4)
														)) {
				if (c[y][x] == c[y1][x1]) { gakkari++; break; }
			} else if (x != x1 && y != y1 && ((nums[i] == 0 && nums[i+1] == 4) || (nums[i] == 4 && nums[i+1] == 0) || 
														 (nums[i] == 0 && nums[i+1] == 8) || (nums[i] == 8 && nums[i+1] == 0) ||
														 (nums[i] == 4 && nums[i+1] == 8) || (nums[i] == 8 && nums[i+1] == 4)														 
														)) {
				if (c[y][x] == c[y1][x1]) { gakkari++; break; }
			} else {

			}
		}
	} while (next_permutation(nums.begin(), nums.end()));//*/

	cout << 1.0 - (double)gakkari / (double)total << endl;
/*
	int total = 362880;
	int val;
	repp(i,1,10) {
		// yoko
		rep(j,3) {
			int tmp = 0;
			rep(k,3) {
				if (c[j][k] == i) tmp++;
			}
			if (tmp == 2) val += 2;
			//else if (tmp == 3) val += 6;
		}
		// tate
		rep(j,3) {
			int tmp = 0;
			rep(k,3) {
				if (c[k][j] == i) tmp++;
			}
			if (tmp == 2) val += 2;
			//else if (tmp == 3) val += 6;
		}
		// naname
		int aaa = 0;
		rep(j,3) {
			if (c[j][j] == i) aaa++;
		}
		if (aaa == 2) val += 2;
		//else if (aaa == 3) val += 6;
		
		aaa = 0;
		rep(j,3) {
			if (c[2-j][j] == i) aaa++;
		}
		if (aaa == 2) val += 2;
		//else if (aaa == 3) val += 6;
	}
	
	//printf("%.10f\n", 1.0 - ((double)(val * 8 * 5040) / (double)total));*/
	return 0;
}