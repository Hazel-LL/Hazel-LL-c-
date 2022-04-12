#include <stdio.h>
#include <stdlib.h>  //malloc()��exit()
#define Size 10

typedef struct SeqList {
    int * head;//������һ����Ϊhead�ĳ��Ȳ�ȷ�������飬Ҳ�С���̬���顱
    int length;//��¼��ǰ˳���ĳ���
    int size;//��¼˳������Ĵ洢����
}SeqList;

//��ʼ��
SeqList initSeqList() {
    SeqList L;
    L.size = Size;//�ձ�ĳ�ʼ�洢�ռ�ΪSize
    L.length = 0;//�ձ�ĳ��ȳ�ʼ��Ϊ0
    L.head = (int*)malloc(Size * sizeof(int));//����һ���յ�˳�����̬����洢�ռ�
    if (!L.head)
    {
        printf("��ʼ��ʧ��");
        exit(0);//ǿ���˳�
    }
    return L;
}

//���˳�����Ԫ�صĺ���
void OutputSeqList(SeqList L) {
    int i;
    if (L.length==0)//�ж�˳����Ƿ�Ϊ��
    {
        printf("��ʼ��ʧ��");
        exit(0);//ǿ���˳�
    }
    for (i = 0; i < L.length; i++) {
        printf("%d ", L.head[i]);//��ǰ����������Ԫ��
    }
    printf("\n");
}



int main() 
{
    int i;
    SeqList L = initSeqList();
    //��˳��������Ԫ��
    for (i = 1; i <= Size; i++) {
        L.head[i - 1] = i;
        L.length++;
    }
    printf("˳����д洢��Ԫ�طֱ��ǣ�\n");
    OutputSeqList(L);
    return 0;
}