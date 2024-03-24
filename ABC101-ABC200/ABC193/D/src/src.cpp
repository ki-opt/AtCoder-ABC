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
#include <limits>
#include "atcoder/all"

using namespace std;
using namespace atcoder;

using ull=unsigned long long;
using ll=long long;
//using mint = modint998244353;
//using mint = modint1000000007;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

struct Node {
	vector<ll> card;
	ll num;
};

int main() {
	ll K;
	string S, T;
	cin >> K >> S >> T;
	Node takahashi, aoki;
	takahashi.card = vector<ll>(10,0); aoki.card = vector<ll>(10,0);
	rep(i,S.size()-1) {
		takahashi.card[S[i]-'0']++;
		aoki.card[T[i]-'0']++;
	}

	vector<ll> total(10,0);
	repp(i,1,10) total[i] = K - takahashi.card[i] - aoki.card[i];

	double ans = 0;
	// 高橋first
	repp(i,1,10) {
		if (total[i] <= 0) continue;
		takahashi.card[i]++, takahashi.num = 0;
		repp(j,1,10) takahashi.num += j * (ll)pow(10,takahashi.card[j]);
		double t = (double)total[i] / (double)(9 * K - 8);
		total[i]--;

		repp(j,1,10) {
			if (total[j] <= 0) continue;
			aoki.card[j]++, aoki.num = 0;
			repp(k,1,10) aoki.num += k * (ll)pow(10,aoki.card[k]);
			double a = (double)total[j] / (double)(9 * K - 9);
			aoki.card[j]--;
			if (takahashi.num > aoki.num) ans += 0.5 * t * a;
		}

		total[i]++; takahashi.card[i]--;
	}

	// 青木first
	repp(i,1,10) {
		if (total[i] <= 0) continue;
		aoki.card[i]++, aoki.num = 0;
		repp(j,1,10) aoki.num += j * (ll)pow(10,aoki.card[j]);
		double t = (double)total[i] / (double)(9 * K - 8);
		total[i]--;

		repp(j,1,10) {
			if (total[j] <= 0) continue;
			takahashi.card[j]++, takahashi.num = 0;
			repp(k,1,10) takahashi.num += k * (ll)pow(10,takahashi.card[k]);
			double a = (double)total[j] / (double)(9 * K - 9);
			takahashi.card[j]--;
			if (takahashi.num > aoki.num) ans += 0.5 * t * a;
		}

		total[i]++; aoki.card[i]--;
	}
	printf("%.16f\n",ans);


	/*
	ll t = 0, a = 0;
	ll c_t_total = 0, c_a_total = 0;
	repp(i,1,10) {
		t += i * (ll)pow(10,c_t[i]);
		a += i * (ll)pow(10,c_a[i]);
		c_t[i] = K - c_t[i];
		c_a[i] = K - c_a[i];
		c_t_total += c_t[i];
		c_a_total += c_a[i];
	}

	double ans = 0;
	repp(i,1,10) {
		double tmp_a = (double)c_a[i] / (double)c_a_total, tmp_t;
		ll a_val = a + 
		ans += tmp_a * tmp_t;
	}
	*/

	return 0;
}