#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#pragma warning(disable:4996)

#include<stdio.h>
#include<stdlib.h>


#define ElemType int
#define MAXSIZE 10

typedef struct
{
	ElemType elem[MAXSIZE];
	int last;//last记录最后一个元素的下标，若为空表则last为-1
	
}SeqList;

void SeqListInit(SeqList *L);//初始化
void Push_Back(SeqList *L, ElemType x);//尾插
void Push_Front(SeqList *L, ElemType x);//头插
void Find_Pos(SeqList *L, int p);//按位置查找
int Find_Val(SeqList *L, ElemType val);//按值查找
void Insert_Pos(SeqList *L,ElemType x, int p); //按位置插入
int Del_Pos(SeqList *L, int p);//按位置删除
void Show_List(SeqList *L);//打印
void Length(SeqList *L);//求长度
void Clear(SeqList *L);//清空静态顺序表
void Destroy_List(SeqList *L);//摧毁静态顺序表

/////////////////////////////////////////////////////////////////////////////////////////
void SeqListInit(SeqList *L)
{
	L->last = -1;
}

//1
void Push_Back(SeqList *L, ElemType x)
{
	if (L->last <MAXSIZE - 1)
	{
		L->last++;
		L->elem[L->last] = x;
	}
	else
	{
		printf("顺序表已满，%d不可的尾部插入.\n", x);
		return;
	}
}

//2
void Push_Front(SeqList *L, ElemType x)
{
	if (L->last <MAXSIZE - 1)
	{
		for (int i = L->last + 1; i>0; --i)
			L->elem[i] = L->elem[i - 1];
		L->elem[0] = x;
		L->last++;
	}
	else
	{
		printf("顺序表已满，%d不可的头部插入.\n", x);
		return;
	}
}

//3
void Find_Pos(SeqList *L, int p)
{
	if (p <= L->last + 1)
	{
		printf("第%d个元素为:%d.\n", p, L->elem[p - 1]);
	}
	else
	{
		printf("查找位置不合法！\n");
	}
}

//4
int Find_Val(SeqList *L, ElemType val)
{
	int i = 0;
	for (i = 0; i <= L->last; i++)
	{
		if (val == L->elem[i])
		{
			return i + 1;
		}
	}
	return -1;
}

//5
void Insert_Pos(SeqList *L, ElemType x, int p)
{
	int i = 0;
	if ((p<1) || (p>L->last + 2))
	{
		printf("要插入的位置[%d]是非法位置, %d 不能插入.\n", p, x);
	}
	if (L->last >= MAXSIZE - 1)
	{
		printf("表已满，无法插入！");
	}
	else
	{
		for (i = L->last; i >= p - 1; --i)
			L->elem[i + 1] = L->elem[i];
		L->elem[p - 1] = x;
		L->last++;
		printf("插入数据成功!\n");
	}
}

//6
int Del_Pos(SeqList *L, int p)
{
	int i = 0;
	if ((p<1) || (p>L->last + 1))
	{
		return -1;
	}
	for (i = 0; i <= L->last; i++)
	{
		L->elem[i - 1] = L->elem[i];
	}
	L->last--;
	return i;

}

//7
void Show_List(SeqList *L)
{
	if (-1 == L->last)
	{
		return;
	}
	else
	{
		for (int i = 0; i <= L->last; ++i)
			printf("%d ", L->elem[i]);
		printf("\n");
	}
}
//8
void Length(SeqList *L)
{

	printf("顺序表的长度为：%d\n", L->last + 1);

}

//9
void Clear(SeqList *L)
{
	L->last = -1;
}


void Destroy_List(SeqList *L)
{
	free(L->elem);
	L->last = -1;
}

#endif /* _SEQLIST_H_ */
