#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int N;
	cin >> N;

	if (N == 1) {
		cout << 1 << endl;
		return 0;
	}

	vector<int> cnt(N,0);
	for (int n = 1; n <= N; n++) {
		int wrk = n;
		while(1) {
			if (wrk % 2 == 0) {
				wrk = wrk / 2;
				cnt[n-1]++;
			} else {
				break;
			}
		}
	}

	int max = 0;
	rep(i,N) {
		if (cnt[i] > max) max = cnt[i];
	}
	cout << int(pow(2, max)) << endl;
	return 0;
}