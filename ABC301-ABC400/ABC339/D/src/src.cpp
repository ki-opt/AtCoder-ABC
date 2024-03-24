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
	int N; cin >> N;
	vector<string> S(N+2);
	string tmp;
	rep(i,N+2) tmp += '#';
	S[0] = tmp;
	S[N+1] = tmp;
	vector<int> p = {-1,-1, -1,-1};
	repp(i,1,N+1) {
		cin >> tmp;
		S[i] = '#' + tmp + '#';
		rep(j,N+2) if (S[i][j] == 'P') {
			if (p[0] == -1 && p[1] == -1) p[0] = i, p[1] = j;
			else p[2] = i, p[3] = j;
		}
	}
	
	vector<pair<int,int>> dydx = {{-1,0},{1,0},{0,1},{0,-1}};
	queue<vector<int>> que;
	int N_dash = N + 2;
	vector dist(N_dash,vector(N_dash,vector(N_dash,vector(N_dash,-1))));
	dist[p[0]][p[1]][p[2]][p[3]] = 0;
	que.push(p);
	while (!que.empty()) {
		vector<int> tmp = que.front(); que.pop();
		for (auto m : dydx) {
			vector<int> next = tmp;
			next[0] += m.first; next[1] += m.second;
			next[2] += m.first; next[3] += m.second;
			if (S[next[0]][next[1]] == '#') next[0] = tmp[0], next[1] = tmp[1];	
			if (S[next[2]][next[3]] == '#') next[2] = tmp[2], next[3] = tmp[3];
			if (dist[next[0]][next[1]][next[2]][next[3]] == -1) {
				dist[next[0]][next[1]][next[2]][next[3]] = dist[tmp[0]][tmp[1]][tmp[2]][tmp[3]] + 1;
				que.push(next);
			}
		}
	}
	int ans = INT_MAX;
	repp(i,1,N+1) repp(j,1,N+1) {
		if (dist[i][j][i][j] != -1) ans = min(ans,dist[i][j][i][j]);
	}
	cout << (ans == INT_MAX ? -1 : ans) << endl;

	return 0;
}