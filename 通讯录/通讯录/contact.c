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
				printf("�˳�ͨѶ¼");
				SAVEcontact(&con);
				break;
			default:
				printf("�����������������\n");
		}
		} while (input);



	return 0;
}