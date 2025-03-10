#include <stdio.h>
#include <stdlib.h>
#define n 10  // 进程个数

struct pcb {
    int name;    // 进程标识符
    int status;  // 进程状态
    int ax, bx, cx, dx;  // 进程现场信息，通用寄存器内容
    int pc;               // 进程现场信息，程序计数器内容
    int psw;              // 进程现场信息，程序状态字寄存器内容
    int next;             // 下一个进程控制块的位置
};

struct pcb pcbarea[n];  // 模拟进程控制块区域的数组

struct {
    int head;
    int tail;
} ready;  // 就绪队列指针

int run;     // 指向正在运行进程的进程控制块的指针
int pfree;   // 指向空闲进程控制块队列的指针

// 初始化进程控制块区域和就绪队列
void init() {
    for (int i = 0; i < n; ++i) {
        pcbarea[i].name = i + 1;
        pcbarea[i].status = 0;  // 0表示进程空闲
        pcbarea[i].next = i + 1;
    }
    pcbarea[n - 1].next = -1;  // 结尾设置为-1表示没有下一个空闲块

    ready.head = ready.tail = -1;
    run = -1;
    pfree = 0;
}

// 创建进程
int createProcess() {
    if (pfree == -1) {
        printf("没有可用的进程控制块。\n");
        return -1;
    }

    int newProcess = pfree;
    pfree = pcbarea[pfree].next;

    // 模拟申请资源的步骤，这里省略

    // 填写进程控制块
    pcbarea[newProcess].status = 1;  // 1表示就绪态
    // 其他信息的填写，例如进程标识符、现场信息等，这里省略

    // 挂入就绪队列
    if (ready.head == -1) {
        ready.head = ready.tail = newProcess;
    } else {
        pcbarea[ready.tail].next = newProcess;
        ready.tail = newProcess;
    }

    return newProcess;
}

// 主程序
int main() {
    init();

    // 模拟创建几个进程
    createProcess();
    createProcess();
    createProcess();

    // 输出每个进程的进程ID
    printf("进程ID:\n");
    for (int i = ready.head; i != -1; i = pcbarea[i].next) {
        printf("%d\n", pcbarea[i].name);
    }
    
    system("pause");
    return 0;
}
