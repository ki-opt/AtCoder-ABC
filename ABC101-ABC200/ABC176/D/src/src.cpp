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

using namespace std;
using namespace atcoder;

using ull=unsigned long long;
using ll=long long;
//using mint = modint998244353;
//using mint = modint1000000007;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int H, W;
struct Node{int i, j;};
struct N{int i, j, cnt;};

bool check(const Node &next) {
	if (next.i >= 0 && next.i < H && next.j >= 0 && next.j < W) return true;
	else return false;
}

int main() {
	int Ch, Cw, Dh, Dw; cin >> H >> W >> Ch >> Cw >> Dh >> Dw;
	Ch--; Cw--; Dh--; Dw--;
	vector<string> S(H);
	rep(i,H) cin >> S[i];

	vector<vector<Node>> blocks;
	vector<Node> move = {{0,-1},{0,1},{-1,0},{1,0}};
	vector<vector<bool>> seen(H,vector<bool>(W,false));
	int s_blks, g_blks;
	rep(i,H) {
		rep(j,W) {
			if (S[i][j] == '#' || seen[i][j]) continue;
			vector<Node> block = {{i,j}};
			queue<Node> que; que.push({i,j});
			seen[i][j] = true;
			while (!que.empty()) {
				Node tmp = que.front(); que.pop();
				for (auto m : move) {
					Node next = {tmp.i+m.i,tmp.j+m.j};
					if (check(next) && S[next.i][next.j] == '.' && !seen[next.i][next.j]) {
						que.push(next);
						seen[next.i][next.j] = true;
						block.push_back(next);
					}
				}
			}
			blocks.push_back(block);
		}
	}

	vector<vector<int>> num(H,vector<int>(W,-1));
	int n = 0;
	for (auto &v : blocks) {
		for (auto &vv : v) {
			num[vv.i][vv.j] = n;
			if (vv.i == Ch && vv.j == Cw) s_blks = n;
			if (vv.i == Dh && vv.j == Dw) g_blks = n;
		}
		n++;
	}
	if (s_blks == g_blks) {
		cout << 0 << endl;
		return 0;
	}

	queue<N> q;
	vector<bool> vis(blocks.size(),false); vis[s_blks] = true;
	for (const auto &vv : blocks[s_blks]) q.push({vv.i,vv.j,0});
	while (!q.empty()) {
		N tmp = q.front(); q.pop();
		repp(i,-2,3) {
			repp(j,-2,3) {
				Node next = {tmp.i+i, tmp.j+j};
				if(check(next) && S[next.i][next.j] == '.' && !vis[num[next.i][next.j]]) {
					if (num[next.i][next.j] == g_blks) { cout << tmp.cnt + 1 << endl; return 0; }
					vis[num[next.i][next.j]] = true;
					for (auto &b : blocks[num[next.i][next.j]]) q.push({b.i,b.j,tmp.cnt+1});
				}
			}
		}
	}
	cout << -1 << endl;
	return 0;
}