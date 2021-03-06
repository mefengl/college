#include <iostream>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <iomanip>
using namespace std;
#define MAXSIZE 10000


/*
 * 一道简单的数学题
 * 得到1+3+5+...+(2*n-1)+...+5+3+1的递推式即可
 * 即(2 * n * n) - (2 * n) + 1
 */



int main() {
    int n;
    cin >> n;
    cout << (2 * n * n) - (2 * n) + 1 << endl;
    return 0;
}
