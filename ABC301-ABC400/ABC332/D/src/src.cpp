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

int H, W;

// ハッシュ関数の定義
struct VectorHash {
	size_t operator()(const vector<vector<int>>& vec) const {
		size_t seed = vec.size();
		for (const auto& innerVec : vec) {
			seed ^= innerVec.size() + 0x9e3779b9 + (seed << 6) + (seed >> 2);
			for (const auto& i : innerVec) {
				seed ^= i + 0x9e3779b9 + (seed << 6) + (seed >> 2);
			}
		}
		return seed;
	}
};

// 等値比較関数の定義
struct VectorEqual {
	bool operator()(const vector<vector<int>>& lhs, const vector<vector<int>>& rhs) const {
		return lhs == rhs;
	}
};

void swap_col(vector<vector<int>> &mat, int w, int w_dash) {
	rep(i,H) swap(mat[i][w],mat[i][w_dash]);
}

bool check(const vector<vector<int>> &a, const vector<vector<int>> &B) {
	rep(i,H) rep(j,W) {
		if (a[i][j] != B[i][j]) return false;
	}
	return true;
}

struct Node {
	vector<vector<int>> a;
	int num;
};

int main() {
	cin >> H >> W;
	vector<vector<int>> A(H,vector<int>(W)), B(H,vector<int>(W));
	rep(i,H) rep(j,W) { cin >> A[i][j]; }
	rep(i,H) rep(j,W) { cin >> B[i][j]; }

	queue<Node> que;
	unordered_map<vector<vector<int>>, int, VectorHash, VectorEqual> ump;
	ump[A]++;
	que.push(Node{A,0});
	while (!que.empty()) {
		Node tmp = que.front(); que.pop();
		if (check(tmp.a,B)) { cout << tmp.num << endl; return 0; }
		rep(i,H-1) {
			vector<vector<int>> a = tmp.a;
			swap(a[i],a[i+1]);
			if (ump.count(a) > 0) continue;
			ump[a]++;
			que.push(Node{a,tmp.num+1});
		}
		rep(i,W-1) {
			vector<vector<int>> a = tmp.a;
			swap_col(a,i,i+1);
			if (ump.count(a) > 0) continue;
			ump[a]++;
			que.push(Node{a,tmp.num+1});
		}
	}
	cout << -1 << endl;
	return 0;
}