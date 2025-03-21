#include <iostream>



using namespace std;
int Nqueen[15]; 
int visited[15];// visted[x] = y
int N;
int answer = 0;


void solution(int n) // 재귀함수 활용
{
    if(n == N) {
        answer++;
        return;
    }
    for(int i = 0; i < N; i++){
        if(visited[i] < 0) {
            bool can = true;
            for(int j = 0; j < N; j++) {
                if(visited[j] >= 0) {
                    if(abs(j - i) == abs(visited[j] - n)) {
                        can = false;
                        break;
                    }
                }
            }
            if(can) {
                visited[i] = n;
                solution(n+1);
                visited[i] = -1;
            }
        }
    }


}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int j = 0; j < 15; j++) {
        visited[j] = -1;
    }

    cin >> N;
    solution(0);
    cout << answer;
    

    

    return 0;
}