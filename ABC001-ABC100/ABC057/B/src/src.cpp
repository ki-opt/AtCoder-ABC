#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>

using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, limit, init) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> a(N), b(N);
	rep(i,N) cin >> a[i] >> b[i];
	vector<int> c(M), d(M);
	rep(i,M) cin >> c[i] >> d[i];

	rep(i,N) {
		int index;
		long int dist = LLONG_MAX;
		rep(j,M){
			long int tmp = abs(a[i]-c[j]) + abs(b[i]-d[j]);
			if (tmp < dist) {
				dist = tmp;
				index = j;
			}
		}
		cout << index + 1 << endl;
	}

	return 0;
}