//
// Created by fengl on 2020/10/4.
//
#include <iostream>
#include <algorithm>
#include <functional>
#include <stack>
#include <cstdio>
#include <cmath>
using namespace std;

#define MAXSIZE 15000
double Pi = acos(-1.0);
#define llong long long

double cake[MAXSIZE];
stack<double> cake_stack;
llong cake_num;
int friend_num;
double cut_range[3]; // min middle max

double area(int r) {
    return r * r * Pi;
}

void sort_cake() {
    sort(cake, cake + cake_num); // min to max
}

void init_stack() {
    while (!cake_stack.empty()) { // empty the stack
        cake_stack.pop();
    }
    for (int i = 0; i < cake_num; ++i) { // max on top
        cake_stack.push(cake[i]);
    }
}


void update_cut_range(double min, double max) {
    cut_range[0] = min;
    cut_range[2] = max;
    cut_range[1] = (max - min) / 2 + min;
}


void init_cake() {
    cin >> cake_num >> friend_num;
    int r;
    for (int i = 0; i < cake_num; ++i) { // 由半径，录入所有的面积
        cin >> r;
        cake[i] = area(r);
    }
    sort_cake();
    init_stack();
    update_cut_range(cake_stack.top() / (friend_num + 1), cake_stack.top()); // 初始化，min为max均分，max就设为max
}

void cut_cake() {
    llong friend_num_temp = friend_num;
    while (true) {
        if (cake_stack.empty()) {
            update_cut_range(cut_range[0], cut_range[1]); // 蛋糕不够分，切多了，update the max
            return;
        }
        if (friend_num_temp == -1) {
            update_cut_range(cut_range[1], cut_range[2]); // 蛋糕多了，切少了，update the min
            return;
        }
        double temp_cake = cake_stack.top(); // 查看top_cake的大小
        if (temp_cake < cut_range[1]) { // 不够切一刀，就拿出来，扔掉
            cake_stack.pop();
        } else { // 够切
            cake_stack.pop(); // 取出来
            temp_cake -= cut_range[1]; // 切一刀
            cake_stack.push(temp_cake); // 切完，返回去
            friend_num_temp--; // 切下的蛋糕分给一个还没有蛋糕的人
        }
    }
}

bool check_cake() {
    if (cut_range[2] - cut_range[0] < 1e-5) { // 二分法终止条件
        return true;
    }
    return false;
}

int main() {
    llong T;
    cin >> T;
    while (T--) {
        init_cake();
        for (;;) {
            cut_cake();
            init_stack();
            if (check_cake()) {
                break;
            }
        }
        printf("%.4lf\n", cut_range[1]);
    }
    return 0;
}
