#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 기수 정렬(radix sort)과 비슷한 계수 정렬(counting sort)

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	cin >> N;

	vector<int> arr(10001, 0);

	// 수를 입력받아서 그 수에 해당하는 인덱스에 값을 1씩 증가시키기
	for (int i = 0; i < N; i++) {
		int temp = 0;
		cin >> temp;

		arr[temp]++;
	}

	// 해당 인덱스의 숫자가 1개 이상이면 그 수를 0이될때까지 감소시키면서 출력
	for (int i = 0; i < 10001; i++) {
		if (arr[i] != 0) {
			while (arr[i]--) {
				cout << i << '\n';

			}
		}

		else {
			continue;
		}
	}

	return 0;


}
