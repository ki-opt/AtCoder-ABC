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

int main() {
	string S;
	ll N;
	cin >> S >> N;

	ll ans = 0;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == '1') ans += (ll)1 << (S.size()-1-i);
	}
	if (ans > N) { cout << -1 << endl; return 0; }

	for (int i = 0; i < S.size(); i++) {
		if (S[i] == '?') {
			//ll tmp = 1;
			//rep(j,S.size()-i-1) tmp *= 2;
			ll tmp = (ll)1 << (ll)(S.size()-1-i);
			if (ans + tmp > N) continue;
			ans += tmp;
		}
	}
	cout << ans << endl;


	/*
	queue<ll> que;
	que.push(ans);
	for (int i = 0; i < S.size(); i++) {
		queue<ll> que_tmp = que;
		if (S[i] == '?') {
			while(!que_tmp.empty()) {
				ll val = que_tmp.front();
				que_tmp.pop();
				val += (ll)pow(2,S.size()-i-1);
				if (val > N) continue;
				ans = max(ans,val);
				que.push(val);
			}
		}
	}
	*/
	return 0;
}