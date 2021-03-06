#include <iostream>
#include <algorithm>
using namespace std;
#define MAXSIZE 55000
int L, N, M;
int stones[MAXSIZE];

void init_stones() { // 初始化
    cin >> L >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> stones[i];
    }
    stones[N] = L;
    sort(stones, stones + N + 1);
}


int counting(int dis) {
    int standing = 0, counter = 0;
    for (int i = 0; i < N; ++i) {
        if (stones[i] - standing < dis) { // 过短不过
            counter++; // 搬的石头加1
        } else {
            standing = stones[i]; // 登上另一个石头，更新所在位置
        }
    }
    return counter;
}

int cross_river() {
    int min = 0, max = L, mid = L / 2;
    while (min <= max) {
        if (counting(mid) > M) {
            max = mid - 1;
        } else {
            min = mid + 1;
        }
        mid = (max + min) / 2;
    }
    return mid;
}

int main() {
    init_stones();
    cout << cross_river() << endl;
    return 0;
}