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
#include <math.h>
#include <float.h>
#include "atcoder/all"

using namespace std;
using namespace atcoder;

using ull=unsigned long long;
using ll=long long;
//using mint = modint998244353;
//using mint = modint1000000007;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

struct Node{
	ll i, t, a, x;
	bool operator>(const Node &another) const {
		return i > another.i;
	}
};

int main() {
	ll H, W, M; cin >> H >> W >> M;

	vector<Node> vec(M);
	ll max_x = 0;
	rep(i,M) {
		ll t, a, x; cin >> t >> a >> x;
		a--;
		vec[i] = {i,t,a,x};
		max_x = max(max_x,x);
	}
	sort(vec.begin(),vec.end(),greater<Node>());

	ll h = H, w = W;
	vector<ll> color(max_x+1,0);
	vector<bool> row(H,false), col(W,false);
	rep(i,M) {
		if (vec[i].t == 1) {
			if (row[vec[i].a]) continue;
			color[vec[i].x] += w;
			row[vec[i].a] = true;
			h--;
		} else if (vec[i].t == 2) {
			if (col[vec[i].a]) continue;
			color[vec[i].x] += h;
			col[vec[i].a] = true;
			w--;
		}
	}

	if (h != 0 && w != 0) color[0] += h * w;

	int cnt = 0;
	rep(i,max_x+1) if (color[i] != 0) cnt++;

	cout << cnt << endl;
	rep(i,max_x+1) if (color[i] != 0) cout << i << " " << color[i] << endl;

	return 0;
}