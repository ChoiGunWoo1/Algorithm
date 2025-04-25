#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>


using namespace std;

vector<int> tree[100002];
int dp[100002];
int parent[100002];

int find_answer(int root) { //루트에서 BFS로 돌며 각 노드에 대한 서브트리 정보를 dp에 저장
    if(dp[root]) {          //dp에 이미 계산 되어있는 서브트리 정보를 불러 계산시간 단축
        return dp[root];
    }
    int r_answer = 1;
    for(auto nxt : tree[root]) {
        if(nxt == parent[root]) {
            continue;
        }
        parent[nxt] = root;
        r_answer += find_answer(nxt);
    }
    dp[root] = r_answer;
    return r_answer;
}




int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, r, q;
    cin >> n >> r >> q;
    int input1, input2;
    for(int i = 0; i < n-1; i++) {
        cin >> input1 >> input2;
        tree[input1].push_back(input2);
        tree[input2].push_back(input1);
    }
    find_answer(r);
    for(int i = 0; i < q; i++) {
        cin >> input1;
        cout << find_answer(input1) << '\n';
    }
    
    
    
    
    

    return 0;

}
