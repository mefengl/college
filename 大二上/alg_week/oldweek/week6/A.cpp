/*    1 2
 *    3 4  只要2等于3即可
 */
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int kind_num, m;
    int a, b, c, d;
    int flag; // 判断有无2位和3位相等的矩阵
    while (n--) {
        flag = 0;

        cin >> kind_num >> m;

        for (int i = 0; i < kind_num; ++i) { // 循环录入，当场判断
            cin >> a >> b >> c >> d;
            if (b == c) {
                flag++;
            }
        }

        if (m % 2 != 0) { // 奇数列是不能拼出的
            flag = 0;
        }

        flag? cout << "YES": cout << "NO"; // 至少有一个即可拼成
        cout << endl;
    }
    return 0;
}