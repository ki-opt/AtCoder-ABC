#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	long int N;
	cin >> N;
	vector<int> d(N);
	rep(i,N) cin >> d[i];

	sort(d.begin(),d.end());
	int start = d[N/2-1];
	int end = d[N/2];

	cout << end - start << endl;
	return 0;
}