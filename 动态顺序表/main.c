#include"seqlist.h"

int main()
{
	SeqList list;
	SeqListInit(&list);
	ElemType item;
	int select = 1;
	int pos, temp;
	while (select)
	{
		printf("************************************************\n");
		printf("*  [1]  Push_Back            [2]  Push_Front   *\n");
		printf("*  [3]  Find_Pos             [4]  Find_Val     *\n");
		printf("*  [5]  Insert_Pos           [6]  Del_Pos      *\n");
		printf("*  [7]  Show_List            [8]  Length       *\n");
		printf("*  [9]  Clear                [0]  Quit_System  *\n");
		printf("************************************************\n");

		printf("请选择:>");
		scanf("%d", &select);

		if (0 == select)
		{
			break;
		}

		switch (select)
		{
		case 1:
			printf("请输入要插入的数据（以-1结束）：\n");
			while (scanf("%d", &item), item != -1)
			{
				Push_Back(&list, item);
			}
			printf("尾部插入数据成功！\n");
			break;
		case 2:
			printf("请输入要插入的数据（以-1结束）：\n");
			while (scanf("%d", &item) && item != -1)
			{
				Push_Front(&list, item);
			}
			printf("头部插入数据成功！\n");
			break;
		case 3:
			printf("请输入要查找元素的位置（起始位置为1）：\n");
			scanf("%d", &item);
			Find_Pos(&list, item);
			break;
		case 4:
			printf("请输入要查找的元素:\n");
			scanf("%d", &item);
			pos = Find_Val(&list, item);
			if (-1 == pos)
			{
				printf("查找元素失败！\n");
			}
			else
			{
				printf("查找元素成功！\n元素%d在顺序表中的位置为%d.\n", item, pos);
			}
			break;
		case 5:
			printf("请输入要插入元素的元素：\n");
			scanf("%d", &item);
			printf("请输入要插入元素的位置（起始位置为1）：\n");
			scanf("%d", &pos);
			Insert_Pos(&list, item, pos);
			break;
		case 6:
			printf("请输入要删除元素的位置：\n");
			scanf("%d", &pos);
			temp = Del_Pos(&list, pos);
			if (-1 == temp)
			{
				printf("删除位置不合法！\n");
			}
			else
			{
				printf("删除数据成功！\n");

			}
			break;
		case 7:
			Show_List(list);
			break;
		case 8:
			Length(&list);
			break;
		case 9:
			Clear(&list);
			printf("数据表清空成功！\n");
			break;
		default:
			printf("命令出错,请重新输入！\n");
			break;
		}
		system("pause");
		system("cls");
	}
	Destroy_List(&list);
	return 0;
}
