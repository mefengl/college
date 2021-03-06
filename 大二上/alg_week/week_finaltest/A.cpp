#include <iostream>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <iomanip>
using namespace std;
#define MAXSIZE 10000
#define cin2 cin >> a >> b
#define int2 int a = 0, b = 0
#define cin3 cin >> a >> b >> c
#define int3 int a = 0, b = 0, c = 0

#define MAX 100

//在此补充完整求n!的函数
long long fac(int i) {
    long long sum = 1;
    for (int j = 1; j <= i; ++j) {
        sum *= j;
    }
    return sum;
};


int main()

{

    int i;
    cin >> i;

//    scanf("%d",&i);
    //在此补充语句，输出i！的值，除此值外不要输出其他信息。
    cout << fac(i);


    return 0;

}