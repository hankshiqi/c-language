#include"contact.h"
#define _CRT_SECURE_NO_WARNINGS
void menu()
{
	printf("**********************\n");
	printf("****1.add      2.del**\n");
	printf("****3.search4.modify**\n");
	printf("****5.sort  6.show  **\n");
	printf("****0.exit************\n");
}
void checkcapacity(Contact* p)
{
	if (p->count == p->size_max)
	{
		People* str = (People*)realloc(p->data, (p->size_max + ADD_SIZE) * (sizeof(People)));
		if (str == NULL)
		{
			printf(" % s\n", strerror(errno));
			return;
		}
		else
		{
			p->data = str;
			p->size_max = p->size_max + ADD_SIZE;
			printf("增容成功\n");
		}
	}
}
int Initcontact(Contact* p)
{
	p->count = 0;
	p->data=(People*)calloc(DEFAULT_SIZE, sizeof(People));
	if (p->data == NULL)
	{
		printf("%s\n", strerror(errno));
		return 1;
	}
	p->size_max = DEFAULT_SIZE;
	Loadcontact(p);
	return 0;
}
void Loadcontact(Contact* p)
{
	FILE* load = fopen("contact.txt", "rb");
	if (load == NULL)
	{
		perror("Loadcontact");
		return;
	}
	People n1 = { 0 };
	while ((fread(&n1, sizeof(People), 1, load)) == 1)
	{
		checkcapacity(p);
		p->data[p->count] = n1;
		p->count++;
	}
	fclose(load);
	load = NULL;
}
void addcontact(Contact*p)
{
	checkcapacity(p);
	printf("请输入要增加的姓名\n");
	scanf("%s", p->data[p->count].name);
	printf("请输入性别\n");
	scanf("%s", p->data[p->count].sex);
	printf("请输入年龄\n");
	scanf("%d", &(p->data[p->count].age));
	printf("请输入号码\n");
	scanf("%s", p->data[p->count].number);
	printf("请输入地址\n");
	scanf("%s", p->data[p->count].arr);
	p->count++;
	printf("添加成功\n");
}
void showcontact(const Contact* p)
{
	int i = 0;
	printf("%-10s\t%-5s\t%-10s\t%-20s\t%-20s\n", "名字", "性别", "年龄","号码","地址");
	for (i = 0; i < p->count; i++)
	{
		printf("%-10s\t%-5s\t%-10d\t%-20s\t%-20s\n", p->data[i].name,p->data[i].sex,p->data[i].age,p->data[i].number,p->data[i].arr);
	}
}
static int findname(Contact* p, char name1[])
{
	int i = 0;
	for (i = 0; i < p->count; i++)
	{
		if (0 == strcmp(p->data[i].name, name1))
		{
			return i;
		}
	}
	return -1;
}
void delcontact(Contact* p)
{
	assert(p);
	int k = 0;
	char name1[20] = { 0 };
	if (p->count == 0)
	{
		printf("没有联系人可以删除\n");
		return;
	}
	else
		printf("请输入要删除联系人的名字\n");
	scanf("%s", name1);
	int j=findname(p, name1);
	if (j != -1)
	{
		for (k = j; k< p->count-1; k++)
		{
			p->data[k] = p->data[k + 1];
		}
		p->count--;
	}
	else {
		printf("该通讯录中没有可以删除的该元素\n");
	}

}
void SAVEcontact(const Contact* p)
{
	FILE* psave = fopen("contact.txt", "wb");
	if (psave == NULL)
	{
		perror("SAVEcontact");
		return;
	}
	int i = 0;
	for (i = 0; i < p->count; i++)
	{
		fwrite(p->data + i, sizeof(People), 1, psave);
	}
	fclose(psave);
	psave = NULL;
}
void searchcontact(Contact* p)
{
	char name2[20] = {0};
	printf("请输入要查找的名字\n");
	scanf("%s", name2);
	int j = findname(p, name2);
	if (j != -1)
	{
		printf("%-10s\t%-5s\t%-10s\t%-20s\t%-20s\n", "名字", "性别", "年龄", "号码", "地址");
		printf("%-10s\t%-5s\t%-10d\t%-20s\t%-20s\n", p->data[j].name, p->data[j].sex, p->data[j].age, p->data[j].number, p->data[j].arr);
	}
	else if (j == -1)
	{
		printf("没有找到想找的元素\n");
	}
}
int cmp_name(const void*e1,const void*e2)
{
	return (strcmp(((People*)e1)->name, ((People*)e2)->name));
}
void sortcontact(Contact* p)
{
	qsort(p->data, p->count, sizeof(p->data[0]), cmp_name);
}
