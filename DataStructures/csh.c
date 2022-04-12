#include <stdio.h>
#include <stdlib.h>
#define Size 4
typedef struct Table{
    int * head;
    int length;
    int size;
}table;
table initTable(){
    table t;
    t.head=(int*)malloc(Size*sizeof(int));
    if (!t.head)
    {
        printf("初始化失败");
        exit(0);
    }
    t.length=0;
    t.size=Size;
    return t;
}
void displayTable(table t){
    for (int i=0;i<t.length;i++) {
        printf("%d",t.head[i]);
    }
    printf("\n");
}
int main(){
    table t1=initTable();
    for (int i=1; i<=Size; i++) {
        t1.head[i-1]=i;
        t1.length++;
    }
    printf("顺序表为：\n");
    displayTable(t1);
    return 0;
}