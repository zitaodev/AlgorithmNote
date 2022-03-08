//
//  Note.cpp
//  AlgorithmNote
//
//  Created by Joe on 2022/3/8.
//

#include "Note.hpp"
#include <math.h>
#include <algorithm>
#include <cstdio>
using namespace std;
// 4.4.2 区间贪心
/*
 区间不相交问题：给出N个开区间，从中选择尽可能多的开区间，使得这些开区间两两没有交集，如对开区间(1,3)(2,4)(3,5)(6,7)，可以选择最多三个区间(1,3)(3,5)(6,7)
 */
const int maxn_I = 110;
struct Interval {
    int x, y; // 开区间左右端点
}I[maxn_I];

bool cmp_I(Interval a, Interval b) {
    if (a.x != b.x) {
        return a.x > b.x; // 先按照左端点从大到小排序
    }else {
        return a.y < b.y; // 左端点相同按右端点从小到大排序
    }
}
void selectInterval() {
    int n;
    while(scanf("%d", &n), n != 0) {
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &I[i].x, &I[i].y);
        }
        sort(I, I + n, cmp_I);// 把区间排序
        // ans记录不相交区间个数，lastx记录上一个被选中区间的左端点
        int ans = 1, lastX = I[0].x;
        for (int i = 1; i < n; i++) {
            if (I[i].y <= lastX) { //如果该区间右端点在lastx左边，则该交换位置
                lastX = I[i].x;
                ans++;
            }
        }
        printf("%d\n", ans);
        
    }
}
// 4.3 递归
/*
 全排列：输出1 ～ n这n个整数的全排列，可分解为输出以1开头的全排列，输出以2开头的全排列。。。输出以n开头的全排列
 */
const int maxn_43 = 11;
int P[maxn_43], hashTable_43[maxn_43] = {false}; // P为当前排列，hashTable记录整数x是否已经在P中

// n 皇后：指在一个n*n的国际象棋棋盘上放置n个皇后，使得这n个皇后两两家均不在同一行，同一列，同一条对角线上，求合法方案数。
int n_q = 8;
int count_43 = 0;
/// 暴力法求解
void generateQ_43(int index) {
    if (index == n_q + 1) { // 递归边界，生成一个排列
        bool flag = true; // true表示当前排列是一个合法方案
        for (int i = 1; i <= n_q; i++) {
            for (int j = i + 1; j <= n_q; j++) {
                if (abs(i - j) == abs(P[i] - P[j])) { // 如果不在一条对角线上
                    flag = false;
                }
            }
        }
        if (flag) {
            count_43++; // 若当前方案合法，令count加1
        }
        return;
    }
    for (int x = 1; x <= n_q; x++) {
        if (hashTable_43[x] == false) {
            P[index] = x;
            hashTable_43[x] = true;
            generateQ_43(index + 1);
            hashTable_43[x] = false;
        }
    }
}
// 1 ～ 3的全排列
int n = 3; // P为当前排列，hashTable记录整数x是否已经在P中
void generateP_43(int index) { // 当前处理排列的第index位
    if (index == n + 1) {// 递归边界，已经处理完排列的1 ～ n 位
        for (int i = 1; i <= n; i++) {
            printf("%d", P[i]);
        }
        printf("\n");
        return;
    }
    for (int x = 1; x <= n; x++) { // 枚举1～n，试图将x填入p中
        if (hashTable_43[x] == false) { // 如果x不在p[0] ~ p[index-1]中
            P[index] = x;// 将x加入当前排列
            hashTable_43[x] = true; // 标记x已经p中
            generateP_43(index + 1);// 处理排列的第index+1号位
            hashTable_43[x] = false;// 已经处理完，还原状态
        }
    }
}
// 4.2.2 字符串hash初步
/*
 题目：给出N个字符串（恰好是三位大写字母组成），再给出M个查询字符串，问每个查询字符串在N个字符串中出现的次数。
 */
const int maxn_hash4 = 100;
char s[maxn_hash4][5], temp4[5];
int hashTable4[26 * 26 * 26 + 10];
int hashFunc4(char S[],int len) {
    int id = 0;
    for (int i = 0; i < len; i++) {
        id = id * 26 + (S[i] - 'A');
    }
    return id;
}
void hashSearch() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {// 输入n个字符串
        scanf("%s", s[i]);
        int id = hashFunc4(s[i], 3);// 将字符串转换成整数
        hashTable4[id]++; // 该字符串出现次数加1
    }
    for (int i = 0; i < m; i++) {// 输入m个字符串
        scanf("%s", temp4);
        int id  = hashFunc4(temp4, 3);
        printf("%d\n", hashTable4[id]);
    }
}

/*
 字符串有大小写字母数字，则由两种处理方法：
 1、按照小写字母的处理方法，增大进制数到62.
 2、如果保证字符串末尾是确定个数的数字，那么可以先把字母转换成整数，再将末尾数字直接拼接上去，如BCD4，先把BCD转换成731，再把4拼接上变为7314即可。
 */
