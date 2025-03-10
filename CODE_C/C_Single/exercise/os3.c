#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 

#define W 5 // 最大进程数 W=5
#define R 3 // 最大资源总数 R=3

// 数据结构定义
int Available[R] = {3, 3, 2};    // 初始可利用资源向量
int Max[W][R] = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}};  // 最大需求矩阵
int Allocation[W][R] = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}};  // 初始分配矩阵

int Need[W][R];  // 需求矩阵
int Request[R];  // 进程请求向量

// 初始化进程的 Need 矩阵
void initializeNeed() {
    for (int i = 0; i < W; i++)
        for (int j = 0; j < R; j++)
            Need[i][j] = Max[i][j] - Allocation[i][j];
}

// 检查请求是否合法
bool isRequestValid(int processId) {
    for (int i = 0; i < R; i++) {
        if (Request[i] > Need[processId][i] || Request[i] > Available[i]) {
            printf("进程%d的请求不合法，超过最大需求或可利用资源。\n", processId);
            return false;
        }
    }
    return true;
}

// 预分配资源
void preAllocateResources(int processId) {
    for (int i = 0; i < R; i++) {
        Available[i] -= Request[i];
        Allocation[processId][i] += Request[i];
        Need[processId][i] -= Request[i];
    }
}

// 回滚到原状态
void rollbackState(int processId) {
    for (int i = 0; i < R; i++) {
        Available[i] += Request[i];
        Allocation[processId][i] -= Request[i];
        Need[processId][i] += Request[i];
    }
}

// 执行安全性算法检查
bool isSafeState() {
    int Work[R];
    bool Finish[W];

    // 初始化Work向量和Finish数组
    for (int i = 0; i < R; i++)
        Work[i] = Available[i];

    for (int i = 0; i < W; i++)
        Finish[i] = false;

    // 安全性算法检查
    int count = 0;
    while (count < W) {
        bool found = false;
        for (int i = 0; i < W; i++) {
            if (!Finish[i]) {
                // 检查是否满足条件
                bool canAllocate = true;
                for (int j = 0; j < R; j++) {
                    if (Need[i][j] > Work[j]) {
                        canAllocate = false;
                        break;
                    }
                }

                if (canAllocate) {
                    // 分配资源
                    for (int j = 0; j < R; j++)
                        Work[j] += Allocation[i][j];

                    Finish[i] = true;
                    found = true;
                    count++;
                    printf("进程%d执行完毕，释放资源。\n", i);
                    // 输出当前系统状态
                    printf("当前可利用资源：{%d, %d, %d}\n", Work[0], Work[1], Work[2]);
                }
            }
        }

        if (!found) {
            // 未找到满足条件的进程，系统处于不安全状态
            return false;
        }
    }

    // 所有进程都执行完毕，系统处于安全状态
    return true;
}

int main() {
    initializeNeed();

    // 在这里可以继续编写后续步骤的代码，包括资源请求处理等。
    // 假设用户请求的进程编号为processId
    int processId;
    printf("请输入请求资源的进程编号：\n");
    scanf("%d", &processId);

    // 输入进程的请求向量
    printf("请输入进程%d的资源请求向量(格式:a,b,c)\n", processId);
    if (scanf("%d,%d,%d", &Request[0], &Request[1], &Request[2]) != 3) {
        printf("输入格式错误，请重新输入。\n");
        return 1;
    }

    // 检查请求是否合法
    if (isRequestValid(processId)) {
        // 预分配资源
        preAllocateResources(processId);

        // 执行安全性算法检查
        if (isSafeState()) {
            printf("资源分配成功，当前系统状态如下：\n");
            // 输出当前系统状态
            // ...
        } else {
            printf("资源分配失败，系统处于不安全状态，回滚到原状态。\n");
            // 回滚到原状态
            rollbackState(processId);
        }
    } else {
        printf("资源请求失败，系统状态未改变。\n");
    }
    system("pause");
    return 0;
}
