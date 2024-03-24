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

struct Node{ ll v, prev, next; };
struct bidirectional_list {
	

	void insert() {

	}
	void erase() {

	}
};


int main() {
	ll N; cin >> N;
	vector<ll> A(N);
	rep(i,N) cin >> A[i];

	unordered_map<ll,ll> umap;
	vector<Node> list(N,{-1,-1});
	rep(i,N) {
		umap[A[i]] = i;
		if (i != N-1) list[i] = {A[i],i-1,i+1};
		else list[i] = {A[i],i-1,-1};
	}

	ll Q; cin >> Q;
	rep(i,Q) {
		ll q;
		cin >> q;
		if (q == 1) {
			ll x, y; cin >> x >> y;
			/////////////			
			ll cur_index = umap[x], next_index = list[umap[x]].next, 
				last_index = list.size();
			list.push_back({y,cur_index,next_index});
			list[cur_index].next = last_index;
			if (next_index != -1) list[next_index].prev = last_index;
			umap[y] = last_index;
			/////////////
		} else {
			ll x; cin >> x;
			/////////////
			ll cur_index = umap[x], next_index = list[umap[x]].next,
				prev_index = list[umap[x]].prev;
			if (next_index != -1) list[next_index].prev = prev_index;
			if (prev_index != -1) list[prev_index].next = next_index;
			list[cur_index] = {-1,-1,-1};
			/////////////
		}
	}

	ll start_index;
	rep(i,list.size()) {
		Node n = list[i];
		if (n.v != -1 && n.prev == -1) start_index = i;
	}
	
	Node n = list[start_index];
	while (true) {
		cout << n.v << " ";
		if (n.next == -1) break;
		n = list[n.next];
	}
	cout << endl;

	/*
	map<ll,ll> mp;
	rep(i,N) {
		cin >> A[i];
		mp[A[i]] = i;
	}

	vector<ll> erase;
	ll Q; cin >> Q;
	rep(i,Q) {
		ll q;
		cin >> q;
		if (q == 1) {
			ll x, y; cin >> x >> y;
			auto itr = mp.lower_bound(x);
			erase.push_back(itr->second+2);
			mp[y] = itr->second + 1;
		} else {
			ll x; cin >> x;
			mp.erase(x);
		}
	}

	vector<pair<ll,ll>> pairs;
	for (auto m : mp) {
		pairs.push_back({m.second,m.first});
	}

	sort(pairs.begin(),pairs.end());
	for(auto p : pairs) cout << p.second << " ";
	cout << endl;*/

	return 0;
}