#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, A, B;
	cin >> N >> A >> B;
	int sum = A + B;
	vector<int> C(N);
	for (int i = 0; i < N; i++) {
		cin >> C[i];
		if (C[i] == sum) {
			cout << i + 1 << endl;
			break;
		}
	}


	return 0;
}