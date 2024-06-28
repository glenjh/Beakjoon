#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

int main() {

	queue<int> q;

	int n;
	int k;

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		q.push(i + 1);
	}
	cout << '<';
	while (!q.empty()) {
		for (int i = 0; i < k-1; i++) {
			q.push(q.front());
			q.pop();
		}
		cout << q.front();
		q.pop();
		if (!q.empty()) {
			cout << ',' << ' ';
		}
	}
	cout << ">";
	return 0;
}