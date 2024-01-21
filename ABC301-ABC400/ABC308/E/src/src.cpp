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
	int N;
	cin >> N;
	vector<int> A(N);
	rep(i,N) cin >> A[i];
	string S;
	cin >> S;

	vector<vector<ll>> m(N,vector<ll>(3,0)), e(N,vector<ll>(9,0)), x(N,vector<ll>(27,0));
	if (S[0] == 'M') m[0][A[0]] = 1;
	repp(i,1,N) {
		rep(j,3) {
			m[i][j] = m[i-1][j];
			rep(k,3) {
				e[i][j*3+k] = e[i-1][j*3+k];
				rep(l,3) {
					x[i][j*9+k*3+l] = x[i-1][j*9+k*3+l];
				}
			}
		}

		if (S[i] == 'M') {
			m[i][A[i]] += 1;
		} else if (S[i] == 'E') {
			rep(j,3) {
				if (m[i-1][j] != 0) {
					//rep(k,3) {
					e[i][j*3+A[i]] += m[i-1][j];
					//}
				}
			}
		} else if (S[i] == 'X') {
			rep(j,3) {
				rep(k,3) {
					if (e[i-1][j*3+k] != 0) {
						x[i][j*9+k*3+A[i]] += e[i-1][j*3+k];
					}
				}
			}
		}
	}

	ll ans = 0;
	rep(i,3) {
		rep(j,3) {
			rep(k,3) {
				if (x[N-1][i*9+j*3+k] > 0) {
					vector<bool> c(4,false);
					c[i] = true; c[j] = true; c[k] = true;
					rep(l,4) { if (!c[l]) { ans += ((ll)x[N-1][i*9+j*3+k] * (ll)l); break; }}
				}
			}
		}
	}
	cout << ans << endl;

	return 0;
}