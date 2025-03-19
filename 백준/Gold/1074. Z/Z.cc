#include <iostream>



using namespace std;




int solution(int N, int r, int c) // 재귀함수 활용
{
    if(N == 0) {
        return 0;
    }
    int half = 1 << N-1;
    if(r < half && c < half) {
        return solution(N-1, r, c);
    }
    else if(r < half && c >= half) {
        return half * half + solution(N-1, r, c-half);
    }
    else if(r >= half && c < half) {
        return 2 * half * half + solution(N-1, r-half, c);
    }
    else {
        return 3 * half * half + solution(N-1, r-half, c-half);
    }


}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, r, c;
    cin >> N >> r >> c;
    cout << solution(N, r, c);
    

    

    return 0;
}