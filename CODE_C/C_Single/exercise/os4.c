#include <stdio.h>
#include <stdlib.h>

// 定义内存总大小
#define TOTAL_MEMORY_SIZE 640

// 定义空闲分区结构体
struct FreeBlock {
    int startAddress;
    int size;
    struct FreeBlock* next;
};

// 定义已用分区结构体
struct UsedBlock {
    int startAddress;
    int size;
    int jobId;  // 作业编号
    struct UsedBlock* next;
};

// 初始化空闲分区链表
struct FreeBlock* freeList = NULL;

// 动态分区分配函数（首次适应算法）
struct UsedBlock* allocateFirstFit(int jobId, int size) {
    struct FreeBlock* current = freeList;
    struct UsedBlock* allocatedBlock = NULL;

    while (current != NULL) {
        if (current->size >= size) {
            // 找到足够大的空闲块，进行分配
            allocatedBlock = (struct UsedBlock*)malloc(sizeof(struct UsedBlock));
            allocatedBlock->startAddress = current->startAddress;
            allocatedBlock->size = size;
            allocatedBlock->jobId = jobId;

            // 更新空闲分区链表
            current->startAddress += size;
            current->size -= size;

            break;
        }

        current = current->next;
    }

    return allocatedBlock;
}

// 回收内存函数
void freeMemory(struct UsedBlock* block) {
    // 在这里实现回收内存的逻辑
    // ...

    // 可能涉及到合并空闲块等操作
}

// 显示空闲分区和已分配区域的情况
void displayMemoryStatus() {
    printf("空闲分区情况：\n");
    struct FreeBlock* currentFree = freeList;
    while (currentFree != NULL) {
        printf("起始地址：%d，大小：%d\n", currentFree->startAddress, currentFree->size);
        currentFree = currentFree->next;
    }

    printf("\n已分配区域情况：\n");
    // 在这里添加显示已分配区域的逻辑
    // ...
}

// 交互式输入申请操作
void interactiveAllocate() {
    int jobId, size;
    printf("请输入作业编号和空间大小（格式：编号 大小）：");
    scanf("%d %d", &jobId, &size);

    struct UsedBlock* allocatedBlock = allocateFirstFit(jobId, size);

    if (allocatedBlock != NULL) {
        printf("作业%d成功分配内存，起始地址：%d，大小：%d\n", jobId, allocatedBlock->startAddress, allocatedBlock->size);
    } else {
        printf("分配失败，没有足够的空闲内存\n");
    }
}

// 交互式输入释放操作
void interactiveFree() {
    int jobId;
    printf("请输入要释放的作业编号：");
    scanf("%d", &jobId);

    // 在这里调用释放内存的函数
    // ...
}

int main() {
    // 初始状态下，整个内存是一个空闲分区
    freeList = (struct FreeBlock*)malloc(sizeof(struct FreeBlock));
    freeList->startAddress = 0;
    freeList->size = TOTAL_MEMORY_SIZE;
    freeList->next = NULL;

    char choice;

    do {
        printf("\n选择操作：\n");
        printf("1. 申请内存\n");
        printf("2. 释放内存\n");
        printf("3. 显示内存状态\n");
        printf("0. 退出\n");
        printf("选择：");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                interactiveAllocate();
                break;
            case '2':
                interactiveFree();
                break;
            case '3':
                displayMemoryStatus();
                break;
            case '0':
                break;
            default:
                printf("无效的选择\n");
        }
    } while (choice != '0');
    system("pause");
    return 0;
}
