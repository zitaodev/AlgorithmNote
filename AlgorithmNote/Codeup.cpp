//
//  Codeup.cpp
//  AlgorithmNote
//
//  Created by Joe on 2022/3/1.
//

#include "Codeup.hpp"
#include <cstring>

// 3.4 日期处理：1928 日期差值
// 平年和闰年的每个月的天数，数组从0开始，月份从1开始
int month[13][2] = {{0, 0}, {31, 31}, {28,29}, {31, 31}, {30, 30}, {31, 31}, {30, 30},
                    {31, 31}, {31, 31}, {30, 30}, {31, 31}, {30, 30}, {31, 31}
                   };
bool isLeap(int year) { // 判断是否闰年（四年一闰；百年不闰，四百年再闰）
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}
void Codeup_1928() {
    int time1, y1, m1, d1;
    int time2, y2, m2, d2;
    while (scanf("%d%d", &time1, &time2) != EOF) {
        if (time1 > time2) { // 第一个日期晚于第二个日期，则交换，看作是排序
            int temp = time1;
            time1 = time2;
            time2 = temp;
        }
        y1 = time1 / 10000;
        m1 = time1 % 10000 / 100;
        d1 = time1 % 100;
        y2 = time2 / 10000;
        m2 = time2 % 10000 / 100;
        d2 = time2 % 100;
        int ans = 1;// 记录结果
        // 第一个日期没有达到第二个日期时进行循环
        // 即!((y1 == y2) && (m1 == m2) && (d1 == d2))
        while (y1 < y2 || m1 < m2 || d1 < d2) {
            d1++; // 天数加一
            if (d1 == month[m1][isLeap(y1)] + 1) { // 满当月天数,日期变为下个月的1号
                m1++;
                d1 = 1;
            }
        }
    }
}

// 3.2 查找元素：1943 找x
const int maxn = 210;
int a[maxn];
void Codeup_1934() {
    int n, x;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]); //输入n个数
        }
        scanf("%d", &x); // 输入查询的数
        int k; // 下标
        for (k = 0; k < n; k++) {
            if (a[k] == x) {
                printf("%d\n", k);// 输出对应的下标
                break;
            }
        }
        
        if (k == n) {// 没有找到
            printf("-1\n");
        }
    }
}

// 3.6 字符串处理 5901 回文串
const int maxn_5901 = 256;
// 判断字符串str是否是回文串
bool judge(char str[]) {
    size_t len = strlen(str); // 字符串长度
    for (int i = 0; i < len / 2; i++) { // 枚举字符串前一半
        if (str[i] != str[len - i - 1]) { // 判断对称位置是否相同
            return false; //不是
        }
    }
    return true;
}
void Codeup_5901() {
    char str[maxn_5901];
    while (gets(str)) { // 输入字符串
        bool flag = judge(str);
        if (flag == true) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
}
