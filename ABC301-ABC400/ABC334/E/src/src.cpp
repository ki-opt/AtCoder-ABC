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
#include <atcoder/all>

using ull=unsigned long long;
using ll=long long;
using namespace std;
using namespace atcoder;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

class RollbackUnionFind {
public:
	vector<int> data;
	stack<pair<int,int>> history;
	int inner_snap;

	RollbackUnionFind(int sz) : inner_snap(0) { data.assign(sz, -1); }

	bool unite(int x, int y) {
		x = root(x), y = root(y);
		history.emplace(x, data[x]);
		history.emplace(y, data[y]);
		if (x == y) return false;
		if (data[x] > data[y]) swap(x, y);
		data[x] += data[y];
		data[y] = x;
		return true;
	}

	int root(int k) {
		if (data[k] < 0) return k;
		return root(data[k]);
	}

	bool issame(int x, int y) { return root(x) == root(y); }

	int size(int k) { return (-data[root(k)]); }

	void undo() {
		data[history.top().first] = history.top().second;
		history.pop();
		data[history.top().first] = history.top().second;
		history.pop();
	}

	void snapshot() { inner_snap = int(history.size() >> 1); }

	int get_state() { return int(history.size() >> 1); }

	void rollback(int state = -1) {
		if (state == -1) state = inner_snap;
		state <<= 1;
		assert(state <= (int)history.size());
		while (state < (int)history.size()) undo();
	}
};

int main() {
	int H, W;
	cin >> H >> W;
	vector<string> S(H);
	int size = 0;
	rep(i,H) {
		cin >> S[i];
		rep(j,W) if (S[i][j] == '#') size++;
	}


	RollbackUnionFind ruf(H*W);
	rep(i,H) {
		rep(j,W) {
			if (S[i][j] != '#') continue;
			if (i-1 >= 0 && S[i][j] == S[i-1][j] && !ruf.issame(i*W+j,(i-1)*W+j)) { 
				ruf.unite(i*W+j,(i-1)*W+j); size--;
			}
			if (i+1 < H && S[i][j] == S[i+1][j] && !ruf.issame(i*W+j,(i+1)*W+j)) { 
				ruf.unite(i*W+j,(i+1)*W+j); size--;
			}
			if (j-1 >= 0 && S[i][j] == S[i][j-1] && !ruf.issame(i*W+j,i*W+(j-1))) {
				ruf.unite(i*W+j,i*W+(j-1)); size--;
			}
			if (j+1 < W && S[i][j] == S[i][j+1] && !ruf.issame(i*W+j,i*W+(j+1))) {
				ruf.unite(i*W+j,i*W+(j+1)); size--;
			}
		}
	}

	/*
	int size = 0;
	unordered_map<int,int> umap;
	rep(i,H) rep(j,W) {
		if (umap.count(ruf.root(i*W+j)) > 0) continue;
		if (ruf.par[i*W+j] != -1) {
			umap[uf.root(i*W+j)]++;
			size++;
		} else {
			if (S[i][j] != '#') continue;
			if ((i-1<0 || S[i-1][j]=='.') && (i+1>=H || S[i+1][j]=='.') && 
					(j-1<0 || S[i][j-1]=='.') && (j+1>=W || S[i][j+1]=='.')) {
				umap[i*W+j]++;
				size++;
			}
		}
	}
	*/

	vector<ll> ans;
	rep(i,H) {
		rep(j,W) {
			if (S[i][j] == '.') {
				int cnt = 0;
				if (i-1 >= 0 && S[i-1][j] == '#') {
					ruf.unite(i*W+j,(i-1)*W+j);
					cnt++;
				}
				if (i+1 < H && S[i+1][j] == '#') {
					if (!ruf.issame(i*W+j,(i+1)*W+j)) {
						ruf.unite(i*W+j,(i+1)*W+j);
						cnt++;
					}
				}
				if (j-1 >= 0 && S[i][j-1] == '#') {
					if (!ruf.issame(i*W+j,i*W+(j-1))) {
						ruf.unite(i*W+j,i*W+(j-1));
						cnt++;
					}
				}
				if (j+1 < W && S[i][j+1] == '#') {
					if (!ruf.issame(i*W+j,i*W+(j+1))) {
						ruf.unite(i*W+j,i*W+(j+1));
						cnt++;
					}
				}
				ans.push_back(size+1-cnt);
				rep(v,cnt) ruf.undo();
				/*
				int left_root, right_root, up_root, down_root;
				bool isFound = false;
				if (i-1 >= 0 && S[i-1][j] == '#') {
					up_root = tmp_uf.root((i-1)*W+j);
					tmp_uf.unite(i*W+j,(i-1)*W+j);
					isFound = true;
				}
				if (i+1 < H && S[i+1][j] == '#') {
					down_root = tmp_uf.root((i+1)*W+j);
					tmp_uf.unite(i*W+j,(i+1)*W+j);
					isFound = true;
				}
				if (j-1 >= 0 && S[i][j-1] == '#') {
					left_root = tmp_uf.root(i*W+(j-1));
					tmp_uf.unite(i*W+j,i*W+(j-1)); 
					isFound = true;
				}
				if (j+1 < W && S[i][j+1] == '#') {
					right_root = tmp_uf.root(i*W+(j+1));
					tmp_uf.unite(i*W+j,i*W+(j+1));
					isFound = true;
				}
				
				
				if (!isFound) {
					ans.push_back(size+1);
				} else {
					if (i-1 >= 0 && up_root != tmp_uf.root((i-1)*W+j) && tmp_umap.count(up_root) > 0) {
						tmp_umap.erase(up_root);
					}
					if (i+1 < H && down_root != tmp_uf.root((i+1)*W+j) && tmp_umap.count(down_root) > 0) {
						tmp_umap.erase(down_root);
					}
					if (j-1 >= 0 && left_root != tmp_uf.root(i*W+(j-1)) && tmp_umap.count(left_root) > 0) {
						tmp_umap.erase(left_root);
					}
					if (j+1 < W && right_root != tmp_uf.root(i*W+(j+1)) && tmp_umap.count(right_root) > 0) {
						tmp_umap.erase(right_root);
					}
					ans.push_back(size - tmp_umap.size());
					//cerr << 1;
				}
				*/

			}
		}
	}

	ll denominator = inv_mod(ans.size(),998244353);
	ll total = 0;
	rep(i,ans.size()) total = (total + ans[i] * denominator) % 998244353;
	cout << total << endl;

	return 0;
}