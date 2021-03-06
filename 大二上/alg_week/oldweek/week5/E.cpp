//
// Created by fengl on 2020/10/4.
//

/* 这题的思路包括代码都和切蛋糕那题几乎一模一样 */
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
#define MAXSIZE 550000
int number_range[3];
int N, M;
int acm[MAXSIZE];
stack<int> acm_stack;

void update_number_range(int min, int max) { // 更新
   number_range[0] = min;
   number_range[2] = max;
   number_range[1] = (max - min + 1) / 2 + min;
}

void init_acm(int N, int M) { // 初始化数组
    for (int i = 0; i < N; ++i) {
        cin >> acm[i];
    }
    sort(acm, acm + N);
    update_number_range(0, acm[N - 1]);
}

void init_stack() { // 初始化栈，这个需要独立出来，因为栈总是会被修改
    while (!acm_stack.empty()) {
        acm_stack.pop();
    }
    for (int i = 0; i < N; ++i) {
        acm_stack.push(acm[i]);
    }
}

void give_stick() { // 核心程序
    int ticket_number = M;
    while (true) {
        if (acm_stack.empty()) { // 先更新max，这样在实验室和票都用完的情况下，找到min
            update_number_range(number_range[0], number_range[1]);
            return;
        }
        if (ticket_number == 0) { // 票用完了，实验室没投完，每次投少了，更新min
            update_number_range(number_range[1], number_range[2]);
            return;
        }
        int temp_acm = acm_stack.top();
        acm_stack.pop();
        if (temp_acm <= number_range[1]) { // 票有部分浪费
            ticket_number--;
        } else { // 票全部用了
            temp_acm -= number_range[1];
            ticket_number--;
            acm_stack.push(temp_acm);
        }
    }
}

bool check_number_range() {
    if (number_range[1] == number_range[0] || number_range[1] == number_range[2]) { // 检查
        return false;
    }
    return true;
}

int main() {
    while (cin >> N >> M) {
        if (N == -1) {
            break;
        }
        init_acm(N, M);
        while (check_number_range()) {
            init_stack();
            give_stick();
        }
        cout << number_range[1] << endl;
    }
    return 0;
}