#include <iostream>
#include <algorithm>

using namespace std;

int LCD(int a, int b) {
    if(b == 0) {
        return a;
    }
    return LCD(b, a % b);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int f;
    cin >> f;
    for(int i = 0; i < N-1; i++) {
        int input;
        cin >> input;

        int lcd;
        if(f >= input) {
            lcd = LCD(f, input);
        }
        else {
            lcd = LCD(input, f);
        }
        cout << f / lcd << "/" << input / lcd;
        cout << '\n';
    }

    return 0;
}