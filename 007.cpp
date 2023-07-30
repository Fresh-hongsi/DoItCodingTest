#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

//투포인터

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0; //재료의 개수
	int M = 0; //갑옷이 완성되는 번호의 합
	vector<int> material_num; //재료번호를 저장할 벡터
	int count = 0; //조건에 만족하는 조합 개수

	

	//입력
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int matNum = 0;
		cin >> matNum;
		material_num.push_back(matNum);
	}

	int start_idx = 0; //시작 포인터는 맨 앞에 위치
	int end_idx = N-1; //단말 포인터는 맨 뒤에 위치

	//오름차순 정렬
	sort(material_num.begin(), material_num.end());

	//투포인터 이용해 수 조합 찾기
	while (start_idx<end_idx) //두 포인터가 교차하기 전까지 진행
	{
		int start_val = material_num[start_idx]; //시작 포인터가 가리키는 값
		int end_val = material_num[end_idx]; //단말 포인터가 가리키는 값

		if ((start_val + end_val) == M) //조건 만족하는 경우
		{
			//시작, 단말 포인터 위치 둘다 변경, 결과값 증가시키기
			count++;
			start_idx++;
			end_idx--;
		}

		else if ((start_val + end_val) < M) //조건보다 작다면
		{
			//start_idx값 증가시켜보기
			start_idx++;
		}

		else if ((start_val + end_val) > M) //조건보다 크다면
		{
			//end_idx값 감소시켜보기
			end_idx--;
		}
	}

	//결과값 출력
	cout << count << '\n';
	return 0;
}
