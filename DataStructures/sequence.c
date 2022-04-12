#include <stdio.h>
#include <stdlib.h>  //malloc()、exit()
#define ERROR 0
#define OK 1
#define Overflow 2   // Overflow 表示上溢
#define Underflow 3  // Underflow 表示下溢
#define NotPresent 4 // NotPresent 表示元素不存在
#define Duplicate 5  // Duplicate 表示有重复元素
typedef int Status;
typedef int ElemType;

typedef struct seqlist
{
    int n;             //顺序表的当前长度
    int maxLength;     //顺序表的最大允许长度
    ElemType *element; //动态一维数组的指针
} SeqList;

Status Init(SeqList *L, int mSize)
{
    L->maxLength = mSize;
    L->n = 0;
    L->element = malloc(sizeof(ElemType) * mSize); //动态生成一维数组空间
    if (!L->element)
        return ERROR;
    return OK;
}

Status Output(SeqList L)
{
int i;
if (L.n==0)      //判断顺序表是否为空
return ERROR;
for (i=0;i<= L.n -1;i++)
printf("%d ",L.element[i]);    //从前往后逐个输出元素
return OK;
}


void main()
{
    int i;
    SeqList L;
    Init(&L, 10); //对顺序表进行初始化
    //for (i = 0; i < 9; i++)
        //Insert(&list, i - 1, i); //线性表中插入新元素
    Output(L);
    //Delete(&list, 0);
    //Output(list);
    //Destroy(&list);
}
