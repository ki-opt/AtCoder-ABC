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
	vector<int> a(N-1), b(N-1);
	vector<vector<int>> g(N,vector<int>());
	rep(i,N-1) {
		cin >> a[i] >> b[i];
		a[i]--; b[i]--;
		g[a[i]].push_back(b[i]);
		g[b[i]].push_back(a[i]);
	}

	queue<int> que;
	vector<int> visited(N,-1);
	visited[0] = 0;
	for (auto n : g[0]) { que.push(n); visited[n] = 0; }
	while (!que.empty()) {
		int tmp = que.front(); que.pop();
		if (tmp == N-1) { break; }
		for (auto n : g[tmp]) {
			if (visited[n] != -1) continue;
			que.push(n);
			visited[n] = tmp;
		}
	}
	vector<int> root = {N-1};
	while (visited[root.back()] != 0) root.push_back(visited[root.back()]);
	root.push_back(0);
	vector<int> root_rev = root;
	reverse(root.begin(),root.end());

	queue<int> f, s;
	vector<bool> seen(N,false);
	
	int next = 0;
	int f_cnt = 0, s_cnt = 0;
	while (true) {
		if (seen[root[next]] || root.size() == next) break;
		seen[root[next]] = true;
		f_cnt++;
		for (auto n : g[root[next]]) f.push(n);
		if (seen[root_rev[next]] || root_rev.size() == next) break;
		seen[root_rev[next]] = true;
		s_cnt++;
		for (auto n : g[root_rev[next]]) s.push(n);
		next++;
	}

	while (!f.empty() || !s.empty()) {
		if (!f.empty()) { 
			int tmp = f.front(); f.pop();
			while (seen[tmp] && !f.empty()) tmp = f.front(), f.pop();
			if (!seen[tmp]) { 
				seen[tmp] = true;
				f_cnt++; 
				for (auto n : g[tmp]) {
					if (seen[n]) continue;
					f.push(n);
				}
			}
		}

		if (!s.empty()) {
			int tmp = s.front(); s.pop();
			while (seen[tmp] && !s.empty()) tmp = s.front(), s.pop();
			if (!seen[tmp]) {
				seen[tmp] = true;
				s_cnt++;
				for (auto n : g[tmp]) {
					if (seen[n]) continue;
					s.push(n);
				}
			}
		}
	}
	if (f_cnt > s_cnt) cout << "Fennec" << endl; 
	else cout << "Snuke" << endl;
}