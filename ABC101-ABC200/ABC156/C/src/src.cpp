#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> X(N);
	for (int i = 0; i < N; i++) cin >> X[i];

	int max_val = INT_MAX;
	int P = 1;
	while(1) {
		int sum = 0;
		for (int i = 0; i < N; i++) {
			sum += (X[i] - P) * (X[i] - P);
		}
		if (sum < max_val) {
			max_val = sum;
			P++;
		} else {
			break;
		}
	}
	cout << max_val << endl;

	return 0;
}