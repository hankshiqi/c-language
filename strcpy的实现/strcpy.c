#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
char* my_strcpy(const char* arr1, char* arr2)
{
	char* ret = arr2;

	while (*arr1)
	{
		*arr2++ = *arr1++;
	}
	return ret;


}
int main()
{ 
	int arr2[20] = { 0 };
	my_strcpy("hello world", arr2);
	printf("%s\n", arr2);

	return 0;
}