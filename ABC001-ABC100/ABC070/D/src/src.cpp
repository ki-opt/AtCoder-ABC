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

struct NextCost{
	ll next, cost;
};


int main() {
	ll N;
	cin >> N;
	vector<ll> a(N-1), b(N-1), c(N-1);
	vector<vector<NextCost>> w(N+1);
	rep(i,N-1) {
		cin >> a[i] >> b[i] >> c[i];
		w[a[i]].push_back({b[i],c[i]});
		w[b[i]].push_back({a[i],c[i]});
	}
	ll Q, K;
	cin >> Q >> K;
	vector<ll> x(Q), y(Q);
	rep(i,Q) cin >> x[i] >> y[i];
	
	vector<ll> dist(N+1,LLONG_MAX);
	//dist[K] = 0;
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pque;
	pque.emplace(0,K);
	dist[K] = 0;
	while(!pque.empty()) {
		ll d = pque.top().first;
		ll v = pque.top().second;
		pque.pop();

		if (d > dist[v]) continue;
		for (const auto &next_cost : w[v]) {
			ll next_dist = d + next_cost.cost;
			if (next_dist < dist[next_cost.next]) {
				dist[next_cost.next] = next_dist;
				pque.emplace(next_dist, next_cost.next);
			}
		}		
	}

	rep(i,Q) {
		cout << dist[x[i]] + dist[y[i]] << endl;
	}

	return 0;
}