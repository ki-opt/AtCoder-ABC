#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int N;
	cin >> N;
	vector<int> a(N);
	rep(i,N) cin >> a[i];

	vector<int> check(N,0);
	int next = a[0] - 1;
	int cnt = 1;
	while(1) {
		if (next + 1 == 2) {
			cout << cnt << endl;
			return 0;
		}
		if (check[a[next]-1] == 0) {
			check[a[next]-1] = 1;
			next = a[next] - 1;
			cnt++;
		} else {
			cout << -1 << endl;
			return 0;
		}
	}

	return 0;
}