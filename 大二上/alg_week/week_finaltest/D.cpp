#include <iostream>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <iomanip>
using namespace std;
#define MAXSIZE 1000005
#define cin2 cin >> a >> b
#define int2 int a = 0, b = 0;
#define cin3 cin >> a >> b >> c
#define int3 int a = 0, b = 0, c = 0;


long long s[MAXSIZE];
long long a, b;

long long counting(long long mid) {
    long long sum = 0;
    for (int i = 0; ; ++i) {
        if (s[i] == -1) {
            break;
        }
        sum += min(s[i], mid);
    }
    return sum;
}
/* 一个普通的二分法 */
long long fac() {
    long long min = 0, max = b, mid;
    while (min <= max) {
        if (counting(mid) >= b) {
            max = mid - 1;
        } else {
            min = mid + 1;
        }
        mid = (max + min) / 2;
    }
    if (counting(mid - 1) >= b) return mid - 1;
    else if (counting(mid) >= b) return mid;
    else return mid + 1;
}

int main() {
    std::ios::sync_with_stdio(false);
    memset(s, -1, MAXSIZE);
    cin >> a >> b;
    for (int i = 0; i < a; ++i) {
        cin >> s[i];
    }
    cout << fac();
    return 0;
}
