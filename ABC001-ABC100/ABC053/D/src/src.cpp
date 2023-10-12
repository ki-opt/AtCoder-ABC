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
	vector<ll> A_cnt((ll)pow(10,5)+1,0);
	rep(i,N) {
		cin >> A[i];
		A_cnt[A[i]]++;
	}

	int kisu = 0, gusu = 0;
	sort(A_cnt.begin(),A_cnt.end(),greater<ll>());
	rep(i,A_cnt.size()) {
		if (A_cnt[i] == 0) break;
		if (A_cnt[i] % 2 == 1) kisu++;
		else gusu++;
	}
	int ans = gusu + kisu;
	if (gusu % 2 == 1) ans--;
	/*
	int index = 1;
	sort(A_cnt.begin(),A_cnt.end(),greater<ll>());
	rep(i,A_cnt.size()) {
		if (A_cnt[i] <= 1) continue;
		index = i + 1;
		while(A_cnt[i] > 1) {
			if (A_cnt[i] == 2) {
				A_cnt[i] = 1;
				A_cnt[index]--;
				break;
			} else if (A_cnt[i] > 2) {
				A_cnt[i] -= 2;
			}
		}
	}

	ll ans = 0;
	rep(i,A_cnt.size()) {
		if (A_cnt[i] == 1) ans++;
		//else (A_cnt[i])
	}*/
	cout << ans << endl;

	return 0;
}
