#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

/*
    实现双链表的基本操作算法
*/
typedef int ElemType;
typedef struct DNode{
    ElemType data;
    struct DNode *prior;
    struct DNode *next;
}DNode,*Dlinknode;

//初始化线性表
void InitList(Dlinknode *L){
    (*L)=(Dlinknode)malloc(sizeof(DNode));
    if(!L){
        printf("双链表初始化失败！\n");
        exit(0);
    }
    (*L)->next=(*L)->prior=NULL;
}
//头插法建立双链表
void CreateDlistHead(Dlinknode *L){
    int n;//设立链表中元素的数量
    Dlinknode p;
    (*L)=(Dlinknode)malloc(sizeof(DNode));
    (*L)->prior=(*L)->next=NULL;
    printf("请输入双链表中元素的数目：\t");
    scanf_s("%d",&n);
    printf("请输入要放入链表中的元素：\n");
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
//尾插法建立双链表
void CreateDlistTail(Dlinknode *L){
    int n;//设立链表中元素的数目
    Dlinknode p,r;
	(*L)=(Dlinknode)malloc(sizeof(DNode));
    r=(*L);
    printf("请输入双链表中元素的数目：\t");
    scanf_s("%d",&n);
    printf("请输入要放入链表中的元素：\n");
    for(int i=0;i<n;i++){
        p=(Dlinknode)malloc(sizeof(DNode));
        scanf_s("%d",&p->data);
        r->next=p;
        p->prior=r;
        r=p;
    }
    r->next=NULL;
}
//输出双链表
void DispList(Dlinknode *L){
    Dlinknode p;
    p=(*L)->next;
    while(p!=NULL){
        printf("%2d",p->data);
        p=p->next;
    }
    printf("\n");
}
//计算链表的长度
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
//将元素插入到双链表的第i个位置
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
//将双链表中第i个位置的元素删除
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
//销毁双链表
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
    printf("双链表L的长度为：%d\n",LengthList(&L));
    Dlinknode H;
    InitList(&H);
    CreateDlistTail(&H);
    DispList(&H);
    printf("双链表H的长度为：%d\n",LengthList(&H));
    InsertElem(&H,3,9);
    DispList(&H);
    DeleteElem(&H,5);
    DispList(&H);
    DestoryList(&H);
    printf("双链表H的长度为：%d\n",LengthList(&H));
    system("pause");
    return 0;
}