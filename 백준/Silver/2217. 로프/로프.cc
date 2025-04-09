#include <iostream>
#include <algorithm>


using namespace std;

int rope[100002];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> rope[i];
    }
    int answer = 0;
    sort(rope, rope+n);// rope배열을 오름차순으로 정렬
    for(int i = 0; i < n; i++) { // 그리디 알고리즘 : 현재선택한 로프로 만들 수 있는 최대 크기를 계속 갱신
        int canweight = rope[i] * (n - i); // 선택한 rope보다 작은 로프는 해당 무게를 지탱할 수 없다.
        if(canweight > answer) {
            answer = canweight;
        }
    }
    cout << answer;
   
    
    return 0;
}