//
//  PATBasicLevel.cpp
//  AlgorithmNote
//
//  Created by Joe on 2022/2/21.
//

#include "PATBasicLevel.hpp"
#include <iostream>
//#include <cstdio>
#include <cmath>
//#include <algorithm>

using namespace std;

void PATBasicLevel_1001() {
    int n, step = 0;
    scanf("%d", &n);
    while (n != 1) {
        if (n % 2 == 0) {
            n = n / 2;
        }else {
            n = (3 * n + 1) / 2;
        }
        step++;
    }
    printf("%d\n", step);
}

struct Student_1004 {
    char name[15];
    char id[15];
    int score;
} temp, ans_max, ans_min; // temp存放临时数据，ans_max为最高分数的学生，ans_min为最低分数的学生
void PATBasicLevel_1004() {
    int n;
    scanf("%d", &n);
    ans_max.score = -1;  //最高分数初始化为-1
    ans_min.score = 101; //最低分数初始化为101
    for (int i = 0; i < n; i++) {
        scanf("%s%s%d", temp.name, temp.id, &temp.score); // 除了字符串数组不需要&，其他类型赋值需要&
        if (temp.score > ans_max.score) {
            ans_max = temp; // 更新最高分数
        }
        if (temp.score < ans_min.score) {
            ans_min = temp; // 更新最低分数
        }
    }
    printf("%s %s\n", ans_max.name, ans_max.id);
    printf("%s %s\n", ans_min.name, ans_min.id);
}

bool cmp_1005(int a, int b) {
    return a > b;
}
void PATBasicLevel_1005() {
    int n, m, a[110];
    scanf("%d", &n);
    bool hashTable_1005[1000] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        m = a[i];
        while (m != 1) {
            if (m % 2 == 1) {
                m = (3 * m + 1) / 2;
            } else {
                m = m /2;
            }
            hashTable_1005[m] = true;
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (hashTable_1005[a[i]] == false) {
            count++;
        }
    }
    sort(a, a + n, cmp_1005);// 从大到小排列
    for (int i = 0; i < n; i++) {
        if (hashTable_1005[a[i]] == false) {
            printf("%d", a[i]);
            count--;
            if (count > 0) {
                printf(" ");
            }
        }
    }
}

// 1008. 数组元素循环右移问题 (20)
void PATBasicLevel_1008() {
    int a[110];
    int n, m, count = 0; // count 记录已经输出数的个数
    scanf("%d%d",&n, &m);
    m = m % n; //修正m，确保m < n
    for (int i = 0; i < n; i++) {
        scanf("%d",&a[i]);
    }
    
    for (int i = n - m; i < n; i++) {
        printf("%d", a[i]);
        count++;
        if (count < n) {
            printf(" ");
        }
    }
    
    for (int i = 0; i < n - m; i++) {
        printf("%d",a[i]);
        count++;
        if (count < n) {
            printf(" ");
        }
    }
}

