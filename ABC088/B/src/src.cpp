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

	sort(a.begin(),a.end(),greater<int>());
	int alice = 0, bob = 0;
	rep(i,N) {
		if (i % 2 == 0) alice += a[i];
		else bob += a[i];
	}
	cout << alice - bob << endl;

	return 0;
}