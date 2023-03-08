#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

//实现单链表的各种基本运算算法

typedef int ElemType;

//定义单链表类型
typedef struct LNode {
	ElemType data;
	struct LNode* next;//指向后继的指针
}LNode,*LinkList;

//带有头结点单链表的初始化
void InitList(LinkList* L) {
	(*L) = (LinkList)malloc(sizeof(LNode));//开辟空间
	if (!L) {
		printf("内存分配失败！\n");
		exit(0);
	}
	(*L)->next = NULL;
}
//头插法创建单链表
void CreateListHead(LinkList* L) {
	int n;//定义元素个数
	LinkList p;
	(*L) = (LinkList)malloc(sizeof(LNode));
	(*L)->next = NULL;
	printf("请输入你要用头插法插入的元素个数：\t");
	scanf_s("%d", &n);
	printf("请输入你要插入的元素值：\n");
	for (int i = 0; i < n; i++) {
		p = (LinkList)malloc(sizeof(LNode));//开创一个新节点
		scanf_s("%d", &p->data);
		p->next = (*L)->next;
		(*L)->next = p;
	}
}
//尾插法创建单链表
void CreateListTail(LinkList* L) {
	int n;//定义元素个数
	LinkList p, r;
	(*L) = (LinkList)malloc(sizeof(LNode));
	r = *L;//r为指向尾部节点的指针
	printf("请输入你要用尾插法插入的元素个数：\t");
	scanf_s("%d", &n);
	printf("请输入你要插入的元素值：\n");
	for (int i = 0; i < n; i++) {
		p=(LinkList)malloc(sizeof(LNode));
		scanf_s("%d", &p->data);
		r->next = p;
		r = p;
	}
	r->next = NULL;
}
//计算单链表的长度
int LengthList(LinkList* L) {
	int length = 0;
	LinkList p;
	p = (*L)->next;
	while (p!=NULL) {
		length++;
		p = p->next;
	}
	return length;
}
//获取单链表中第i个值的元素
ElemType getElem(LinkList L, int i, ElemType* e) {
	int j = 1;
	LinkList p;
	p = L->next;
	while (p  && j < i) {
		p = p->next;
		++j;
	}
	if (!p||j > i) {
		printf("查询不到元素！\n");
	}
	*e = p->data;
	return 0;
}
//在单链表的第i个位置插入元素
void InsertElem(LinkList* L, int i, ElemType e) {
	LinkList p,s;
	p = (*L);
	int j = 1;
	while (p && j < i) {
		p = p->next;
		++j;
	}
	if (!p || j > i) {
		printf("插入元素失败！\n");
	}
	s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
}
//删除L中第i个元素，并用e返回其值
void DeleteList(LinkList* L, int i, ElemType* e)				
{
	LinkList p, q;
	int j = 1;
	p = *L;
	while (p->next && j < i)						
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i)
	{
		printf("删除元素失败！\n");
		exit(0);
	}
	q = p->next;
	p->next = q->next;//将q的后继赋值给p的后继
	*e = q->data;//将q节点中的数据给e*
	free(q);//释放q节点
}
//打印整个链表
void ShowList(LinkList* L)					
{
	LinkList p;
	p = (*L)->next;
	if (p == NULL)
	{
		printf("这是一个空链表！\n");
	}
	printf("单链表");

	while (p)
	{
		printf("%2d", p->data);
		p = p->next;
	}
	printf("\n");
}
//判断单链表是否为空
int IsEmpty(LinkList* L) {
	LinkList p;
	p = (*L);
	if (p->next == NULL) {
		return 0;
	}
	return 1;
}
int main()
{
	printf("初始化单链表h\n");
	LinkList L;
	InitList(&L);
	printf("采用尾插法插入1，2，3，4，5\n");
	CreateListTail(&L);
	printf("输出单链表h\n");
	ShowList(&L);
	printf("单链表的长度为：%d\n", LengthList(&L));
	printf("判断单链表是否为空：\t");
	int n = IsEmpty(&L);
	if (n == 0) {
		printf("单链表为空\n");
	}
	else {
		printf("单链表不为空\n");
	}
	system("pause");
	return 0;
}

