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

ll gcd(ll a, ll b) {
	if(a%b == 0){
		return b;
	}else{
		return gcd(b, a%b);
	}
}

ll lcm(ll a, ll b) {
	return a * b / gcd(a,b);
}

int main() {
	ll N;
	cin >> N;
	vector<ll> T(N), A(N);
	rep(i,N) cin >> T[i] >> A[i];

	ll t = 1, a = 1;
	rep(i,N) {
		ll n = max(t/T[i] + (t % T[i] ? 1 : 0), a/A[i] + (a % A[i] ? 1 : 0));
		t = n * T[i];
		a = n * A[i];
	}
	cout << t + a << endl;
	return 0;
}