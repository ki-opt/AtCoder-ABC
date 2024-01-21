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
	int N, K;
	cin >> N >> K;
	vector<ll> A(K), B;
	//vector<bool> unseen(N,false);
	rep(i,K) {
		cin >> A[i];
		A[i]--;
		//unseen[A[i]] = true;
	}
	//rep(i,N) if (unseen[i]) B.push_back(i);

	ll ans = 0;
	if (K % 2 == 0) {
		for (int i = 0; i < K-1; i+=2) {
			ans += A[i+1] - A[i];
		}
	} else {
		vector<int> tmp(K-1);
		ll kisu = 0, gusu = 0;
		rep(i,K-1) {
			tmp[i] = A[i+1] - A[i];
			if (i % 2 == 1) kisu += tmp[i];
		}
		
		ans = kisu;
		for (int i = 2; i < K; i += 2) {
			kisu -= tmp[i-1];
			gusu += tmp[i-2];
			ans = min(ans,kisu+gusu);
		}
	}
	cout << ans << endl;
	return 0;
}