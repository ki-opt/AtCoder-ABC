#include <iostream>
#include <vector>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	string a, b;
	cin >> a >> b;
	int num = stoi(a + b);
	
	for (int i = 1; i < num; i++) {
		if (i * i == num) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}