// 1009. 说反话
void PATBasicLevel_1009() {
    //1、最简洁的方式
    /*
    int num = 0;
    char ans[90][90];// 把二维数组看作一维数组的元素也是一维数组
    while (scanf("%s", ans[num]) != EOF) {
        num++;// 单词个数加1
    }
    for (int i = num - 1; i >= 0; i--) {
        printf("%s", ans[i]);
        if (i > 0) {
            printf(" ");
        }
    }
    */
    // 2.常规方式
    char str[90];
    gets(str);
    size_t len = strlen(str), r = 0, h = 0; //r是行，h是列
    char ans[90][90]; //ans[0]~a[r]存放单词
    for (int i = 0; i < len; i++) {
        if (str[i] != ' ') {
            ans[r][h++] = str[i];// 不是空格，则存放在ans[r][h]中
        } else { // 是空格，说明一个单词结束
            ans[r][h] = '\0'; // 末尾是结束符\0
            r++;
            h = 0;
        }
    }
    for (int i = r; i >= 0; i--) {
        printf("%s", ans[i]);
        if (i > 0 ) {
            printf(" ");
        }
    }
}
// 1010.求导(公式：(X^n)' = nX^(n-1))
// XCode 结束scanf 输入EOF状态使用：先control + Q再control + D
// window 结束scanf 输入EOF状态使用：control + Z
void PATBasicLevel_1010() {
    int a[1010] = {0};
    int k, e, count = 0; // k 为系数，e为指数，count 计数不为0的导数项个数
    while (scanf("%d%d", &k, &e) != EOF) {
        a[e] = k;
    }
    a[0] = 0; // 0次项求导直接是0
    for (int i = 1; i <= 1000; i++) {
        a[i - 1] = a[i] * i; // 公式
        a[i] = 0; //求导后系数置0
        if (a[i - 1] != 0) {
            count++;
        }
    }
    if (count == 0) {
        printf("0 0");
    } else {
        for (int i = 1000; i >= 0; i--) {
            if (a[i] != 0) {
                printf("%d %d", a[i], i);
                count--;
                if (count != 0) {
                    printf(" ");
                }
            }
        }
    }

//    int a, b, flag = 0;
//    while (cin >> a >> b) {
//        if (b != 0) {
//            if (flag == 1) cout << " ";
//            cout << a * b << " " << b - 1;
//            flag = 1;
//        }
//    }
//    if (flag == 0) cout << "0 0";
}

// 1011. A+B和C (15)
void PATBasicLevel_1011() {
    int T, tcase = 1;
    scanf("%d", &T);
    while (T--) {
        long long a, b, c;
        scanf("%lld%lld%lld", &a, &b, &c);
        if (a + b > c) {
            printf("Case #%d: true\n", tcase++);
        } else {
            printf("Case #%d: false\n", tcase++);
        }
    }
}

void PATBasicLevel_1012() {
    int count[5] = {0};
    int ans[5] = {0};
    int n, temp;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d",&temp);
        if (temp % 5 == 0) {
            if (temp % 2 == 0) {
                ans[0] += temp;
                count[0]++;
            }
        }else if (temp % 5 == 1) {
            if (count[1] % 2 == 0) {
                ans[1] += temp;
            } else {
                ans[1] -= temp;
            }
            count[1]++;
        } else if (temp % 5 == 2) {
            count[2]++;
        } else if (temp % 5 == 3) {
            ans[3] += temp;
            count[3]++;
        } else {
            if (temp > ans[4]) {
                ans[4] = temp;
            }
            count[4]++;
        }
    }
    
    if (count[0] == 0) {
        printf("N ");
    } else {
        printf("%d ", ans[0]);
    }
    if (count[1] == 0) {
        printf("N ");
    } else {
        printf("%d ", ans[1]);
    }
    if (count[2] == 0) {
        printf("N ");
    } else {
        printf("%d ", count[2]);
    }
    if (count[3] == 0) {
        printf("N ");
    } else {
        printf("%.1f ",(double)ans[3] / count[3]);
    }
    if (count[4] == 0) {
        printf("N ");
    } else {
        printf("%d",ans[4]);
    }
    
}
void PATBasicLevel_1016() {
    long long a, b, da, db;
    scanf("%lld%lld%lld%lld",&a, &da, &b, &db);
    long long pa = 0, pb = 0;
    
    while (a != 0) {
        if (a % 10 == da) {
            pa = pa * 10 + da;
        }
        a = a / 10;
    }
    
    while (b != 0) {
        if (b % 10 == db) {
            pb = pb * 10 + db;
        }
        b = b / 10;
    }
    
    printf("%lld\n",pa + pb);
}

int change(char c) { //恰好是循环相克顺序且字典序递增
    if (c == 'B')  return 0;
    if (c == 'C')  return 1;
    if (c == 'J')  return 2;
    return -1;
}

