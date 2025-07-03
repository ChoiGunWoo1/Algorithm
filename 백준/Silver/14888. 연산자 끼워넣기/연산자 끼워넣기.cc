#include <iostream>
#include <algorithm>
#include <vector>
#include <map>


using namespace std;

vector<int> number;
vector<int> symbol;

int answer;
int N;
int maxa = -1000000001;
int mina = 1000000001;

void check(int num, int cnt) {
    if(cnt == N-1) {
        if(maxa < num) {
            maxa = num;
        }
        if(mina > num) {
            mina = num;
        }
        return;
    }
    if(cnt == 0) {
        answer = number[0];
    }
    for(int i =0; i < 4; i++) {
        if(symbol[i] > 0) {
            symbol[i] -= 1;
            if(i == 0) {
                check(num + number[cnt+1],cnt+1);
            }
            else if(i == 1) {
                check(num - number[cnt+1],cnt+1);
            }
            else if(i == 2) {
                check(num * number[cnt+1],cnt+1);
            }
            else {
                check(num / number[cnt+1],cnt+1);
            }
            symbol[i] += 1;
        }
    }
}









int main()
{
    cin.tie(0); cout.tie(0);
    cin.sync_with_stdio(false);
    int input;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> input;
        number.push_back(input);
    }
    for(int j = 0; j < 4; j++) {
        cin >> input;
        symbol.push_back(input);
    }
    check(number[0], 0);
    cout << maxa << '\n' << mina;


    
    
    

    return 0;
}