#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
using namespace std;

int N = 0;
int result = 0;
vector<int> arr;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int temp = 0;
		cin >> temp;

		arr.push_back(temp);
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < N; i++) {
		int cur = arr[i]; // 현재 수
		int st = 0;
		int end = N - 1;
		while (st < end) {
			if (st == i) {
				st++;
				continue;
			}
			if (end == i) {
				end--;
				continue;
			}

			if (arr[st] + arr[end] == cur) {
				//cout << arr[st] << ' ' << arr[end] << '\n';
				result++;
				break;
			}
			else if (arr[st] + arr[end] < cur) {
				st++;
			}
			else if (arr[st] + arr[end] > cur) {
				end--;
			}


		}
	}

	cout << result;
	


	//-3 -2 -1 0 0 1 2 3 4 4 5



	return 0;
}
