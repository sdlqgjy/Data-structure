#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

//ʵ�ֵ�����ĸ��ֻ��������㷨

typedef int ElemType;

//���嵥��������
typedef struct LNode {
	ElemType data;
	struct LNode* next;//ָ���̵�ָ��
}LNode,*LinkList;

//����ͷ��㵥����ĳ�ʼ��
void InitList(LinkList* L) {
	(*L) = (LinkList)malloc(sizeof(LNode));//���ٿռ�
	if (!L) {
		printf("�ڴ����ʧ�ܣ�\n");
		exit(0);
	}
	(*L)->next = NULL;
}
//ͷ�巨����������
void CreateListHead(LinkList* L) {
	int n;//����Ԫ�ظ���
	LinkList p;
	(*L) = (LinkList)malloc(sizeof(LNode));
	(*L)->next = NULL;
	printf("��������Ҫ��ͷ�巨�����Ԫ�ظ�����\t");
	scanf_s("%d", &n);
	printf("��������Ҫ�����Ԫ��ֵ��\n");
	for (int i = 0; i < n; i++) {
		p = (LinkList)malloc(sizeof(LNode));//����һ���½ڵ�
		scanf_s("%d", &p->data);
		p->next = (*L)->next;
		(*L)->next = p;
	}
}
//β�巨����������
void CreateListTail(LinkList* L) {
	int n;//����Ԫ�ظ���
	LinkList p, r;
	(*L) = (LinkList)malloc(sizeof(LNode));
	r = *L;//rΪָ��β���ڵ��ָ��
	printf("��������Ҫ��β�巨�����Ԫ�ظ�����\t");
	scanf_s("%d", &n);
	printf("��������Ҫ�����Ԫ��ֵ��\n");
	for (int i = 0; i < n; i++) {
		p=(LinkList)malloc(sizeof(LNode));
		scanf_s("%d", &p->data);
		r->next = p;
		r = p;
	}
	r->next = NULL;
}
//���㵥����ĳ���
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
//��ȡ�������е�i��ֵ��Ԫ��
ElemType getElem(LinkList L, int i, ElemType* e) {
	int j = 1;
	LinkList p;
	p = L->next;
	while (p  && j < i) {
		p = p->next;
		++j;
	}
	if (!p||j > i) {
		printf("��ѯ����Ԫ�أ�\n");
	}
	*e = p->data;
	return 0;
}
//�ڵ�����ĵ�i��λ�ò���Ԫ��
void InsertElem(LinkList* L, int i, ElemType e) {
	LinkList p,s;
	p = (*L);
	int j = 1;
	while (p && j < i) {
		p = p->next;
		++j;
	}
	if (!p || j > i) {
		printf("����Ԫ��ʧ�ܣ�\n");
	}
	s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
}
//ɾ��L�е�i��Ԫ�أ�����e������ֵ
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
		printf("ɾ��Ԫ��ʧ�ܣ�\n");
		exit(0);
	}
	q = p->next;
	p->next = q->next;//��q�ĺ�̸�ֵ��p�ĺ��
	*e = q->data;//��q�ڵ��е����ݸ�e*
	free(q);//�ͷ�q�ڵ�
}
//��ӡ��������
void ShowList(LinkList* L)					
{
	LinkList p;
	p = (*L)->next;
	if (p == NULL)
	{
		printf("����һ��������\n");
	}
	printf("������");

	while (p)
	{
		printf("%2d", p->data);
		p = p->next;
	}
	printf("\n");
}
//�жϵ������Ƿ�Ϊ��
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
	printf("��ʼ��������h\n");
	LinkList L;
	InitList(&L);
	printf("����β�巨����1��2��3��4��5\n");
	CreateListTail(&L);
	printf("���������h\n");
	ShowList(&L);
	printf("������ĳ���Ϊ��%d\n", LengthList(&L));
	printf("�жϵ������Ƿ�Ϊ�գ�\t");
	int n = IsEmpty(&L);
	if (n == 0) {
		printf("������Ϊ��\n");
	}
	else {
		printf("������Ϊ��\n");
	}
	system("pause");
	return 0;
}

