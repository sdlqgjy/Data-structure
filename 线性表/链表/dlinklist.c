#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

/*
    ʵ��˫����Ļ��������㷨
*/
typedef int ElemType;
typedef struct DNode{
    ElemType data;
    struct DNode *prior;
    struct DNode *next;
}DNode,*Dlinknode;

//��ʼ�����Ա�
void InitList(Dlinknode *L){
    (*L)=(Dlinknode)malloc(sizeof(DNode));
    if(!L){
        printf("˫�����ʼ��ʧ�ܣ�\n");
        exit(0);
    }
    (*L)->next=(*L)->prior=NULL;
}
//ͷ�巨����˫����
void CreateDlistHead(Dlinknode *L){
    int n;//����������Ԫ�ص�����
    Dlinknode p;
    (*L)=(Dlinknode)malloc(sizeof(DNode));
    (*L)->prior=(*L)->next=NULL;
    printf("������˫������Ԫ�ص���Ŀ��\t");
    scanf_s("%d",&n);
    printf("������Ҫ���������е�Ԫ�أ�\n");
    for(int i=0;i<n;i++){
        p=(Dlinknode)malloc(sizeof(DNode));
        scanf_s("%d",&p->data);
        p->next=(*L)->next;
        if((*L)->next!=NULL){
            (*L)->next->prior=p;
        }
        (*L)->next=p;
        p->prior=(*L);
    }
}
//β�巨����˫����
void CreateDlistTail(Dlinknode *L){
    int n;//����������Ԫ�ص���Ŀ
    Dlinknode p,r;
	(*L)=(Dlinknode)malloc(sizeof(DNode));
    r=(*L);
    printf("������˫������Ԫ�ص���Ŀ��\t");
    scanf_s("%d",&n);
    printf("������Ҫ���������е�Ԫ�أ�\n");
    for(int i=0;i<n;i++){
        p=(Dlinknode)malloc(sizeof(DNode));
        scanf_s("%d",&p->data);
        r->next=p;
        p->prior=r;
        r=p;
    }
    r->next=NULL;
}
//���˫����
void DispList(Dlinknode *L){
    Dlinknode p;
    p=(*L)->next;
    while(p!=NULL){
        printf("%2d",p->data);
        p=p->next;
    }
    printf("\n");
}
//��������ĳ���
int LengthList(Dlinknode *L){
    int length=0;
    Dlinknode p;
    p=(*L)->next;
    while(p!=NULL){
        length++;
        p=p->next;
    }
    return length;
}
//��Ԫ�ز��뵽˫����ĵ�i��λ��
void InsertElem(Dlinknode *L,int i,ElemType e){
    Dlinknode p=(*L),s;
    for(int j=0;j<i-1;j++){
        p=p->next;
    }
    s=(Dlinknode)malloc(sizeof(DNode));
    s->data=e;
    s->next=p->next;
    p->next->prior=s;
    s->prior=p;
    p->next=s;
}
//��˫�����е�i��λ�õ�Ԫ��ɾ��
void DeleteElem(Dlinknode *L,int i){
    Dlinknode p=(*L),s;
    for(int j=0;j<i-1;j++){
        p=p->next;
    }
    s=p->next;
    //e=s->data;
    p->next=s->next;
    p->next->prior=p;
    free(s);
}
//����˫����
void DestoryList(Dlinknode *L){
    Dlinknode p=(*L);
    Dlinknode s=p->next;
    while(p!=NULL){
        free(p);
        p=s;
        s=p->next;
    }
    free(s);
}
int main()
{
    Dlinknode L;
    InitList(&L);
    CreateDlistHead(&L);
    DispList(&L);
    printf("˫����L�ĳ���Ϊ��%d\n",LengthList(&L));
    Dlinknode H;
    InitList(&H);
    CreateDlistTail(&H);
    DispList(&H);
    printf("˫����H�ĳ���Ϊ��%d\n",LengthList(&H));
    InsertElem(&H,3,9);
    DispList(&H);
    DeleteElem(&H,5);
    DispList(&H);
    DestoryList(&H);
    printf("˫����H�ĳ���Ϊ��%d\n",LengthList(&H));
    system("pause");
    return 0;
}