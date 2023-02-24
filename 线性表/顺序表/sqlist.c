#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

//@file    :sqlist
//@author  :sdlqgjy
//@data    :2023/2/23 21:52:32
//@brief   :实现顺序表的基本操作

#define MaxSize 50

typedef char ElemType;
typedef struct {
	ElemType data[MaxSize];
	int length;
}SqList;

//初始化顺序表
void InitList(SqList* L) {
	L->length = 0;
}
//在指定位置插入元素
void ListInsert(SqList* L, int i, ElemType e) {
	for (int j = L->length; j > i-1; j--) {
		L->data[j] = L->data[j - 1];
	}
	L->data[i - 1] = e;
	L->length++;
}
//打印顺序表
void PrintList(SqList* L) {
	for (int i = 0; i < L->length; i++) {
		printf("%2c", L->data[i]);
	}
	printf("\n");
}
//计算顺序表的长度
int ListLength(SqList* L) {
	return L->length;
}
//判断顺序表是否为空
int ListEmpty(SqList* L) {
	if (L->length == 0) {
		return 0;//返回0为空
	}
	return 1;//返回1则不为空
}
//求线性表第i个元素的位置
void GetElem(SqList* L,int i, ElemType* e) {
	*e = L->data[i - 1];
}
//输出某个元素的位置
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
	printf("顺序表的基本操作如下：\n");
	printf("1、初始化顺序表\n");
	InitList(&L);
	printf("2、依次插入a,b,c,d,e五个元素：\n");
	ListInsert(&L, 1, 'a');
	ListInsert(&L, 2, 'b');
	ListInsert(&L, 3, 'c');
	ListInsert(&L, 4, 'd');
	ListInsert(&L, 5, 'e');
	printf("3、输出顺序表\t");
	PrintList(&L);
	//printf("\n");
	printf("4、输出顺序表的长度：%d\n",ListLength(&L));
	printf("5、判断线性表是否为空:\t");
	int a = ListEmpty(&L);
	if (a == 1) {
		printf("线性表不为空\n");
	}
	else {
		printf("线性表为空\n");
	}
	printf("6、输出顺序表的第三个元素:\t");
	GetElem(&L, 3, &e);
	printf("%c\n", e);
	printf("7、输出元素a的位置:%d\n",LocateElem(&L,'a'));
	printf("8、在第四个元素位置上插入f元素:\n");
	ListInsert(&L, 4, 'f');
	printf("9、输出线性表L\t");
	PrintList(&L);
	//printf("\n");
	printf("10、删除第3个元素:\n");
	DeleteElem(&L, 3);
	printf("11、输出线性表L\t");
	PrintList(&L);
	//printf("\n");
	printf("12、释放线性表L\n");
	//FreeList(&L);
	system("pause");
	return 0;
}