void PATBasicLevel_1018() {
    char map[3] = {'B', 'C', 'J'};
    int n;
    scanf("%d", &n);
    int times_A[3] = {0}, times_B[3] = {0}; // 分别记录甲乙胜、平、负的次数
    int hand_A[3] = {0}, hand_B[3] = {0}; //按照BCJ顺序分别记录甲乙3种手势的获胜次数
    char c1, c2;
    int k1, k2;
    for (int i = 0; i < n; i++) {
        getchar(); //吸收换行符\n
        scanf("%c %c", &c1, &c2); //甲乙的手势
        k1 = change(c1);
        k2 = change(c2);
        if ((k1 + 1) % 3 == k2) { //甲胜
            times_A[0]++; // 甲胜次数加一
            times_B[2]++; // 乙负次数加一
            hand_A[k1]++; // 甲靠k1胜的次数加一
        } else if (k1 == k2) { //平局
            times_A[1]++; // 甲平局次数加一
            times_B[1]++; // 乙平局次数加一
        } else {
            times_A[2]++; // 甲负次数加一
            times_B[0]++; // 乙胜次数加一
            hand_B[k2]++; // 乙靠k2胜的次数加一
        }
    }
    
    printf("%d %d %d\n", times_A[0], times_A[1], times_A[2]);
    printf("%d %d %d\n", times_B[0], times_B[1], times_B[2]);
    
    int id1 = 0, id2 = 0;
    for (int i = 0; i < 3; i++) {
        if (hand_A[i] > hand_A[id1]) {
            id1 = i;
        }
        if (hand_B[i] > hand_B[id2]) {
            id2 = i;
        }
    }
    printf("%c %c\n", map[id1], map[id2]);// 转换回BCJ
}
struct mooncake {
    double store; // 库存量
    double sell; // 总售价
    double price;// 单价
} cake[1010];
bool cmp_mooncake(mooncake a, mooncake b) { // 按单价从高到低排列
    return a.price > b.price;
}
void PATBasicLevel_1020() {
    int n;
    double D;
    scanf("%d%lf", &n, &D);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &cake[i].store);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lf", &cake[i].sell);
        cake[i].price = cake[i].sell / cake[i].store;
    }
    sort(cake, cake + n, cmp_mooncake);
    double ans = 0;
    for (int i = 0; i < n; i++) {
        if (cake[i].store <= D) { // 需求量高于月饼库存量
            D -= cake[i].store; // 第i种月饼全部卖出
            ans += cake[i].sell;
        } else { // 月饼库存量高于需求量
            ans += cake[i].price * D; // 只卖出剩余需求量的月饼
            break;
        }
    }
    printf("%.2f\n", ans);
}

void PATBasicLevel_1023() {
    int count[10]; //记录数字0～9的个数
    for (int i = 0; i < 10; i++) {
        scanf("%d", &count[1]);
    }
    for (int i = 1; i < 10; i++) {
        if (count[i] > 0) {
            printf("%d", i);
            count[i]--;
            break;
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < count[i]; j++) {
            printf("%d", i);
        }
    }
}

void PATBasicLevel_1022() {
    int a,b,d;
    scanf("%d%d%d", &a, &b, &d);
    int sum = a + b;
    int ans[31], num = 0;
    do {
        ans[num++] = sum % d;
        sum /= d;
    } while (sum != 0);
    for (int i = num - 1; i >= 0; i--) {
        printf("%d", ans[i]);
    }
}

void PATBasicLevel_1026() {
    int c1, c2;
    scanf("%d%d",&c1, &c2);
    int ans = c2 - c1;
    if (ans % 100 >= 50) {
        ans = ans / 100 + 1;
    }else {
        ans = ans / 100;
    }
    
    printf("%02d:%02d:%02d\n", ans / 3600, ans % 3600 / 60, ans % 60);
}

