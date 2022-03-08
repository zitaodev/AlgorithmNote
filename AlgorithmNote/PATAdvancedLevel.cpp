//
//  PATAdvancedLevel.cpp
//  AlgorithmNote
//
//  Created by Joe on 2022/2/22.
//

#include "PATAdvancedLevel.hpp"
#include <algorithm>
#include <cstring>
using namespace std;

// 1002. A+B for polynomials (25)
const int max_n = 1111;
double p[max_n];
void PATAdvancedLevel_1002() {
    int k, n, count = 0;
    double a;
    scanf("%d",&k);
    for (int i = 0; i < k; i++) {
        scanf("%d %lf", &n, &a);
        p[n] += a;
    }
    
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d %lf", &n, &a);
        p[n] += a;
    }
    
    for (int i = 0; i < max_n; i++) {
        if (p[i] != 0) {
            count++;
        }
    }
    printf("%d ", count);
    for (int i = max_n; i >= 0; i--) {
        if (p[i] != 0) {
            printf(" %d %.1f", i, p[i]);
        }
    }
}

struct pNode {
    char id[20];
    int hh, mm, ss;
} temp_pN, ans_fst, ans_lat; // ans_fst 存放最早签到时间, ans2_lat 存放最晚签离时间

bool great(pNode node1, pNode node2) { // node1的时间大于node2的时间则返回true
    if (node1.hh != node2.hh) {
        return node1.hh > node2.hh;
    }
    if (node1.mm != node2.mm) {
        return node1.mm > node2.mm;
    }
    return node1.ss > node2.ss;
}
void PATAdvancedLevel_1006() {
    int n;
    scanf("%d", &n);
    // 把最早签到的时间初始化最大
    ans_fst.hh = 24;
    ans_fst.mm = 60;
    ans_fst.ss = 60;
    // 把最晚签离的时间初始化最小
    ans_lat.hh = 0;
    ans_lat.mm = 0;
    ans_lat.ss = 0;
    for (int i = 0; i < n; i++) {
        scanf("%s %d:%d:%d", temp_pN.id, &temp_pN.hh, &temp_pN.mm, &temp_pN.ss);
        if (great(temp_pN, ans_fst) == false) {
            ans_fst = temp_pN;
        }
        scanf("%d:%d:%d", &temp_pN.hh, &temp_pN.mm, &temp_pN.ss);
        if (great(temp_pN, ans_lat)) {
            ans_lat = temp_pN;
        }
    }
    printf("%s %s\n", ans_fst.id, ans_lat.id);
}

// 1009
struct Poly {
    int exp; //指数
    double cof; // 系数
} poly[1001];// 第一个多项式
double ans[2001]; // 存放最终结果
void PATAdvancedLevel_1009() {
    int n, m, number = 0;
    scanf("%d", &n);// 第一个多项式中非零系数的项数
    for (int i = 0; i < n; i++) {
        scanf("%d %lf", &poly[i].exp, &poly[i].cof);// 第一个多项式的指数和系数
    }
    scanf("%d", &m); // 第二个多项式中非零系数的项数
    for (int i = 0; i < m; i++) {
        int exp;
        double cof;
        scanf("%d %lf", &exp, &cof); // 第二个多项式的指数和系数
        
        for (int j = 0; j < n; j++) {
            ans[exp + poly[j].exp] += (cof * poly[j].cof);
        }
    }
    for (int i = 0; i < 2000; i++) {
        if (ans[i] != 0.0) {
            number++; //累计非零系数的项数
        }
    }
    printf("%d", number);
    
    for (int i = 2000; i >= 0; i--) {
        if (ans[i] != 0.0) {
            printf(" %d %.1f", i, ans[i]);
        }
    }
    
}

char S[3] = {'W', 'T', 'L'};
void PATAdvancedLevel_1011() {
    double ans = 1.0, tmp, a;
    int flag[3];
    for (int i = 0; i < 3; i++) {
        tmp = 0.0;
        for (int j = 0; j < 3; j++) {
            scanf("%lf", &a);
            if (a > tmp) {
                tmp = a;
                flag[i] = j;
            }
        }
        ans *= tmp;
    }
    for (int i = 0; i < 3; i++) {
        printf("%c ", S[flag[i]]);
    }
    printf("%.2f", (ans * 0.65 - 1) * 2);
    
    
    
}

void PATAdvancedLevel_1022() {
    int a, b, d;
    scanf("%d%d%d", &a, &b, &d);
    int sum = a + b;
    int ans[31], num = 0;
    do {
        ans[num++] = sum % d;
        sum /= d;
    } while (sum != 0);
    for (int i = num - 1; i >= 0; i--) {
        printf("%d",ans[i]);
    }
}

