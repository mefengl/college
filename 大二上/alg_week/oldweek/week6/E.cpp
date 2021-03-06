#include <iostream>
#include <algorithm>
using namespace std;
#define MAXSIZE 26

int main() {
    int candy[MAXSIZE] = {0};
    int sum;
    string s;
    cin >> s;
    for (char i : s) { // 遍历字符串中字符
        if ('a' <= i && i <= 'z') {
            candy[i - 'a']++;
        } else {
            candy[i - 'A']++;
        }
    }
    sort(candy, candy + MAXSIZE); // 从小到大排序
    sum = 0;
    for (int i = MAXSIZE; i > 0; --i) { // 元素位置和价格基本是对应的
        sum += i * candy[i - 1];
    }
    cout << sum << endl;
    return 0;
}