void PATBasicLevel_1027() {
    int n;
    char c;
    scanf("%d %c", &n, &c);
    int bottom = (int)sqrt(2.0 * (n + 1)) - 1;//三角形底部拥有的字符数
    if (bottom % 2 == 0) {
        bottom--; // 偶数时减1，变为奇数
    }
    int used = (bottom + 1) * (bottom + 1) / 2 - 1; //总共输出的非空格字符数
    // 输出倒三角
    for (int i = bottom; i >= 1; i -= 2) { //i为当前行的非空格
        for (int j = 0; j < (bottom - i) / 2; j++) {
            printf(" "); // 空格数为（bottom - i）/2
        }
        for (int j = 0; j < i; j++) {
            printf("%c",c);
        }
        printf("\n");
    }
    //输出正三角
    for (int i = 3; i <= bottom; i += 2) {
        for (int j = 0; j < (bottom - i) / 2; j++) {
            printf(" "); //
        }
        for (int j = 0; j < i; j++) {
            printf("%c",c);
        }
        printf("\n");
    }
    printf("%d\n", n - used);
}

struct Person_1028 {
    char name[10];  //姓名
    int yy, mm, dd; //日期
} oldest_p, youngest_p, left_p, right_p, temp_p; // oldest和youngest存放最年长、最年轻的人，left和right存放合法日期的左右边界

bool lessEqu(Person_1028 a, Person_1028 b) { // 如果a的日期小于等于b，返回true
    if (a.yy != b.yy) {
        return a.yy <= b.yy;
    } else if (a.mm != b.mm) {
        return a.mm <= b.mm;
    } else {
        return a.dd <= b.dd;
    }
}

bool MoreEqu(Person_1028 a, Person_1028 b) { // 如果a的日期大于等于b，返回true
    if (a.yy != b.yy) {
        return a.yy >= b.yy;
    } else if (a.mm != b.mm) {
        return a.mm >= b.mm;
    } else {
        return a.dd >= b.dd;
    }
}

void init() {
    youngest_p.yy = left_p.yy = 1814;
    oldest_p.yy = right_p.yy = 2014;
    youngest_p.mm = oldest_p.mm = left_p.mm = right_p.mm = 9;
    youngest_p.dd = oldest_p.dd = left_p.dd = right_p.dd = 6;
}
    
void PATBasicLevel_1028() {
    init();
    int n, num = 0; // n 为输出人数，num存放合法日期的人数
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %d/%d/%d", temp_p.name, &temp_p.yy, &temp_p.mm, &temp_p.dd);
        if (MoreEqu(temp_p, left_p) && lessEqu(temp_p, right_p)) { // 日期合法
            num++;
            if (lessEqu(temp_p, oldest_p)) {
                oldest_p = temp_p;
            }
            if (MoreEqu(temp_p, youngest_p)) {
                youngest_p = temp_p;
            }
        }
    }
    
    if (num == 0) {
        printf("0\n"); //所有人的日期不合法只输出0
    } else {
        printf("%d %s %s\n", num, oldest_p.name, youngest_p.name);
    }
}

void PATBasicLevel_1029() {
    char str1[100], str2[100];
    bool hashTable[128] = {false}; // ascii 总共128个字符，数组用来标记字符是否已被输出
    gets(str1);
    gets(str2);
    size_t len1 = strlen(str1); // 获取长度
    size_t len2 = strlen(str2);
    for (int i = 0; i < len1; i++) { //枚举第一个字符串中的每个字符
        int j;
        char c1, c2;
        for (j = 0; j < len2; j++) { //枚举第二个字符串中的每个字符
            c1 = str1[i];
            c2 = str2[j];
            if (c1 >= 'a' && c1 <= 'z') { // 小写字母转成大写字母，小写和大写之间相差32，a==97，A==65
                c1 -= 32;
            }
            if (c2 >= 'a' && c2 <= 'z') {
                c2 -= 32;
            }
            if (c1 == c2) { // 如果c1在第二个字符串中出现，跳出当前j循环，往下i循环执行下一个c1字符的遍历对比，并且j会重新为0
                break;
            }
        }
        printf("j==%d",j);
        if (j == len2 && hashTable[c1] == false) {
            printf("%c",c1); //在第二个字符串中未出现c1，且c1未被输出过
            hashTable[c1] = true;
        }
    }
}

