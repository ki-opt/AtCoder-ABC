#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int N;
	cin >> N;
	vector<double> v(N);
	rep(i,N) cin >> v[i];

	sort(v.begin(),v.end());
	rep(i,N-1) {
		double ans = (v[0] + v[1]) / 2.0;
		v.erase(v.begin());
		v.erase(v.begin());
		v.push_back(ans);
		sort(v.begin(),v.end());
	}

	cout << v[0] << endl;

	return 0;
}