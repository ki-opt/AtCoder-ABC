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
#include <set>
#include "atcoder/all"

using namespace std;
using namespace atcoder;

using ull=unsigned long long;
using ll=long long;
//using mint = modint998244353;
//using mint = modint1000000007;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

struct Node {
	int s, index;
	set<int> sets;
	bool operator<(const Node& another) const {
		return s > another.s;
	}
};

int main() {
	int H, W, M; cin >> H >> W >> M;
	vector<int> h(M), w(M);
	vector<set<int>> row(H), col(W);
	rep(i,M) {
		cin >> h[i] >> w[i];
		h[i]--; w[i]--;
		row[h[i]].insert(w[i]);
		col[w[i]].insert(h[i]);
	}

	vector<Node> col_tmp(W);
	rep(i,W) col_tmp[i] = {(int)col[i].size(),i,col[i]};
	sort(col_tmp.begin(),col_tmp.end());

	int ans = 0;
	rep(i,H) {
		int tmp = row[i].size();
		for (int j = 0; j < W; j++) {
			if (row[i].find(col_tmp[j].index) != row[i].end()) {
				ans = max(ans,tmp+col_tmp[j].s-1);
			} else {
				ans = max(ans,tmp+col_tmp[j].s);
				break;
			}
		}
	}
	cout << ans << endl;
	/*
	int row_max = 0, col_max = 0;
	rep(i,H) row_max = max(row_max,(int)row[i].size());
	rep(i,W) col_max = max(col_max,(int)col[i].size());
	cout << row_max + col_max << endl;
	*/

	return 0;
}