const int maxn = 100010;
int school[maxn] = {0};
void PATBasicLevel_1032() {
    int n, schID, score;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &schID, &score);
        school[schID] += score;
    }
    int k = 1, MAX = -1;
    for (int i = 1; i <= n; i++) {
        if (school[i] > MAX) {
            MAX = school[i];
            k = i;
        }
    }
    printf("%d %d\n", k, MAX);
    
}

const int maxn_1033 = 100010;
bool hashTabel_1033[256]; // 散列数组，记录键盘上字符是否完好
char str_1033[maxn_1033];
void PATBasicLevel_1033() {
    memset(hashTabel_1033, true, sizeof(hashTabel_1033)); // 初值为true表示所有键完好
    gets(str_1033); // 读入所有失效的键位
    size_t len = strlen(str_1033);
    for (int i = 0; i < len; i++) {
        if (str_1033[i] >= 'A' && str_1033[i] <= 'Z') { // 如果是大写字母，则转换成小写字母
            str_1033[i] = str_1033[i] - 'A' + 'a';
        }
        hashTabel_1033[str_1033[i]] = false; // 设置键位失效
    }
    gets(str_1033); // 读入欲输入的字符串
    len = strlen(str_1033);
    for (int i = 0; i < len; i++) {
        if (str_1033[i] >= 'A' && str_1033[i] <= 'Z') {
            int low = str_1033[i] - 'A' + 'a'; //大写转换小写
            if (hashTabel_1033[low] == true && hashTabel_1033['+'] == true) {
                printf("%c", str_1033[i]); // 只有小写字母的键位与上档键均完好，才能输出
            }
        } else if (hashTabel_1033[str_1033[i]] == true) {
            printf("%c", str_1033[i]); // 对于其他字符，只要键盘位完好，就能输出
        }
    }
    printf("\n");// 最后换行输出
}

void PATBasicLevel_1036() {
    int row, col; // 行和列
    char c;
    scanf("%d %c",&col, &c);
    if (col % 2 == 1) {
        row = col / 2 + 1;// col为奇数，向上取整
    } else {
        row = col / 2; //col 为偶数
    }
    // 第一行
    for (int i = 0; i < col; i++) {
        printf("%c",c);
    }
    printf("\n");
    //第2～row-1行
    for (int i = 2; i < row; i++) {
        printf("%c",c); //每行第一个a
        for (int j = 0; j < col - 2; j++) {
            printf(" "); // col - 2个空格
        }
        printf("%c\n",c);//每行最后一个a
    }
    //第row行
    for (int i = 0; i < col; i++) {
        printf("%c",c);
    }
}

void PATBasicLevel_1037() {
    
}

int hashTable_1038[110] = {0};
void PATBasicLevel_1038() {
    int n, score, k;
    scanf("%d", &n); // 学生数
    for (int i = 0; i < n; i++) {
        scanf("%d", &score); // 分数
        hashTable_1038[score]++; // 分数score出现次数加1
    }
    
    scanf("%d", &k);// 查询次数
    for (int i = 0; i < k; i++) {
        scanf("%d", &score);
        printf("%d", hashTable_1038[score]); // 分数出现的次数
        if (i < k - 1) { // 前k - 1 个后面输出空格
            printf(" ");
        }
    }
}

const int maxn_1039 = 1010; // 两串珠子不超过1000个
int hashTable_1039[80] = {0}, miss_1039 = 0; // 大小写字符加上数字共62个
int change_1039(char c) {// 将数字和字母转换成hashTable下标
    if (c >= '0' && c <= '9') return c - '0'; // 数字
    if (c >= 'a' && c <= 'z') return c - 'a' + 10; // 小写字母
    if (c >= 'A' && c <= 'Z') return c - 'A' + 36; // 大写字母
    return 0;
}

