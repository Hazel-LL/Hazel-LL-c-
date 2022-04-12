#include <stdio.h>
#include <stdlib.h>  //malloc()、exit()
#define Size 10

typedef struct SeqList {
    int * head;//声明了一个名为head的长度不确定的数组，也叫“动态数组”
    int length;//记录当前顺序表的长度
    int size;//记录顺序表分配的存储容量
}SeqList;

//初始化
SeqList initSeqList() {
    SeqList L;
    L.size = Size;//空表的初始存储空间为Size
    L.length = 0;//空表的长度初始化为0
    L.head = (int*)malloc(Size * sizeof(int));//构造一个空的顺序表，动态申请存储空间
    if (!L.head)
    {
        printf("初始化失败");
        exit(0);//强制退出
    }
    return L;
}

//输出顺序表中元素的函数
void OutputSeqList(SeqList L) {
    int i;
    if (L.length==0)//判断顺序表是否为空
    {
        printf("初始化失败");
        exit(0);//强制退出
    }
    for (i = 0; i < L.length; i++) {
        printf("%d ", L.head[i]);//从前往后逐个输出元素
    }
    printf("\n");
}



int main() 
{
    int i;
    SeqList L = initSeqList();
    //向顺序表中添加元素
    for (i = 1; i <= Size; i++) {
        L.head[i - 1] = i;
        L.length++;
    }
    printf("顺序表中存储的元素分别是：\n");
    OutputSeqList(L);
    return 0;
}