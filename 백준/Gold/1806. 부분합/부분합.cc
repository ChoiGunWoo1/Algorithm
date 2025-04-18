#include <iostream>
#include <algorithm>


using namespace std;

int num[100002];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, s;
    cin >> n >> s;
    
    for(int i = 0; i < n; i++) {
        cin >> num[i];
    }    
    int end = 0;
    int sum = num[0]; // 초기 sum값을 첫번째 배열 값으로 줌
    int answer = 0;
    for(int start = 0; start < n; start++) { // 투포인터 활용
        while(end < n && sum < s) {// sum이 s보다 작다면 end를 늘여가며 클때까지 길이를 늘린다
            end++;
            sum += num[end];
        }
        if(end == n) { // 끝까지 늘렸는데 s보다 크게 만들 수 없다면 더이상 start로부터 s를 만들 수 없으므로 break를 실행
            break;
        }
        if(answer != 0) {
            answer = min(answer, end - start + 1);
        }
        else {
            answer = end - start + 1;
        }
        sum -= num[start];
    }
    cout << answer;


    return 0;

}