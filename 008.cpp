#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
//투 포인터
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//입력
	int N = 0; //수의 개수
	vector<int> numArr; //입력받은 수들의 배열
	int count = 0; //결과값
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int temp = 0;
		cin >> temp;
		numArr.push_back(temp);
	}

	//오름차순 정렬
	sort(numArr.begin(), numArr.end());

	//투 포인터 이용해 맞는 조건인 경우 count하기
	for (int i = 0; i < N; i++)
	{
		int currentValue = numArr[i]; //좋은 수 인지 판별 대상이 되는 수
		
		//좋은 수 인지 판별 대상이 되는 수가 바뀔 때마다 두 포인터는 양쪽 끝으로 초기화
		int start_idx = 0;
		int end_idx = N - 1;

		while (start_idx < end_idx)
		{
			int start_val = numArr[start_idx]; //시작 포인터가 가리키는 값
			int end_val = numArr[end_idx]; //단말 포인터가 가리키는 값

			int sum = start_val + end_val; //두 포인터가 가리키는 값을 더한 값

			if (sum == currentValue) //좋은 수를 찾았다면
			{
				//중요!!! 중요 tc: 0 0 0 1 2일 경우도 있으므로 이를 고려해야힘
				if ((start_idx == i) || (end_idx == i)) //만약 좋은 수를 만드는 데 자기 자신이 쓰였을 경우, 포인터 조정해서 더 찾아봐야함
				{
					if (start_idx == i) //만약 시작 인덱스에서 겹쳤다면, 시작인덱스를 뒤로 미뤄보기
					{
						start_idx++;
					}
					else if(end_idx==i) //먄약 단말 인덱스에서 겹쳤다면, 단말 인덱스를 앞으로 댕겨보기
					{
						end_idx--;
					}

				}
				
				else //좋은 수를 만드는데 자기 자신이 쓰이지 않은 경우
				{
					count++;
					break; //while문 탈출
				}
				
			}
			else if (sum < currentValue) //좋은 수인지 판별 대상이 되는 수보다 두 포인터가 가리키는 값을 더한 값이 작다면
			{
				start_idx++; //시작 포인터 값 증가시켜보기
			}
			else if (sum > currentValue) //좋은 수인지 판별 대상이 되는 수보다 두 포인터가 가리키는 값을 더한 값이 크다면
			{
				end_idx--; //단말 포인터 값 감소시켜보기
			}
		}

		
		
	}

	cout << count;
	return 0;


}
