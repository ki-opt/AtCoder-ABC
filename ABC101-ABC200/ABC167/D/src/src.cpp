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

int main() {
	ll N, K; cin >> N >> K;
	vector<ll> A(N);
	rep(i,N) {
		cin >> A[i];
		A[i]--;
	}

	int cnt = 0, pos = 0;
	vector<bool> seen(N,false);
	while(!seen[pos]) {
		seen[pos] = true;
		pos = A[pos];
		cnt++;
		if (cnt == K) {
			cout << pos + 1 << endl;
			return 0;
		}
	}
	if (A[pos] == pos) {
		cout << pos + 1 << endl;
		return 0;
	}
	K -= cnt;
	
	cnt = 0;
	seen = vector<bool>(N,false);
	while(!seen[pos]) seen[pos] = true, pos = A[pos], cnt++;

	ll amari = K % cnt;
	rep(i,amari) pos = A[pos];
	cout << pos + 1 << endl;
	return 0;
}