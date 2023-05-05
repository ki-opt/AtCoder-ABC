#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;

	int X = 0;
	for (int i = 1; i <= N; i++) {
		if (N == int((double)i * 1.08)) {
			X = i;
			break;
		}
	}
	if (X == 0) cout << ":(" << endl;
	else cout << X << endl;

	return 0;
}