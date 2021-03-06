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
 * 韭菜类，存放韭菜的高度，和它之前的递增序列长度
 */
class ChineseChive {
public:
    int height;
    int length = 1;
};

/*
 * 计算最大递增序列函数
 */
int cal_maxlength(ChineseChive chive[], int item_number){
    int max = 1;
    for (int i = 1; i < item_number; ++i) {
        if (chive[i].height > chive[i-1].height) {
            chive[i].length = chive[i-1].length + 1;
            max = (max > chive[i].length)? max : chive[i].length;
        }
    }
    return max;
}


int main() {
    int n;
    cin >> n;
    ChineseChive chive[n];
    for (int i = 0; i < n; ++i) { // 录入数据
        cin >> chive[i].height;
    }

    cout << cal_maxlength(chive, n) << endl; // 输出
    return 0;
}
