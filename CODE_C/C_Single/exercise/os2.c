#include <stdio.h>
#include <stdlib.h>

#define n 10  // 进程个数
#define TIME_QUANTUM 5  // 时间片长度

struct pcb {
    int name;    // 进程标识符
    int status;  // 进程状态 (0: 空闲, 1: 就绪, 2: 执行, 3: 结束)
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

// 进程调度
void schedule() {
    if (ready.head == -1) {
        printf("就绪队列为空，无法调度。\n");
        return;
    }

    // 从就绪队列头部摘下一个进程
    int scheduledProcess = ready.head;
    ready.head = pcbarea[ready.head].next;

    // 修改进程状态为执行态
    pcbarea[scheduledProcess].status = 2;

    // 输出调度信息
    printf("调度进程 %d 到执行态\n", scheduledProcess + 1);

    // 如果有正在运行的进程，将其状态改为就绪态
    if (run != -1) {
        pcbarea[run].status = 1;
        // 输出让出CPU的信息
        printf("进程 %d 让出CPU\n", run + 1);
    }

    // 更新运行进程指针
    run = scheduledProcess;

    // 输出运行进程的信息
    printf("正在运行的进程: %d\n", run + 1);

    // 恢复进程现场信息到CPU寄存器
    // 这里省略了具体的现场信息恢复过程

    // 模拟进程执行，延时表示
    printf("进程 %d 执行...\n", run + 1);
    // 这里可以添加模拟实际进程执行的代码，例如延时或其他操作

    // 模拟进程执行结束后的处理
    // 这里省略了具体的处理过程

    // 将执行结束的进程状态改为结束态
    pcbarea[run].status = 3;

    // 输出进程结束的信息
    printf("进程 %d 执行结束\n", run + 1);

    // 清空运行进程指针
    run = -1;
}

// 主程序
int main() {
    init();

    // 模拟创建几个进程
    createProcess();
    createProcess();
    createProcess();

    // 进行进程调度
    schedule();

    // 输出每个进程的进程ID及状态
    printf("进程ID和状态:\n");
    for (int i = 0; i < n; ++i) {
        printf("进程 %d - 状态: %d\n", pcbarea[i].name, pcbarea[i].status);
    }
    system("pause");
    return 0;
}
