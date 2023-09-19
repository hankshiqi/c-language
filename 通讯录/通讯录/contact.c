#include"contact.h"
int main()
{
	int input = 0;
	Contact con;
	Initcontact(&con);
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
			case 1:
				addcontact(&con);
				break;
			case 2:
				delcontact(&con);
				break;
			case 3:
				searchcontact(&con);
				break;
			case 4:
				break;
			case 5:
				sortcontact(&con);
				break;
			case 6:
				showcontact(&con);
				break;
			case 0:
				printf("退出通讯录");
				SAVEcontact(&con);
				break;
			default:
				printf("输入错误请重新输入\n");
		}
		} while (input);



	return 0;
}