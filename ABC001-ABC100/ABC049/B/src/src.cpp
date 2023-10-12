#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>

using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, limit, init) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int H, W;
	cin >> H >> W;
	vector<vector<char>> C(H,vector<char>(W));
	rep(i,H){
		rep(j,W) cin >> C[i][j];
	}

	rep(i,H){
		rep(j,W) cout << C[i][j] << " ";
		cout << endl;
		rep(j,W) cout << C[i][j] << " ";
		cout << endl;
	}

	return 0;
}