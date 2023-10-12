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
	int N, M;
	cin >> N >> M;
	vector<pair<long int,long int>> AB(N);
	rep(i,N) {
		long int a, b;
		cin >> a >> b;
		AB[i] = make_pair(a,b);
	}
	sort(AB.begin(),AB.end());

	long int ans = 0;
	long int m = 0;
	rep(i,N) {
		if (m + AB[i].second >= M) {
			ans += AB[i].first * (M - m);
			break;
		}
		m += AB[i].second;
		ans += AB[i].first * AB[i].second;
	}
	cout << ans << endl;

	return 0;
}