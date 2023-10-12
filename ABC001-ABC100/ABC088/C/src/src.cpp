#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>

using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, limit, init) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	vector<vector<int>> c(3,vector<int>(3));
	rep(i,3) rep(j,3) cin >> c[i][j];
	for(int n1 = 0; n1 < 101; n1++) {
		vector<int> a(3), b(3);
		a[0] = n1;
		rep(j,3) b[j] = c[0][j] - a[0];
		for (int n2 = 0; n2 < 101; n2++) {
			a[1] = n2;
			int flag = 0;
			rep(j,3) {
				if (a[1] + b[j] != c[1][j]) {
					flag = 1;
					break;
				}
			}
			if (flag == 1) continue;
			for (int n3 = 0; n3 < 101; n3++) {
				a[2] = n3;
				int flag_2 = 0;
				rep(j,3) {
					if (a[2] + b[j] != c[2][j]) {
						flag_2 = 1;
						break;
					}
				}
				if (flag_2 == 0) {
					cout << "Yes" << endl;
					return 0;
				}
			}
		}	
	}
	cout << "No" << endl;
	return 0;
}