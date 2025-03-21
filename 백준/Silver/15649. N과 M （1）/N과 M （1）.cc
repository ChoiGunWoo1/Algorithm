#include <iostream>
#include <vector>



using namespace std;
bool visited[8] = {0, };
vector<int> v;



void solution(int N, int M) // 재귀함수 활용
{
    if(v.size() == M) {
        for(int i = 0; i < M; i++) {
            cout << v[i] << " ";
        }
        cout << '\n';
        return;
    }
    for(int i = 0; i < N; i++) {
        if(!visited[i]) {
            v.push_back(i+1);
            visited[i] = true;
            solution(N, M);
            v.pop_back();
            visited[i] = false;
        }
    }


}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    solution(n, m);
    

    

    return 0;
}