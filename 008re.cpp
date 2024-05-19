#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <functional>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	cin >> N;

	vector<int> arr;
	for (int i = 0; i < N; i++) {
		int temp = 0;
		cin >> temp;

		arr.push_back(temp);
	}

	sort(arr.begin(), arr.end());

	int result = 0;

	for (int i = 0; i < arr.size(); i++) {
		int cur = arr[i];

		int start = 0;
		int end = arr.size()-1;

		while (start < end) {
			if (arr[start] + arr[end] == cur) {
				if (start != i && end != i) {
					result++;
					break;
				}

				else if (start == i) {
					start++;
				}

				else if (end == i) {
					end--;
				}

			}

			else if(arr[start]+arr[end]<cur) {
				start++;
			}
			else {
				end--;
			}
		}
		

	}

	cout << result;
	return 0;
	//-1 -1 -1 0 0 1 1 2 3 4 5
}