struct student_1025 {
    ///准考证
    char id[15];
    ///分数
    int score;
    ///考场号
    int location_number;
    ///考场内排名
    int local_rank;
} stu[30010];
bool cmp_1025 (student_1025 a, student_1025 b) {
    if (a.score != b.score) {
        return a.score > b.score; // 先按照分数从高到低排序
    } else {
        return  strcmp(a.id, b.id) < 0; // 分数相同按照准考证号从小到大排序
    }
}
void PATAdvancedLevel_1025() {
    int n, k, num = 0; // num是总考生数
    scanf("%d", &n); // n 是考场数
    for (int i = 1; i <= n; i++) {
        scanf("%d", &k); // 该考场人数
        for (int j = 0; j < k; j++) {
            scanf("%s %d", stu[num].id, &stu[num].score);
            stu[num].location_number = i; // 该考生的考场号为i
            num++; // 总考生数加1
        }
        // 该考场考生排序
        // sort(首元素地址(必填), 尾元素地址的下一个地址(必填), 比较函数(非必填))，如a[0] ~ a[3]从小到达排序：sort(a, a+4)
        sort(stu + num - k, stu + num, cmp_1025);// num是每读入一个考生就记录一次的考生总数，读完一个考场的k个考生后，这个考场对应的数组下标区间是[num - k, num)
        stu[num - k].local_rank = 1; // 此时stu数组已经排序好，该考场第一名的local_rank记为1
        for (int j = num - k + 1; j < num; j++) {// 该考场除了第一名外剩余考生
            if (stu[j].score == stu[j - 1].score) { // 如果与前一个考生的分数相同，则是相同排名
                stu[j].local_rank = stu[j - 1].local_rank;
            } else {
                stu[j].local_rank = j - (num - k) + 1;// 该考生前的人数
            }
        }
    }
    printf("%d\n", num); // 总考生人数
    sort(stu, stu + num, cmp_1025); // 所有考生排名排序
    int r = 1; // 当前考生在总考生人数中的排名
    for (int i = 0; i < num; i++) {
        if (i > 0 && stu[i].score != stu[i - 1].score) {
            r = i + 1; // 当前考生与上一个考生分数不同时，r更新为人数+1
        }
        printf("%s ", stu[i].id);
        printf("%d %d %d\n", r , stu[i].location_number, stu[i].local_rank);
    }
}

void PATAdvancedLevel_1031() {
    // 1、二维数组方式
    
    char str[100], ans[40][40];
    gets(str);
    int N = (int)strlen(str);
    int n1 = (N + 2) / 3, n3 = n1, n2 = N + 2 - n1 - n3; // 公式
    for (int i  = 0; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            ans[i][j] = ' ';//初始化，数组赋值空格
        }
    }
    int pos = 0; //pos 从0开始使用str数组
    for (int i = 0; i <= n1; i++) {
        ans[i][1] = str[pos++]; // 从上往下赋值左侧n1个字符
    }
    for (int j = 2; j <= n2; j++) {
        ans[n1][j] = str[pos++]; //从左往右赋值底部n2 - 1个字符（去掉最左端字符）
    }
    for (int i = n3 - 1; i >= 1; i--) {
        ans[i][n2] = str[pos++]; //从下往上赋值右侧n3 - 1个字符（去掉最下端字符）
    }
    for (int i = 1; i <= n1; i++) {
        for (int j = 0; j <= n2; j++) {
            printf("%c",ans[i][j]);// 输出整个二维数组
        }
        printf("\n");
    }
    
    // 2、直接输出方式
    /*
    char str[100];
    gets(str);
    int N = strlen(str);
    int n1 = (N  + 2) / 3, n3 = n1, n2 = N + 2 - n1 - n3;
    for (int i = 0; i < n1 - 1; i++) {
        printf("%c", str[i]); //输出当前行的左侧字符
        for (int j = 0; j < n2 - 2; j++) {
            printf(" "); //输出n2 - 2个字符
        }
        printf("%c\n", str[N - i - 1]); //输出当前行右侧字符
    }
    for (int i = 0; i < n2; i++) {
        printf("%c",str[n1 + i - 1]); //输出底部的n个字符
    }
    printf("\n");
     */
}


