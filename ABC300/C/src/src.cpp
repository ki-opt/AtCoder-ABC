#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define TEISU 2*10*10*10*10*10+1

int main() {
	int N, Q;
	cin >> N >> Q;
	
	vector<priority_queue<int, vector<int>, greater<int>>> que_for_query2(N+1);
	vector<priority_queue<int, vector<int>, greater<int>>> que_for_query3(TEISU);

	for (int iter = 0; iter < Q; iter++) {
		int i, j;
		int query_1;
		cin >> query_1;
		if (query_1 == 1) {
			cin >> i >> j;
			que_for_query2[j].push(i);
			que_for_query3[i].push(j);
		} else if (query_1 == 2) {
			cin >> i;
			priority_queue<int, vector<int>, greater<int>> copy_que = que_for_query2[i];
			while (copy_que.size() != 0) {
				cout << copy_que.top() << " ";
				copy_que.pop();
			}
			cout << endl;
		} else if (query_1 == 3) {
			cin >> i;
			priority_queue<int, vector<int>, greater<int>> copy_que = que_for_query3[i];
			vector<int> out(TEISU,0);
			while (copy_que.size() != 0) {
				int index = copy_que.top();
				copy_que.pop();
				if (out[index] == 0) {
					cout << index << " ";
					out[index] = 1;
				}
			}
			cout << endl;
		}
	}
	return 0;
}