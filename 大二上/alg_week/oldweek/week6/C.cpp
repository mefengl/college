#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
#define MAXSIZE 150

class Element {
public:
    int total_weight, total_value;
    double average_value; // total_value / total_weight

    bool operator<(const Element& other) const {
        /* 把原有的的’<‘改成’<‘就可以逆排序（虽然不一定规范） */
        return average_value > other.average_value;
    }
};

void init_Element(Element element[], int kinds_number) { // 初始化元素详情
    for (int i = 0; i < kinds_number; ++i) {
        cin >> element[i].total_weight >> element[i].total_value;
        element[i].average_value = element[i].total_value * 1.0 / element[i].total_weight;
    }
    sort(element, element + kinds_number); // 从大到小排序
}

int main() {
    int n;
    cin >> n;
    int pocket_weight, kinds_number, pocket_left;
    double sum_value;
    Element element[MAXSIZE];

    while (n--) {
        cin >> pocket_weight >> kinds_number;
        pocket_left = pocket_weight;
        sum_value = 0; // 初始化
        init_Element(element, kinds_number);

        for (int i = 0; i < kinds_number; ++i) {
            if (pocket_left < element[i].total_weight) { // 如果口袋装不下了
                sum_value += pocket_left * element[i].average_value;
                break;
            } else { // 口袋装的下
                pocket_left -= element[i].total_weight;
                sum_value += element[i].total_value;
            }
        }

        printf("%.2lf\n", sum_value); // 按要求输出
    }

    return 0;
}
