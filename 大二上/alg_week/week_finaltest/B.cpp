#include <iostream>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <iomanip>
using namespace std;
#define MAXSIZE 10000
#define cin2 cin >> a >> b
#define int2 int a = 0, b = 0;
#define cin3 cin >> a >> b >> c
#define int3 int a = 0, b = 0, c = 0;

bool fac(int x) {
    if (x == 1) {
        return false;
    }
    int sum = 1;
    for (int i = 2; i < x; ++i) {
        if (x % i == 0) {
            sum += i;
        }
    }
    return sum == x;
}

int main() {
    int2;
    cin2;
    int num = 0;
    for (int i = a; i <= b; ++i) {
        if (fac(i)) {
            num++;
        }
    }
    cout << num;
    return 0;
}
