#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#define NAME 20
#define NUM  20
#define SEX  5
#define AGE  10
#define ARR  30
#define MAX  100
#define DEFAULT_SIZE 3
#define ADD_SIZE 2
//�˵�����

typedef struct People
{
	char name[NAME];
	char number[NUM];
	char sex[SEX];
	int age;
	char arr[ARR];

}People;
typedef struct Contact
{
	People* data;
	int count;
	int size_max;

}Contact;

void menu();
//���ӹ���
int Initcontact();
void addcontact();
//չʾ
void showcontact();
//ɾ������
void delcontact();
//��ѯ����
void searchcontact();
//�޸Ĺ���
void modifycontact();
//������
void sortcontact();
void SAVEcontact(const Contact*);
void checkcapacity();
void Loadcontact();
