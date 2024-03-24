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

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

struct Node{int y, x;};

int ans = 0;
int H, W, N, M; 
vector<vector<bool>> light, block, seen;

bool check(int y, int x) {
	if (x >= 0 && x < W && y >= 0 && y < H) return true;
	else return false;
}

void dfs(const vector<Node> &move, Node dir, int y, int x) {
	light[y][x] = false;
	if (!seen[y][x]) ans++, seen[y][x] = true;
	for (auto m : move) {
		if ((m.y == dir.y && m.x == dir.x) || (m.y == -dir.y && m.x == -dir.x)) continue;
		int y_dash = y + m.y, x_dash = x + m.x;
		while (check(y_dash,x_dash) && !block[y_dash][x_dash]) {
			if (!seen[y_dash][x_dash]) ans++, seen[y_dash][x_dash] = true;
			if (light[y_dash][x_dash]) dfs(move,m,y_dash,x_dash);
			y_dash += m.y, x_dash += m.x;
		}
	}
}

int main() {
	cin >> H >> W >> N >> M;
	vector<int> A(N), B(N), C(M), D(M);
	light = vector<vector<bool>>(H,vector<bool>(W,false));
	block = vector<vector<bool>>(H,vector<bool>(W,false));
	seen = vector<vector<bool>>(H,vector<bool>(W,false));
	rep(i,N) { 
		cin >> A[i] >> B[i]; A[i]--; B[i]--;
		light[A[i]][B[i]] = true;
	}
	rep(i,M) { 
		cin >> C[i] >> D[i]; C[i]--; D[i]--;
		block[C[i]][D[i]] = true;
	}

	vector<Node> move = {{-1,0},{1,0},{0,-1},{0,1}};
	rep(i,N) {
		int y = A[i], x = B[i];
		if (!light[y][x]) continue;
		dfs(move,{0,0},y,x);
	}
	cout << ans << endl;

	return 0;
}