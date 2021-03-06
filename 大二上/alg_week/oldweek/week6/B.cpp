#include <iostream>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstdio>
using namespace std;
#define MAXSIZE 150


int main() {
    double a[MAXSIZE];
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a+n); // 从小到大

    stack<double> a_stack;
    for (int i = 0; i < n; ++i) {
        a_stack.push(a[i]); // 从大到小
    }

    double length1, length2, length3;
    while (a_stack.size() != 1) // 循环直到只剩一个数据
    {
        length1 = a_stack.top();
        a_stack.pop();
        length2 = a_stack.top();
        a_stack.pop();
        length3 = 2 * sqrt(length1 * length2); // 计算
        a_stack.push(length3);
    }

    printf("%.3lf\n", a_stack.top()); // 输出
    return 0;
}