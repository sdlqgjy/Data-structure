#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

//@file    :sqlist
//@author  :sdlqgjy
//@data    :2023/2/23 21:52:32
//@brief   :ʵ��˳���Ļ�������

#define MaxSize 50

typedef char ElemType;
typedef struct {
	ElemType data[MaxSize];
	int length;
}SqList;

//��ʼ��˳���
void InitList(SqList* L) {
	L->length = 0;
}
//��ָ��λ�ò���Ԫ��
void ListInsert(SqList* L, int i, ElemType e) {
	for (int j = L->length; j > i-1; j--) {
		L->data[j] = L->data[j - 1];
	}
	L->data[i - 1] = e;
	L->length++;
}
//��ӡ˳���
void PrintList(SqList* L) {
	for (int i = 0; i < L->length; i++) {
		printf("%2c", L->data[i]);
	}
	printf("\n");
}
//����˳���ĳ���
int ListLength(SqList* L) {
	return L->length;
}
//�ж�˳����Ƿ�Ϊ��
int ListEmpty(SqList* L) {
	if (L->length == 0) {
		return 0;//����0Ϊ��
	}
	return 1;//����1��Ϊ��
}
//�����Ա��i��Ԫ�ص�λ��
void GetElem(SqList* L,int i, ElemType* e) {
	*e = L->data[i - 1];
}
//���ĳ��Ԫ�ص�λ��
int LocateElem(SqList* L, ElemType e) {
	for (int i = 0; i < L->length; i++) {
		if (e == L->data[i]) {
			return i + 1;
		}
	}
	return -1;
}
void DeleteElem(SqList* L, int i) {
	for (int j = i; j < L->length - 1; j++) {
		L->data[j] = L->data[j + 1];
	}
	L->length--;
}
void FreeList(SqList* L) {
	free(L);
}

int main()
{
	SqList L;
	ElemType e;
	printf("˳���Ļ����������£�\n");
	printf("1����ʼ��˳���\n");
	InitList(&L);
	printf("2�����β���a,b,c,d,e���Ԫ�أ�\n");
	ListInsert(&L, 1, 'a');
	ListInsert(&L, 2, 'b');
	ListInsert(&L, 3, 'c');
	ListInsert(&L, 4, 'd');
	ListInsert(&L, 5, 'e');
	printf("3�����˳���\t");
	PrintList(&L);
	//printf("\n");
	printf("4�����˳���ĳ��ȣ�%d\n",ListLength(&L));
	printf("5���ж����Ա��Ƿ�Ϊ��:\t");
	int a = ListEmpty(&L);
	if (a == 1) {
		printf("���Ա�Ϊ��\n");
	}
	else {
		printf("���Ա�Ϊ��\n");
	}
	printf("6�����˳���ĵ�����Ԫ��:\t");
	GetElem(&L, 3, &e);
	printf("%c\n", e);
	printf("7�����Ԫ��a��λ��:%d\n",LocateElem(&L,'a'));
	printf("8���ڵ��ĸ�Ԫ��λ���ϲ���fԪ��:\n");
	ListInsert(&L, 4, 'f');
	printf("9��������Ա�L\t");
	PrintList(&L);
	//printf("\n");
	printf("10��ɾ����3��Ԫ��:\n");
	DeleteElem(&L, 3);
	printf("11��������Ա�L\t");
	PrintList(&L);
	//printf("\n");
	printf("12���ͷ����Ա�L\n");
	//FreeList(&L);
	system("pause");
	return 0;
}