int hashFunc3_2(char S[], int len) {
    int id = 0;
    for (int i = 0; i < len - 1; i++) { // 确定末位是数字，因此除外末位
        id = id * 26 + (S[i] - 'A');
    }
    id = id * 10 + (S[len - 1] - '0');
    return id;
}
int hashFunc3_1(char S[], int len) {
    int id = 0;
    for (int i = 0; i < len; i++) {
        if (S[i] >= 'A' && S[i] <= 'Z') {
            id = id * 62 + (S[i] - 'A');
        } else if (S[i] >= 'a' && S[i] <= 'Z') {
            id = id * 62 + (S[i] - 'a') + 26;
        } else if (S[i] >= '0' && S[i] <= '9') {
            id = id * 62 + (S[i] - '0') + 10;
        }
    }
    return id;
}
/*
 字符串有大小写字母，则把A ~ Z视为0 ～ 25，a ~ z视为26 ～ 51，这样就变成五十二进制转换成十进制的问题
 */
int hashFunc2(char S[], int len) {
    int id = 0;
    for (int i = 0; i < len; i++) {
        if (S[i] >= 'A' && S[i] <= 'Z') {
            id = id * 52 + (S[i] - 'A');
        } else if (S[i] >= 'a' && S[i] <= 'Z') {
            id = id * 52 + (S[i] - 'a') + 26;
        }
    }
    return id;
}
/*
 字符串均由大写字母A ～ Z，把A ~ Z视为0 ～ 25，26个大写字母对应到二十六进制中，可实现将字符串映射成整数，整数最大值是26^len。
 注意字符串S的长度不能太长
 */
int hashFunc1(char S[], int len) {
    int id = 0;
    for (int i = 0; i < len; i++) {
        id = id * 26 + (S[i] - 'A');
    }
    return id;
}
//4.2 散列（hash）
/*
 给出N个正整数，再给出M个正整数，问这M个数中每个数分别是否在N中出现过，其中N,M<=10^5，且所有正整数均不超过10^5;
 */
/********************输出true or false**********************************/
const int maxn_hash = 100010;
bool hashTable[maxn_hash] = {false};
void isFound() {
    int n, m, x;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        hashTable[x] = true; // 数字x出现过
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        if (hashTable[x] == true) {  // 数字x出现过，则输出yes
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
}

/********************输出出现次数**********************************/
const int maxn_hash1 = 100010;
int hashTable1[maxn_hash1] = {0};
void isFound1 () {
    int n, m, x;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        hashTable1[x]++;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        printf("%d", hashTable1[x]);
    }
}

// 2.5.4
// 2.5.3 二维数组:可以看作一维数组的每一个元素都是一个一维数组，如int a[5][6]看作是5个长度为6的一维数组
// warning：如果数组大小较大（大概10^6级别），则需要将其定义在主函数外面，否则会使程序异常退出，原因是函数内部申请的局部变量来自系统栈，允许申请的空间较小；
//          而函数外部申请的全局变量来自静态存储区，允许申请的空间较大

// 两个二维数组相加
void two_dimen_array_sum() {
    int a[3][3], b[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &b[i][j]);
        }
    }
    int c[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}

// 2.2.6 常用math函数
void math_func() {
    // 1.fabs(double x)用于对double型变量取绝对值
    double db1 = -12.56;
    printf("%.2f\n",fabs(db1)); // 输出结果 12.56
    
    // 2.floor(double x)和ceil(double x)用于double型变量的向下取整和向上取整，返回类型是double型
    double db2 = -5.2, db3 = 5.2;
    printf("%.0f %.0f\n", floor(db2), ceil(db2)); // 输出 -6 -5
    printf("%.0f %.0f\n", floor(db3), ceil(db3)); // 输出 5 6
    
    // 3.pow(double r, double p) 用于返回r^p,要求r和p都是double型
    double db4 = pow(2.0, 3.0);
    printf("%f\n", db4); //输出 8.000000
    
    // 4.sqrt(double x) 用于返回double型变量的算术平方根
    double db5 = sqrt(2.0);
    printf("%f\n", db5); // 输出 1.414214
    
    // 5.log(double x)用于double型变量的以自然对数为底的对数
    double db6 = log(2.0);
    printf("%f.\n", db6); // 输出0.000000
    
    // 6.sin(double x)、cos(double x)、tan(double x)用于返回double型变量的正弦值、余弦值、正切值，参数要求弧度制
    const double pi = acos(-1.0);//cos(pi) = -1 ,2*pi = 360度。1度 = pi/180度
    double db7 = sin(45 * (pi / 180));
    double db8 = cos(45 * (pi / 180));
    double db9 = tan(45 * (pi / 180));
    printf("%f, %f, %f\n", db7, db8, db9); // 输出 0.707107, 0.707107, 1.000000
    
    // 7.asin(double x)、acos(double x)、atan(double x) 返回double型变量的反正弦值、反余弦值、反正切值
    double db10 = asin(1);
    double db11 = acos(-1.0);
    double db12 = atan(0);
    printf("%f, %f, %f\n", db10, db11, db12); // 输出 1.570796， 3.141593， 0.000000
    
    // 8.round(double x) 返回double型变量x的四舍五入，返回类型也是double型，需要进行取整
    double db13 = round(3.40);
    double db14 = round(3.45);
    double db15 = round(3.50);
    double db16 = round(3.55);
    double db17 = round(3.60);
    printf("%d, %d, %d, %d, %d\n", (int)db13, (int)db14, (int)db15, (int)db16, (int)db17); //输出 3, 3, 4, 4, 4
    
}
