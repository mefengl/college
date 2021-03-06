//
// Created by fengl on 2020/10/4.
//
#include <iostream>
using namespace std;

#define llong long long
llong k_range[3]; // min k max
llong candy_number;

void update_k_range(llong min, llong max) {
    k_range[0] = min;
    k_range[2] = max;
    k_range[1] = (max - min + 1) / 2 + min; // 题解需要是整数，故向上取整符合要求
}

void init_eat(){
    cin >> candy_number;
    update_k_range(0, candy_number);
}

void one_eat() {
    llong candy_left = candy_number;
    llong boy_eaten = 0;
    while (true) {
        if (candy_left <= k_range[1]) { // 糖果少于boy一次吃的，全部吃完并判断
            boy_eaten += candy_left;
            candy_left = 0;
            if (boy_eaten >= (candy_number + 1)/2) { // 多于或等于一半update max
                update_k_range(k_range[0], k_range[1]);
                break;
            } else { // 小于一半update min
                update_k_range(k_range[1], k_range[2]);
                break;
            }
        } else { // 一次吃不完的情况下，boy吃k颗，girl吃left/10颗
            candy_left -= k_range[1];
            boy_eaten += k_range[1];
            candy_left = candy_left - candy_left / 10;
        }
    }
}

bool check_eat() {
    if (k_range[1] == k_range[2]) { // 检查满足条件的两位是否相等即可
        return false;
    }
    return true;
}

int main() {
    init_eat();
    while (check_eat()) {
        one_eat();
    }
    cout << k_range[1] << endl;
    return 0;
}
