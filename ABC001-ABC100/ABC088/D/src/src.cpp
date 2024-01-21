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

struct Node{
	int i, j;
};
bool node_equal(Node &a, const Node &b) {
	return a.i == b.i && a.j == b.j;
}

int main() {
	int H, W;
	cin >> H >> W;
	vector<string> s(H+2);
	string s_tmp;
	rep(i,W+2) { s_tmp += '#'; }
	s[0] = s_tmp;
	s[H+1] = s_tmp;
	int black = 0;
	repp(i,1,H+1) {
		cin >> s[i];
		s[i] = '#' + s[i] + '#';
		repp(j,1,W+1) {
			if (s[i][j] == '#') {
				black++;
			}
		}
	}

	vector<Node> dir = { {-1,0},{1,0},{0,-1},{0,1}};
	queue<Node> que;
	que.push({1,1});
	vector<vector<Node>> seen(H+2,vector<Node>(W+2,{-1,-1}));
	vector<vector<int>> num(H+2,vector<int>(W+2,0));
	seen[1][1] = {1,1};
	while (!que.empty()) {
		Node tmp = que.front(); que.pop();
		if (tmp.i == H && tmp.j == W) break;
		for (auto d : dir) {
			Node next = {tmp.i+d.i,tmp.j+d.j};
			if (!node_equal(seen[next.i][next.j],Node{-1,-1}) ||
				s[next.i][next.j] == '#') continue;
			que.push(next);
			seen[next.i][next.j] = tmp;
			num[next.i][next.j] = num[tmp.i][tmp.j] + 1;
		}
	}
	if (node_equal(seen[H][W],Node{-1,-1})) cout << -1 << endl;
	else cout << H * W - black - (num[H][W]+1) << endl;
	return 0;
}