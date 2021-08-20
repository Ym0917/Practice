#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#pragma warning(disable:4996)

#include<stdio.h>
#include<stdlib.h>
#include <assert.h>

#define ElemType int
#define MAXSIZE 10

typedef struct
{
	ElemType* a; // 存储数据空间的指针
	int size;      // 有效数据个数 
	int capacity;  // 容量空间大小
	
}SeqList;

void SeqListInit(SeqList *L);
void Push_Back(SeqList *L, ElemType x);
void Push_Front(SeqList *L, ElemType x);
void Find_Pos(SeqList *L, int p);
int Find_Val(SeqList *L, ElemType val);
void Insert_Pos(SeqList *L, ElemType x, int p);
int Del_Pos(SeqList *L, int p);
void Show_List(SeqList L);
void Length(SeqList *L);
void Clear(SeqList *L);
void Destroy_List(SeqList *L);

/////////////////////////////////////////////////////////////////////////////////////////
//初始化
void SeqListInit(SeqList *L)//先开4个空间
{
	L->a = (ElemType*)malloc(sizeof(ElemType)* 4);

	if (L->a == NULL)//malloc申请空间失败
	{
		printf("malloc fail\n");
		exit(-1);
	}

	//memset(L->a, 0, sizeof(ElemType)* 4);//初始化所开空间（可有可无)
	L->size = 0;
	L->capacity = 4;
}

//检查是否需要扩容
void CheckCapacity(SeqList* L)
{
	// 检查空间，不够扩容
	if (L->size == L->capacity)
	{
		ElemType* temp = (ElemType*)realloc(L->a, sizeof(ElemType)*L->capacity * 2);

		if (temp == NULL)
		{
			printf("malloc fail\n");
			exit(-1);
		}

		L->a = temp;
		L->capacity *= 2;
	}
}


//1 尾插
void Push_Back(SeqList *L, ElemType x)
{
	assert(L);//判断空间是否申请成功

	CheckCapacity(L);//扩容

	L->a[L->size] = x;
	L->size++;

}

//2头插
void Push_Front(SeqList *L, ElemType x)
{
	assert(L);

	CheckCapacity(L);

	for (int i = L->size; i > 0; --i)
		L->a[i] = L->a[i - 1];

	L->a[0] = x;
	L->size++;

}

//3 按位置查找
void Find_Pos(SeqList *L, int p)
{
	if (p > 0 && p <= L->size)//用户输入的p从1开始
	{
		printf("第%d个元素为:%d.\n", p, L->a[p - 1]);
	}
	else
	{
		printf("查找位置不合法！\n");
	}
}

//4 按值查找
int Find_Val(SeqList *L, ElemType val)
{
	int i = 0;
	for (i = 0; i < L->size; i++)//i为下标
	{
		if (val == L->a[i])
		{
			return i + 1;
		}
	}
	return -1;
}

//5 按位置插入
void Insert_Pos(SeqList *L, ElemType x, int p)
{
	CheckCapacity(L);

	int i = 0;
	if ((p<1) || (p>L->size + 1))
	{
		printf("要插入的位置[%d]是非法位置, %d 不能插入.\n", p, x);
		return;
	}
	else
	{
		for (i = L->size - 1; i >= p - 1; --i)//i为下标
			L->a[i + 1] = L->a[i];
		L->a[p - 1] = x;
		L->size++;
		printf("插入数据成功!\n");
	}
}

//6 按位置删除
int Del_Pos(SeqList *L, int p)
{
	int i = p - 1;//i为下标
	if ((p<1) || (p>L->size))
	{
		return -1;
	}
	for (; i < L->size - 1; i++)
	{
		L->a[i] = L->a[i + 1];
	}
	L->size--;
	return i;

}

//7 打印
void Show_List(SeqList L)
{

	for (int i = 0; i <=L.size-1; ++i)//i为下标
		printf("%d ", L.a[i]);
	printf("\n");
}

//8 求长度
void Length(SeqList *L)
{

	printf("顺序表的长度为：%d\n", L->size);

}

//9 清空顺序表
void Clear(SeqList *L)
{
	L->size = 0;
}

//摧毁
void Destroy_List(SeqList *L)
{
	free(L->a);//销毁a所指空间
	L->a = NULL;//将a指向空，预防野指针
	L->size = L->capacity = 0;
}

#endif /* _SEQLIST_H_ */
