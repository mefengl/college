#include<Windows.h>
#include <iostream>
using namespace std;
#include <algorithm>

int n, m;
int range[2];
class KISS1 { // 为了能够两个数组按第一个数组排序
public:
    int a,b,c;
    long long d;
    bool operator<(const KISS1& other) const {
        /* 把原有的的’<‘改成’<‘就可以逆排序（虽然不一定规范） */
        return a > other.a;
    }
};

class KISS2 { // 为了能够两个数组按第二个数组排序
public:
    int b,c;
    bool operator<(const KISS2& other) const {
        /* 把原有的的’<‘改成’<‘就可以逆排序（虽然不一定规范） */
        return b > other.b;
    }
};

void init_kiss(KISS1 kiss1[], KISS2 kiss2[]) { // 录入数据
    cin >> kiss1[0].a >> kiss1[0].b;
    kiss1[0].d = kiss1[0].a;
    for (int i = 1; i < m; ++i) {
        cin >> kiss1[i].a >> kiss1[i].b;
        kiss1[i].d = kiss1[i].a + kiss1[i-1].d;
    }
    sort(kiss1, kiss1 + m);
    for (int i = 0; i < m; ++i) {
        kiss1[i].c = i+1;
    }
    for (int i = 0; i < m; ++i) {
        kiss2[i].b = kiss1[i].b;
        kiss2[i].c = kiss1[i].c;
    }
    sort(kiss2, kiss2 + m);
}

long long kiss_num(KISS1 kiss1[], KISS2 kiss2[], int bought_first) {
    long long max = 0, sum = 0, temp_sum;
    if (bought_first != 0) sum = kiss1[bought_first-1].d;
    if (kiss2[0].c <= bought_first) {
        return sum+kiss2[0].b * (n - bought_first);
    }
    for (int i = 0; i < m; ++i) {
        temp_sum = sum;
        if (i < bought_first) {
            temp_sum += kiss1[i].b * (n - bought_first);
        } else {
            temp_sum += kiss1[i].a + kiss1[i].b * (n - bought_first - 1);
        }
        max = max > temp_sum ? max : temp_sum;
    }
    return max;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        range[0] = 0;
        range[1] = m;
        KISS1 kiss1[m];
        KISS2 kiss2[m];
        long long max = 0;
        init_kiss(kiss1,kiss2);
        DWORD start_time = GetTickCount();
        long long temp;
        int times = 4;
        int temp1,temp2;
        while (range[1] - range[0] > 1000 && times--) {
            temp1 = (range[1] - range[0])/4;
            temp2 = temp1+(range[1] - range[0])/2;
            if (kiss_num(kiss1, kiss2, temp1) > kiss_num(kiss1, kiss2, temp2)) {
                range[1] = (range[1] - range[0])/2;
            } else if (kiss_num(kiss1, kiss2, temp1) < kiss_num(kiss1, kiss2, temp2)) {
                range[0] = (range[1] - range[0])/2;
            }
        }
        for (int i = range[0]; i <= range[1]; ++i) {
            temp = kiss_num(kiss1, kiss2, i);
            max = max > temp ? max : temp;
        }
        cout << max << endl;
        DWORD end_time = GetTickCount();
        cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;
    }
    return 0;
}