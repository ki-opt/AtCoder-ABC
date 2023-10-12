#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>

using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, limit, init) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	long int N;
	cin >> N;
	vector<long int> A(N);
	rep(i,N) cin >> A[i];
	long int Q;
	cin >> Q;
	vector<long int> l(Q), r(Q);
	rep(i,Q) cin >> l[i] >> r[i];

	vector<long int> suimin(N);
	rep(i,N) {
		if (i == 0) suimin[i] = 0;
		else {
			if (i % 2 == 1) suimin[i] = suimin[i-1];
			else suimin[i] = suimin[i-1] + (A[i] - A[i-1]);
		}
      //cout << suimin[i] << endl;
	}

	long int ans = 0;
	rep(i,Q) {
		auto pos_l = upper_bound(A.begin(),A.end(),l[i]) - A.begin();
		auto pos_q = upper_bound(A.begin(),A.end(),r[i]) - A.begin() - 1;
		//cout << pos_l << " " << pos_q << endl;
		ans = suimin[pos_q] - suimin[pos_l];
		//cout << ans << endl;
    	if (pos_l % 2 == 0) ans += A[pos_l] - l[i];
		if (pos_q % 2 == 1) ans += r[i] - A[pos_q];
		cout << ans << endl;
	}
	return 0;
}