//
//  main.cpp
//  AlgorithmNote
//
//  Created by Joe on 2022/2/17.
//

#include <cstdio>
#include <algorithm>
#include <iostream>
#include "PATBasicLevel.hpp"
#include "PATAdvancedLevel.hpp"
#include "Codeup.hpp"
#include "Sort.hpp"
#include <math.h>
using namespace std;

void math_func();
void sort();
void algorithm_practice();

int main(int argc, const char * argv[]) {
    algorithm_practice();
    return 0;
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

// 排序算法
void sort() {
//    bubbleSort();
//    selectSort();
    insertSort();
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

// AlgorithmNote-上机训练实战
void algorithm_practice() {
    /*****************3.1 简单模拟*****************/
    //    PATBasicLevel_1001();// 1001. 害死人不偿命的(3n+1)猜想 (15)
    //    PATBasicLevel_1011();// 1011.a + b 和 c
    //    PATBasicLevel_1016();// 1016.部分a+b
    //    PATBasicLevel_1026();// 1026.程序运行时间
    //    PATBasicLevel_1046();// 1046.划拳
    //    PATBasicLevel_1008();// 1008.数组元素循环右移问题
    //    PATBasicLevel_1012();// 1012.数字分类
    //    PATBasicLevel_1018();// 1018.锤子剪刀布
    //    PATAdvancedLevel_1042(); // 1042.shuffling machine
    //    PATAdvancedLevel_1046();// 1046.shortest distance
    //    PATBasicLevel_1010();// 1010.一元多项式求导
    //    PATAdvancedLevel_1002();// 1002.a + b for polynomials
    //    PATAdvancedLevel_1009(); // Product of Polynomials
        
    /*****************3.2 查找元素*****************/
    //    PATBasicLevel_1041();    // 考试座位号
    //    PATBasicLevel_1004();    // 成绩排名
    //    PATBasicLevel_1028();    // 人口普查
    //    PATBasicLevel_1032();    // 挖掘机技术哪家强
    //    PATAdvancedLevel_1011(); // World Cup Betting
    //    PATAdvancedLevel_1006(); // Sign in and Sign out
    //    PATAdvancedLevel_1036(); // Boys VS Girls
        
    /*****************3.3 图形输出*****************/
    //    PATBasicLevel_1036(); // 跟着奥巴马一起编程
    //    PATBasicLevel_1027(); // 打印沙漏
//        PATAdvancedLevel_1031();// Hello World for U
        
    /*****************3.5 进制转换*****************/
    
    /*****************3.6 字符串处理*****************/
//    Codeup_5901();
//    PATBasicLevel_1009();
    
    /*****************4.2 散列*****************/
    // B1029/A1084.旧键盘
//    PATBasicLevel_1029();
    // B1033.旧键盘打字
//    PATBasicLevel_1033();
    // B1038.统计同成绩学生
//    PATBasicLevel_1038();
    // B1039/A1092.到底买不买
//    PATBasicLevel_1039();
    // B1042.字符统计
//    PATBasicLevel_1042();
    // B1043.输出PATest
//    PATBasicLevel_1043();
    // B1047.编程团体赛
//    PATBasicLevel_1047();
    // A1041.Be Unique
//    PATAdvancedLevel_1041();
    // A1050.String Subtraction
//    PATAdvancedLevel_1050();
    // B1005.继续（3n+1）猜想
//    PATBasicLevel_1005();
    // A1048.Find Coins
//    PATAdvancedLevel_1048();
    /*****************4.3 递归*****************/
    
    /*****************4.4 贪心*****************/
    // B1023.组个最小数
    // B1020/A1070.月饼
    // A1033.To Fill or Not to Fill
    // A1037.Magic Coupon
    // A1067.Sort with Swap(0,*)
    // A1038.Recover the Smallest Number
    
    /*****************4.5 二分*****************/
    // B1030/A1085.完美数列
    // A1010.Radix
    // A1044.Shopping in Mars
    // A1048.Find Coins
    
    /*****************4.6 two pointers*****************/
    // B1030/A1085.完美数列
    // B1035/A1089.Insert or Merge
    // A1029.Median
    // A1048.Find Coins
    
    /*****************4.7 其他高效技巧与算法*****************/
    // B1040/A1093.有几个PAT
    // B1045/A1101.快速排序
}
