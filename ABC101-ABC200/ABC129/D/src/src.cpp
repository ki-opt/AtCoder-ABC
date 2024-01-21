#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <queue>
#include <stack>
#include "atcoder/all"

using ull=unsigned long long;
using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int H, W;
	cin >> H >> W;
	vector<string> S(H+2);
	string tmp;
	repp(i,1,H+1) {
		cin >> tmp;
		tmp = '#' + tmp + '#';
		S[i] = tmp;
		tmp.clear();
	}
	tmp.clear();
	rep(i,W+2) tmp += '#';
	S[0] = tmp; S[H+1] = tmp;

	//vector<pair<int,int>> dir = { {-1,0},{1,0},{0,-1},{0,1} };
	vector<vector<int>> row(H+2,vector<int>(W+2,0)), col(H+2,vector<int>(W+2,0));
	repp(i,1,H+1) {
		repp(j,1,W+1) {
			if (S[i][j] == '#') continue;
			int cnt = 0, j_dash = j;
			while (S[i][j_dash] != '#') cnt++, j_dash++; 
			repp(k,j,j_dash) col[i][k] = cnt;
			j = j_dash;
		}
	}
	repp(j,1,W+1) {
		repp(i,1,H+1) {
			if (S[i][j] == '#') continue;
			int cnt = 0, i_dash = i;
			while (S[i_dash][j] != '#') cnt++, i_dash++;
			repp(k,i,i_dash) row[k][j] = cnt;
			i = i_dash;
		}
	}

	int ans = 0;
	repp(i,1,H+1) {
		repp(j,1,W+1) {
			if (S[i][j] == '#') continue;
			ans = max(ans,row[i][j]+col[i][j]);
		}
	}
	cout << ans - 1 << endl;

	return 0;
}