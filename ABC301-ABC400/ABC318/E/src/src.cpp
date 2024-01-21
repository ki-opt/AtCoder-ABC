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
	ll N;
	cin >> N;
	vector<ll> A(N);
	vector<vector<ll>> a(N);
	rep(i,N) {
		cin >> A[i];
		A[i]--;
		a[A[i]].push_back(i);
	}

	ll ans = 0;
	rep(i,N) {
		if (a[i].size() <= 1) continue;
		if (a[i].size() == 2) ans += a[i][1] - a[i][0] - 1;
		rep(j,a[i].size()-1) {
			ans += 
		}

		cerr << "un" << endl;
	}
	
	/*
	rep(i,N) {
		if (a[i].size() <= 1) continue;
		
		vector<ll> tmp(a[i].size()-1,0);
		tmp[0] = a[i][1] - a[i][0] - 2;
		ll total = tmp[0];
		repp(j,1,a[i].size()-1) {
			tmp[j] = (a[i][j+1] - a[i][0] - 2);
			total += tmp[j];
		}
		
		reverse(tmp.begin(),tmp.end());
		ans += tmp[0];
		repp(j,1,a[i].size()-1) {
			ans += tmp[j-1] - tmp[j];
		}
		//if (i == 10) getchar();
	}*/
	cout << ans << endl;

	return 0;
}