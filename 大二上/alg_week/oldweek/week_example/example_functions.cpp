int isPrime(int n)
{
    for (int i = 2; i <= n / 2; ++i) {
        if(n % i ==0)
        {
            return 0;
        }
    }
    return 1;
}

int now = ;
mymax = max(mymax, now); // 更新最大值

int fab(int n) { // 斐波拉契函数
    if (n==1 || n==2) { // 终止条件
        return 1;
    }
    else { // 否则根据数列定义递归
        return fab(n-1) + fab(n-2);
    }
}

int gcd(int x,int y) {
    if (x < y) { // 录入数据保证x>y
        swap(x, y);
    }
    if (x == y || y == 0) { // 终止条件分别是xy相等或者上一次运算整除
        return x;
    }
    else { // 根据辗转相除法的定义来编写递归函数
        int t;
        t = x%y;
        x = y;
        y = t;
        return gcd(x, y);
    }
}


/* rangeC */
if (i > sum/2) { // long long依然会溢出，所以根据组合的性质简化运算
a = sum - i;
}
long long my_rangeC(int a, int n) { // 求数学组合C ,long可能会溢出所以用long long
    long long multiple1 = 1;
    long long multiple2 = 1;
    for (int i = 0; i < a; ++i) {
        multiple1 *= n - i;
    }
    for (int i = 1; i <= a; ++i) {
        multiple2 *= i;
    }
    return multiple1/multiple2;
}

/* 一个普通的回溯法 */
//void chess_down(int size, int column) { // 一个棋子对所在行造成影响
//    for (int i = 0; i < size; ++i) {
//        board[i][column]--;
//    }
//}
//
//void chess_up(int size, int column) { // 去除这种影响
//    for (int i = 0; i < size; ++i) {
//        board[i][column]++;
//    }
//}
//
//void way_count(int size, int row, int chess_number) {
//    if (row >= size) { // 遍历完成
//        return;
//    }
//    way_count(size, row+1, chess_number); // 不放棋子
//    for (int column = 0; column < size; ++column) {
//        if (board[row][column] == 1) {
//            chess_down(size, column);
//            if (chess_number == 1) { // 找到一种可能
//                way_number++;
//            }
//            way_count(size, row+1, chess_number-1); // 放棋子并继续递归
//            chess_up(size, column);
//        }
//    }
//}

/* 一个普通的二分法 */
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