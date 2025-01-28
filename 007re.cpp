#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
using namespace std;

int N = 0;
int M = 0;
int result = 0;
vector<int> arr;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int temp = 0;
		cin >> temp;

		arr.push_back(temp);
	}

	sort(arr.begin(), arr.end());

	int st = 0;
	int end = N - 1;

	while (st < end) {
		if (arr[st] + arr[end] == M) {
			result++;
			st++;
			end--;
		}
		else if(arr[st]+arr[end]<M) {
			st++;
		}
		else {
			end--;
		}
	}

	cout << result;

	return 0;
}
