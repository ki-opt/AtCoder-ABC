//https://qiita.com/0xkei10/items/807ff3c78857fd3017b1

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <queue>
#include <string.h>

using ull=unsigned long long;
using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

class Dinic {
public:
	struct Edge { int to, cap, rev; };
	vector<vector<Edge>> G;
	vector<int> level, iter;
	int max_v;

	Dinic(const int &max_v) : max_v(max_v) {
		G = vector<vector<Edge>>(max_v);
		level = vector<int>(max_v,-1);
		iter = vector<int>(max_v,0);
	}

	void add_edge(int from, int to, int cap) {
		G[from].push_back(Edge{to,cap,(int)G[to].size()});
		G[to].push_back(Edge{from,0,(int)G[from].size()-1});
	}

private:
	void bfs(int s) {
		queue<int> que;
		que.push(s); level[s] = 0;
		while (!que.empty()) {
			int v = que.front(); que.pop();
			for (auto e : G[v]) {
				if (e.cap > 0 && level[e.to] < 0) {
					level[e.to] = level[v] + 1;
					que.push(e.to);
				}
			}
		}
	}

	int dfs(int v, const int t, int f) {
		if (v == t) return f;	// toへ到達
		for (int &i = iter[v]; i < G[v].size(); i++) {
			Edge &e = G[v][i];
			if (e.cap > 0 && level[v] < level[e.to]) {
				int d = dfs(e.to, t, min(f,e.cap));
				if (d > 0) {
					e.cap -= d;
					G[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}

public:
	int maximum_flow(int s, int t) {
		int flow = 0;
		while (true) {
			for (int i = 0; i < max_v; i++) level[i] = -1;
			bfs(s);
			if (level[t] < 0) return flow;
			for (int i = 0; i < max_v; i++) iter[i] = 0;
			int f = dfs(s,t,1e9);
			while (f > 0) { 
				flow += f;
				f = dfs(s,t,1e9);
			}
		}
	}
};

void func() {
	int V, E;
	cin >> V >> E;
	vector<int> u(E), v(E), c(E);
	Dinic dinic(V);
	rep(i,E) {
		cin >> u[i] >> v[i] >> c[i];
		dinic.add_edge(u[i],v[i],c[i]);	
	}
	cout << dinic.maximum_flow(0,V-1) << endl;
}

int main() {
	int N;
	cin >> N;
	vector<int> a(N), b(N), c(N), d(N);
	rep(i,N) cin >> a[i] >> b[i];
	rep(i,N) cin >> c[i] >> d[i];

	Dinic dinic(2*N+2);
	// source to node-i
	rep(i,N)	dinic.add_edge(2*N,i,1);
	rep(i,N) {
		rep(j,N) {
			if (a[i] < c[j] && b[i] < d[j]) {
				// node-i to node-j
				dinic.add_edge(i,N+j,1);
			}
		}
	}
	// node-j to sink
	rep(j,N) dinic.add_edge(N+j,2*N+1,1);

	int ans;
	ans = dinic.maximum_flow(2*N,2*N+1);
	cout << ans << endl;
	
	return 0;
}