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

long int gcd(long int a, long int b) {
	if (b == 0) {
		return a;
	} else {
		return gcd(b, a % b);
	}
}

int main() {
	long int N, X;
	cin >> N >> X;
	vector<long int> x(N);
	rep(i,N) cin >> x[i];

	if (N == 1) {
		cout << abs(x[0] - X) << endl;
	} else {
		long int tmp = gcd(abs(X-x[0]),abs(X-x[1]));
		repp(i,N,2) {
			tmp = gcd(tmp,abs(X-x[i]));
		}	
		cout << tmp << endl;
	}

	/*sort(x.begin(),x.end());
	if (N == 1) {
		cout << abs(x[0] - X) << endl;
	} else if (X < x[0]) {
		cout << x[0] - X << endl;
	} else if (X > x[x.size()-1]) {
		cout << X - x[x.size()-1] << endl;
	} else {
		int index = upper_bound(x.begin(), x.end(), X) - x.begin();

		int diff = x[index] - X;
		int diff_2 = X - x[index-1];

		int D = min(diff,diff_2);
		cout << D << endl;	
	}*/

	return 0;
}