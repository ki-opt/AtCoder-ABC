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

int main() {
	int N, M, Q; cin >> N >> M >> Q;
	vector<ll> W(N), V(N);
	rep(i,N) cin >> W[i] >> V[i];
	vector<ll> X(M);
	rep(i,M) cin >> X[i];

	ll MAX_VAL = 1e6+1;
	mcf_graph<ll,ll> graph(N+M+2);
	rep(i,N) {
		graph.add_edge(0,i+1,1,0);
		rep(j,M) {
			if (W[i] > X[j]) {
				//graph.add_edge(i+1,N+(j+1),0,MAX_VAL);
				continue;
			} else {
				graph.add_edge(i+1,N+(j+1),1,MAX_VAL-V[i]);
			}
		}
	}
	
	vector<ll> ans;
	rep(q,Q) {
		ll L, R; cin >> L >> R;
		mcf_graph<ll,ll> graph_tmp = graph;
		rep(i,M) {
			if (i + 1 >= L && i + 1 <= R) {
				//graph_tmp.add_edge(N+i+1,N+M+1,1,MAX_VAL);
				continue;
			} else {
				graph_tmp.add_edge(N+i+1,N+M+1,1,0);
			}
		}
		auto [flow, cost] = graph_tmp.flow(0,N+M+1);
		ans.push_back(MAX_VAL * flow - cost);
	}

	for (auto a : ans) {
		cout << a << endl;
	}

	return 0;
}