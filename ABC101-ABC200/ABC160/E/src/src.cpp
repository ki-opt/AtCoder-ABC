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

bool desc_asc(pair<ll,int> &left, pair<ll,int> &right) {
	if (left.first == right.first) {
		return left.second < right.second;
	} else {
		return right.first < left.first;
	}
}

int main() {
	ll X, Y, A, B, C; cin >> X >> Y >> A >> B >> C;
	vector<ll> p(A), q(B), r(C);
	vector<pair<ll,int>> t;
	rep(i,A) cin >> p[i], t.push_back({p[i],0});
	rep(i,B) cin >> q[i], t.push_back({q[i],1});
	rep(i,C) cin >> r[i], t.push_back({r[i],2});
	sort(t.begin(), t.end(), desc_asc);
	int index = 0, x = 0, y = 0, z = 0;
	ll ans = 0;
	while (x < X || y < Y) {
		if (t[index].second == 0) {
			if (x < X) ans += t[index].first, x++; 
		} else if (t[index].second == 1) {
			if (y < Y) ans += t[index].first, y++;
		} else {
			ans += t[index].first;
			z++;
		}
		index++;
		if (x + y + z >= X + Y) break;
	}
	cout << ans << endl;





	/*
	sort(p.begin(),p.end(),greater<ll>());
	sort(q.begin(),q.end(),greater<ll>());
	sort(r.begin(),r.end(),greater<ll>());
	if (X < p.size()) p[X] = -1;
	else p.push_back(-1);
	if (Y < q.size()) q[Y] = -1;
	else q.push_back(-1);
	r.push_back(-1);
	int a = 0, b = 0, c = 0;
	int x = 0, y = 0;
	ll ans = 0;
	while (x < X || y < Y) {
		if (p[a] > q[b])
		if (x < X && (p[a] >= q[b] || r[c] >= q[b])) {
			x++;
			if (p[a] > r[c]) ans += p[a], a++;
			else if (p[a] <= r[c]) ans += r[c], c++;
		} else if (y < Y && (q[b] >= p[a] || r[c] >= p[a])) {
			y++;
			if (q[b] > r[c]) ans += q[b], b++;
			else if (q[b] <= r[c]) ans += r[c], c++;
		} else {
			if (x < X) {
				ans += r[c];
			} else if (y < Y) {
				ans += r[c];
			}
			c++;
		}
	}
	return 0;
	*/
}