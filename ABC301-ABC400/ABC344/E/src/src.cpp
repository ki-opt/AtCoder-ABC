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
	vector<Node> vec;
	// コンストラクタ1
	bidirectional_list() { }
	// コンストラクタ2
	bidirectional_list(const vector<ll> &A) {
		ll N = A.size();
		vec.resize(N);
		rep(i,N) {
			if (i != N-1) vec[i] = {A[i],i-1,i+1};
			else vec[i] = {A[i],i-1,-1};
		}
	}

	// cur_indexの次にvalを挿入
	void insert(ll cur_index, ll val) {
		// vectorが空のとき
		if (vec.size() == 0) {
			vec.push_back({val,-1,-1});
		// 先頭への要素の追加
		} else if (cur_index == -1) {
			vec[0].prev = vec.size();
			vec.push_back({val,-1,0});
		// 先頭以外への要素の追加
		} else {
			ll next_index = vec[cur_index].next, last_index = vec.size();
			vec.push_back({val,cur_index,next_index});
			vec[cur_index].next = last_index;
			if (next_index != -1) vec[next_index].prev = last_index;
		}
	}
	// cur_indexを削除
	void erase(ll cur_index) {
		ll next_index = vec[cur_index].next, prev_index = vec[cur_index].prev;
		if (next_index != -1) vec[next_index].prev = prev_index;
		if (prev_index != -1) vec[prev_index].next = next_index;
		vec[cur_index] = {-1,-1,-1};
	}
	// serach first index
	ll search_first_index() {
		ll start_index;
		rep(i,vec.size()) {
			Node n = vec[i];
			if (n.v != -1 && n.prev == -1) start_index = i;
		}
		return start_index;
	}
};


int main() {
	ll N; cin >> N;
	vector<ll> A(N);
	rep(i,N) cin >> A[i];

	unordered_map<ll,ll> umap;
	bidirectional_list bl(A);
	rep(i,N) umap[A[i]] = i;

	ll Q; cin >> Q;
	rep(i,Q) {
		ll q;
		cin >> q;
		if (q == 1) {
			ll x, y; cin >> x >> y;
			bl.insert(umap[x],y);
			umap[y] = bl.vec.size()-1;
		} else {
			ll x; cin >> x;
			bl.erase(umap[x]);
		}
	}

	ll start_index = bl.search_first_index();
	
	Node n = bl.vec[start_index];
	while (true) {
		cout << n.v << " ";
		if (n.next == -1) break;
		n = bl.vec[n.next];
	}
	cout << endl;

	return 0;
}