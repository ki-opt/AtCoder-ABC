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
	long int N, M;
	cin >> N;
	vector<long int> D(N);
	rep(i,N) cin >> D[i];
	cin >> M;
	vector<long int>T(M);
	rep(i,M) cin >> T[i];

	sort(D.begin(),D.end());
	sort(T.begin(),T.end());

	int cnt = 0;
	rep(i,M) {
		while(D[cnt] < T[i]) {
			cnt++;
		}
		if (D[cnt] == T[i]) {
			cnt++;
		}
		else {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;

	return 0;
}