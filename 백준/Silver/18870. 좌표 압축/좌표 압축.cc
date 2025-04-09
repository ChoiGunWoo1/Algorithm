#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;


int num[1000002]; 
vector<int> tmp;
int answer[1000002];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> num[i];
        tmp.push_back(num[i]);
    }
    sort(tmp.begin(), tmp.end()); // 정렬후
    auto ed = unique(tmp.begin(), tmp.end()); // 중복제거
    tmp.erase(ed, tmp.end()); 
    for(int i = 0; i < n; i++) { // 이분탐색으로 lower_bound찾기
        answer[i] = lower_bound(tmp.begin(), tmp.end(), num[i]) - tmp.begin();
        cout << answer[i] << " ";
    }
    


    return 0;
}