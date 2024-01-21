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
