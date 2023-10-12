#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>

using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	ll N;
	cin >> N;
	vector<ll> A(N+1);
	A[0] = 0;
	repp(i,1,N+1) { cin >> A[i]; }
	A.push_back(0);

	ll ans = 0;
	rep(i,N+1) ans += abs(A[i] - A[i+1]); 

	rep(i,N) {
		ll tmp = ans - abs(A[i]-A[i+1]) - abs(A[i+1]-A[i+2]);
		tmp += abs(A[i+2]-A[i]);
		cout << tmp << endl;
	}

	return 0;
}