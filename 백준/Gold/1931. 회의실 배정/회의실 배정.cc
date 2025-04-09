#include <iostream>
#include <algorithm>


using namespace std;


pair<int, int> meeting[100002];


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int s, e;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s >> e;
        meeting[i] = make_pair(e, s);
    }
    sort(meeting, meeting+n);
    int endp = 0;
    int answer = 0;
    for(int i = 0; i < n; i++) { // 그리디 알고리즘 : 회의 종료시간을 기준으로 오름차순 정렬해놓은 배열에서 이전 선택한 회의 종료시간 이후에 가장 처음으로 시작하는 회의를 고른다
        if(meeting[i].second >= endp) {
            answer += 1;
            endp = meeting[i].first;
        }
    }
    cout << answer;
    
    return 0;
}