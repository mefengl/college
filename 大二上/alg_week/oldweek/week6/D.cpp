#include <cstdio>
int main()
{
    int t;
    scanf("%d", &t);
    while (t--) // 遍历组数
    {
        int n, i, a[100] = { 0 }, m, k = 0;
        scanf("%d", &n);
        m = n;
        while (n--) // 遍历糖罐
        {
            char s[1005];
            scanf("%s", s);
            for (i = 0; s[i]; i++) // 遍历字符串
            {
                a[s[i] - 'a']++;
            }
        }
        for (i = 0; i<26; i++)
        {
            if (a[i] % m != 0) // 不能平分即不满足要求
            {
                k = 1;
                break;
            }
        }
        if (k == 1)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }
    return 0;
}