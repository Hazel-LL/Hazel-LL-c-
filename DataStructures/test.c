
#include <stdio.h>
#include <stdlib.h>

//顺序表的定义
typedef int ElemType;
typedef struct seqList //定义一个结构体
{
    int n;             //顺序表的当前长度
    int maxLength;     //顺序表的最大允许长度
    ElemType *element; //动态一维数组的指针
} SeqList;

//顺序表的初始化
#define ERROR 0
#define OK 1
#define Overflow 2
#define Underflow 3
#define NotPresent 4
#define Duplicate 5
typedef int Status;
Status Init(SeqList *L, int mSize)
{
    L->maxLength = mSize;                                      //顺序表的最大允许长度
    L->n = 0;                                                  //顺序表的当前长度为0
    L->element = (ElemType *)malloc(sizeof(ElemType) * mSize); //动态生成一维数组空间

    if (!L->element) //如果顺序表没有取到储存空间的首地址
        return ERROR;
    return OK;
}

//顺序表的查找
Status Find(SeqList L, int i, ElemType *x)//查找下标为i的元素ai
{
    if (i < 0 || i > L.n - 1)
        return ERROR;//判断元素下标i 是否越界
    *x = L.element[i];//取出element[i]值通过参数x 返回
    return OK;
}


//顺序表的插入
Status Insert(SeqList *L, int i, ElemType x)
{
    int j;
    if (i < -1 || i > L->n - 1)//判断下标i 是否越界
        return ERROR;
    if (L->n == L->maxLength)//判断存储空间是否已满

        return ERROR;
    for (j = L->n - 1; j > i; j--)
        L->element[j + 1] = L->element[j];//从后往前逐个后移元素

    L->element[i + 1] = x;//将新元素放入下标为i+1 的位置
    L->n = L->n + 1;
    return OK;
}


//顺序表的删除
Status Delete(SeqList *L, int i)
{
    int j;
    if (i < 0 || i > L->n - 1)//下标i 是否越界

        return ERROR;
    if (!L->n)//顺序表是否为空
        return ERROR;
    for (j = i + 1; j < L->n; j++)
    {
        L->element[j - 1] = L->element[j];//从前往后逐个前移元素

    }
    L->n--;//表长减1
    return OK;
}


//顺序表的输出
Status Output(SeqList *L)
{
    int i;
    if (L->n == 0)//判断顺序表是否为空
        return ERROR;
    for (i = 0; i <= L->n - 1; i++)
        printf("%d ", L->element[i]);//从前往后逐个输出元素
    printf("\n");
    return OK;
}


//顺序表的撤销
void Destroy(SeqList *L)
{
    L->n = 0;
    L->maxLength = 0;
    free(L->element);
}

int main(void)
{
    int i,  q;
    SeqList list;
    Init(&list, 10);//对顺序表进行初始化
    for (i = 0; i < 10; i++)
        Insert(&list, i - 1, i);//线性表中插入新元素
    printf("原顺序表：\n");
    Output(&list);


    printf("查找元素的位置:\n");
    q = Find( L, 5);
    printf("%d\n", q);
    return 0;
}
