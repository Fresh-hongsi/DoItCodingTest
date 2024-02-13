#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N = 0; // 입력받은 자릿수

// 소수 판별검사 함수
bool prime_calculator(int num) {
	bool flag = true;

	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) {
			flag = false; // 소수가 아님
		}
	}

	return flag;
}

void dfs(int num, int jarisu)
{
	// 해당 num이 소수인지 판별
	bool is_prime =prime_calculator(num);

	// 소수가 아니면, return
	if (is_prime != true) {
		return;
	}


	// 소수라면, 자릿수 하나 더 올려서 dfs
	else {
		
		// 자릿수가 N이라면, 출력
		if (jarisu == N) {
			cout << num << '\n';
		}

		// 자릿수가 N이 아니라면, 자릿수 올려서 dfs다시 호출
		else {
			// 자릿수를 올렸을 때 가능한 소수 후보 가능군은 끝자리가 1,3,5,7,9일 때임
			for (int i = 1; i <= 9; i++) {
				if (i % 2 != 0) {
					dfs(num * 10 + i, jarisu + 1);
				}
			}
		}
	}
}



int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	cin >> N;

	// 가장 왼쪽에 있는 숫자부터 차례로 가지치기 시도
	dfs(2,1);
	dfs(3,1);
	dfs(5,1);
	dfs(7,1);

	return 0;


}