void PATBasicLevel_1039() {
    char whole[maxn_1039], target[maxn_1039];
    gets(whole); // 第一串
    gets(target);// 第二串
    size_t len1 = strlen(whole);
    size_t len2 = strlen(target);
    for (int i = 0; i < len1; i++) {
        int id = change(whole[i]);
        hashTable_1039[id]++;
    }
    for (int i = 0; i < len2; i++) {
        int id = change(target[i]);
        hashTable_1039[id]--;
        if (hashTable_1039[id] < 0) {
            miss_1039++;
        }
    }
    if (miss_1039 > 0) {
        printf("No %d\n", miss_1039);// 有缺少
    } else {
        printf("Yes %lu\n", len1 - len2);// 有多余
    }
    
}

const int max_n = 1010;
struct Student {
    long long id;    //准考证号
    int examSeat;    //考试座位号
} testSeat[max_n];   //以试机座位号作为下标记录考生
void PATBasicLevel_1041() {
    int n, m, seat, examSeat;
    long long id;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld %d %d", &id, &seat, &examSeat);
        testSeat[seat].id = id;
        testSeat[seat].examSeat = examSeat;
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &seat);
        printf("%lld %d\n", testSeat[seat].id, testSeat[seat].examSeat);
    }
}

const int maxn_1042 = 1010;
char str_1042[maxn_1042];// 字符串
int hashTable_1042[30] = {0}; // 记录大小写字母出现的次数，不区分大小写
void PATBasicLevel_1042() {
    gets(str_1042);
    size_t len = strlen(str_1042);
    for (int i = 0; i < len; i++) {
        if (str_1042[i] >= 'a' && str_1042[i] <= 'z') { // 是小写字母
            hashTable_1042[str_1042[i] - 'a']++;
        } else if (str_1042[i] >= 'A' && str_1042[i] <= 'Z') { // 是大写字母
            hashTable_1042[str_1042[i] - 'A']++;
        }
    }
    int k = 0; // 记录数组中最大元素的下标
    for (int i = 0; i < 26; i++) {
        if (hashTable_1042[i] > hashTable_1042[k]) {
            k = i;
        }
    }
    printf("%c %d\n", 'a' + k, hashTable_1042[k]);
}

const int maxn_1043 = 10010;
// 字符串、字典
char str_1043[maxn_1043], dict[6] = {'P', 'A', 'T', 'e', 's', 't'};
int hashTable_1043[6] = {0}; // 记录PATest这6个字符的个数
void PATBasicLevel_1043() {
    gets(str_1043);
    size_t len = strlen(str_1043), sum = 0; // 长度，总共需要输出的字符个数
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < 6; j++) {
            if (str_1043[i] == dict[j]) { // str[i]在字典中下标为j
                hashTable_1043[j]++;
                sum++;
            }
        }
    }
    while (sum > 0) { // 当输出的字符个数变成0时推出
        for (int i = 0; i < 6; i++) {
            if (hashTable_1043[i] > 0) {
                printf("%c", dict[i]);
                hashTable_1043[i]--;
                sum--;
            }
        }
    }
}

void PATBasicLevel_1046() {
    int n, failA = 0, failB = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a1, a2, b1, b2;
        scanf("%d%d%d%d", &a1, &a2, &b1, &b2);
        if (a1 + b1 == a2 && a1 + b1 != b2) {
            failB++;
        }else if (a1 + b1 != a2 && a1 + b1 == b2) {
            failA++;
        }
    }
    printf("%d %d\n", failA, failB);
}

const int maxn_1047 = 1010;
int hashTable_1047[maxn_1047] = {0};
void PATBasicLevel_1047() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int team, member, score;
        scanf("%d-%d %d", &team, &member, & score);
        hashTable_1047[team] += score;
    }
    int k = 0, MAX = -1;
    for (int i = 0; i < maxn_1047; i++) {
        if (hashTable_1047[i] > MAX) {
            k = i;
            MAX = hashTable_1047[i];
        }
    }
    printf("%d %d\n", k, MAX);
    
}
