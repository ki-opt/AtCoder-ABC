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
	vector<vector<int>> A(9,vector<int>(9));
	rep(i,9) rep(j,9) cin >> A[i][j];

	rep(i,9) {
		vector<bool> check(10,false);
		rep(j,9) check[A[i][j]] = true;
		repp(j,1,10) if (!check[j]) { cout << "No" << endl; return 0; }
		check = vector<bool>(10,false);
		rep(j,9) check[A[j][i]] = true;
		repp(j,1,10) if (!check[j]) { cout << "No" << endl; return 0; }
	}

	rep(i,3) {
		rep(j,3) {
			vector<bool> check(10,false);
			repp(k,i*3,(i+1)*3) {
				repp(l,j*3,(j+1)*3) {
					check[A[k][l]] = true;
				}
			}
			repp(k,1,10) if (!check[k]) { cout << "No" << endl; return 0; }
		}
	}

	cout << "Yes" << endl;

	return 0;
}