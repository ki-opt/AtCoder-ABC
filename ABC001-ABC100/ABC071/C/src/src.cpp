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
	vector<ll> A(N);
	rep(i,N) cin >> A[i];

	sort(A.begin(),A.end(),greater<ll>());
	ll tate = -1, yoko = -1;
	repp(i,0,N-1) {
		if (tate == -1 && A[i] == A[i+1]) {
			tate = A[i];
			i++;
		} else if (tate != -1 && A[i] == A[i+1]) {
			yoko = A[i];
			break;
		}
	}
	if (tate != -1 && yoko != -1) {
		cout << tate * yoko << endl;
	} else {
		cout << 0 << endl;
	}

	return 0;
}