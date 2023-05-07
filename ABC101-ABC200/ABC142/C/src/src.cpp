#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int N;
	cin >> N;
	vector<pair<int,int>> A(N);
	rep(i,N) {
		int tmp;
		cin >> tmp;
		A[i] = make_pair(tmp,i);
	}

	sort(A.begin(), A.end());

	rep(i,N) {
		cout << A[i].second + 1 << " ";
	}
	cout << endl;

	return 0;
}