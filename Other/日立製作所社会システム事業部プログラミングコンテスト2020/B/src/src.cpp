#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int A, B, M;
	cin >> A >> B >> M;
	vector<int> a(A), b(B);
	vector<vector<int>> xyc(M, vector<int>(3));
	rep(i,A) cin >> a[i];
	rep(i,B) cin >> b[i];
	rep(i,M) rep(j,3) cin >> xyc[i][j];

	int min_num = *min_element(a.begin(),a.end()) + *min_element(b.begin(),b.end());
	rep(i,M) {
		int cost = a[xyc[i][0]-1] + b[xyc[i][1]-1] - xyc[i][2];
		if (cost < min_num) min_num = cost;
	}
	cout << min_num << endl;

	return 0;
}