#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <iomanip>
using namespace std;
#define MAXSIZE 100
#define cin2 cin >> a >> b
#define int2 int a = 0, b = 0;
#define cin3 cin >> a >> b >> c
#define int3 int a = 0, b = 0, c = 0;

long long s[100];
int main() {
    memset(s, 0, 100);
    s[1] = 1;
    s[2] = 2;
    s[3] = 4;
    s[4] = 7;
    for (int i = 5; i < 60; ++i) {
        for (int j = 1; j <= 4; ++j) {
            s[i] += s[i - j];
        }
    }
    int n;
    cin >> n;
    cout << s[n];
    return 0;
}