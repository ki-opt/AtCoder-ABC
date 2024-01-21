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

//using Pair = pair<ll,ll>;

struct Node {
	ll dist;
	ll node; 
	int flag;
};

int main() {
	ll N, A, B, C;
	cin >> N >> A >> B >> C;
	vector<vector<ll>> D(N+1,vector<ll>(N+1));
	rep(i,N) {
		rep(j,N) cin >> D[i+1][j+1];
	}

	queue<Node> que;
	que.push({0,1,0});
	que.push({0,1,1});

	vector<vector<ll>> cost(N+1,vector<ll>(2,LLONG_MAX));
	while (!que.empty()) {
		ll dist = que.front().dist;
		ll from = que.front().node;
		int flag = que.front().flag;
		que.pop();

		repp(to,1,N+1) {
			if (to == from) continue;
			ll syayosya = dist + D[from][to]*A;
			ll densya = dist + D[from][to]*B+C;
			if (flag == 0) {
				if (syayosya < cost[to][0]) {
					cost[to][0] = syayosya;
					que.push({syayosya,to,0});
				}
			}
			if (densya < cost[to][1]) {
				cost[to][1] = densya;
				que.push({densya,to,1});
			}
		}
	}
	ll ans = min(cost[N][0],cost[N][1]);
	cout << ans << endl;

	/*
	priority_queue<Pair,vector<Pair>, greater<Pair>> q;
	q.emplace(0,1);

	vector<vector<ll>> cost(N+1,vector<ll>(2,LLONG_MAX));
	while (!q.empty()) {
		ll dist = q.top().first;
		ll from = q.top().second;
		q.pop();

		repp(to,1,N+1) {
			if (to == from) continue;
			ll tmp = dist + min(D[from][to]*A,D[from][to]*B+C);
			if (tmp < cost[to]) {
				cost[to] = tmp;
				q.emplace(tmp,to);	
			}
		}
	}
	cout << cost[N] << endl;
	*/
	
	return 0;
}