struct student_1036 {
    char name[15];
    char id[15];
    int score;
} Male, Female, temp_stu; // Male 为男生最低分数信息，Female为女生最高分数信息
void init_1036() {
    Male.score = 101; // 男生最低分数初始化为较大值101
    Female.score = -1; //女生最高分数初始化为较小值-1
}
void PATAdvancedLevel_1036() {
    init_1036();
    int n;
    char gender;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %c %s %d", temp_stu.name, &gender, temp_stu.id, &temp_stu.score);
        if (gender == 'M' && temp_stu.score < Male.score) {
            Male = temp_stu;
        } else if (gender == 'F' && temp_stu.score > Female.score) {
            Female = temp_stu;
        }
    }
    if (Female.score == -1) {
        printf("Absent\n");
    } else {
        printf("%s %s\n", Female.name, Female.id);
    }
    if (Male.score == 101) {
        printf("Absent\n");
    } else {
        printf("%s %s\n", Male.name, Male.id);
    }
    if (Female.score == -1 || Male.score == 101) {
        printf("NA\n");
    } else {
        printf("%d\n", Female.score - Male.score);
    }
}

int a_1041[100001], hashTable_1041[100001] = {0};
void PATAdvancedLevel_1041() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a_1041[i]);
        hashTable_1041[a_1041[i]]++;
    }
    int ans = -1;
    for (int i = 0; i < n; i++) {
        if (hashTable_1041[a_1041[i]] == 1) {
            ans = a_1041[i];
            break;
        }
    }
    if (ans == -1) {
        printf("None");
    } else {
        printf("%d\n", ans);
    }
}

void PATAdvancedLevel_1042() {
    const int N = 54;
    char map[5] = {'S', 'H', 'C', 'D', 'J'}; //牌的编号与花色的对应关系
    int star[N+1], end[N+1],next[N+1]; //next数组存放每个位置的牌在操作后的位置
    
    int K;
    scanf("%d", &K);
    for (int i = 1; i <= N; i++) {
        star[i] = i; //初始化花牌的编号
    }
    for (int i = 1; i <= N; i++) {
        scanf("%d", &next[i]); //输入每个位置上的牌在操作后的位置
    }
    for (int step = 0; step < K; step++) { //执行k次操作
        for (int i = 1; i <= N; i++) {
            end[next[i]] = star[i]; // 把第i个位置的牌的编号存在位置next[i]
        }
        for (int i = 1; i <= N; i++) {
            star[i] = end[i];
        }
    }
    for (int i = 1; i <= N; i++) {
        if (i != 1) {
            printf(" ");
        }
        star[i]--;
        printf("%c%d", map[star[i] / 13], star[i] % 13 + 1);
    }
}

void PATAdvancedLevel_1046() {
    const int MAXN = 100005;
    int dis[MAXN], A[MAXN]; // dis[i]是1号结点到达i结点下一个节点的距离，A[i]存放i号结点与i+1号结点的结点的距离
    int sum = 0, query, n, left, right;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d",&A[i]); // 输入两个结点间的距离
        sum += A[i]; // 结点总距离
        dis[i] = sum; //预处理dis数组
    }
    scanf("%d", &query);
    for (int i = 0; i < query; i++) {
        scanf("%d%d",&left, &right);
        if (left > right) {
            swap(left, right);
        }
        int temp = dis[right - 1] - dis[left - 1];
        printf("%d\n", min(temp, sum - temp));
    }
}

const int N_1048 = 1005;
int hashTable_1048[N_1048];
void PATAdvancedLevel_1048() {
    int n, m, a;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        hashTable_1048[a]++;
    }
    for (int i = 0; i < N_1048; i++) {
        if (hashTable_1048[i] && hashTable_1048[m - i]) {
            if (i == m - i && hashTable_1048[i] <= 1) {
                continue;
            }
            printf("%d %d\n", i, m - i);
            return;
        }
    }
    printf("No solution\n");
    
}
const int MAX_LEN = 10005;
char a_1050[MAX_LEN], b_1050[MAX_LEN];
bool hashTable_1050[128]; // 记录字符是否在第二个字符串中出现过
void PATAdvancedLevel_1050() {
    gets(a_1050);
    gets(b_1050);
    size_t lenA = strlen(a_1050);
    size_t lenB = strlen(b_1050);
    for (int i = 0; i < lenB; i++) {
        hashTable_1050[b_1050[i]] = true;
    }
    for (int i = 0; i < lenA; i++) {
        if (hashTable_1050[a_1050[i]] == false) {
            printf("%c", a_1050[i]);
        }
    }
}

void PATAdvancedLevel_1065() {
    int T, tscase = 1;
    scanf("%d",&T);
    
    while (T--) {
        long long a, b, c;
        scanf("%lld%lld%lld",&a, &b, &c);
        long long ans = a + b;
        bool flag;
        if (a > 0 && b > 0 && ans < 0) {
            flag = true;
        } else if (a < 0 && b < 0 && ans >= 0) {
            flag = false;
        } else if (ans > c) {
            flag = true;
        } else {
            flag = false;
        }
        if (flag == true) {
            printf("Case #%d: true\n", tscase++);
        } else {
            printf("Case #%d: false\n", tscase++);
        }
        
    }
}




