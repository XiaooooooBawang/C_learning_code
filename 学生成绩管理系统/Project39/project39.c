#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
int enter, i,*m,num,snum ,j;          /*num和m是记录学生的人数,snum是输入的学生学号*/
char ch, sname[10], cha ;
errno_t err;

struct Student 
{
	int number;
	char name[10];
	int Chinese;
	int math;
	int English;
	int total;
};
struct Student student[100];

void menu()
{
	printf("|--------students' grade management system-------|\n");
	printf("|0:exit                                          |\n");
	printf("|1:input grade                                   |\n");
	printf("|2:search grade                                  |\n");
	printf("|3:delete grade                                  |\n");
	printf("|4:modify grade                                  |\n");
	printf("|5:order grade                                   |\n");
	printf("|6:count student number                          |\n");
	printf("|------------------------------------------------|\n");
	printf("         please input <0-6> :");
}
void input()
{
	FILE* fp;
	num=0;
	if ((err = fopen_s(&fp, "成绩", "ab+")) != 0)
	{
		printf("can not open file (input)!");
		exit(0);
	}
	else
	{
		do
		{
			A:printf("please input student's information:\n");
			printf("No.:");
			scanf_s("%d", &snum);
			student[snum-1].number = snum;
			printf("name:");
			scanf_s("%s", student[snum -1].name, 10);
			printf("Chinese grade:");
			scanf_s("%d", &student[snum -1].Chinese);
			printf("math grade:");
			scanf_s("%d", &student[snum -1].math);
			printf("English grade:");
			scanf_s("%d", &student[snum -1].English);
			(student[snum -1].total) = (student[snum -1].Chinese) + (student[snum -1].math) + (student[snum -1].English);
			printf("total grade is :%d\n", student[snum -1].total);
			if (fwrite(&student[snum -1],sizeof(struct Student),1,fp)==1)
			{
				printf("the student's information successedly inputted!\n");
				num++;
			}
			else

			{
				printf("the student's information  can not successedly inputted!\nplease input once again ");
				goto A;
			}
			m = &num;
			printf("continue input?<y/n>:\n");
			ch = getchar();   /*上一行的转义字符“\n”代表回车换行，是帮你输入了一个回车，说以要回收一下回车符，不然cha就直接为回车符*/
			cha = getchar();
		} while (cha!='n');
	}
	fclose(fp);
	printf("input over!\n");
}

void search()
{
	FILE* fp;
	if ((err = fopen_s(&fp, "成绩", "ab+")) != 0)
	{
		printf("can not open file (search)!");
		exit(0);
	}
	else
	{
		for (i = 0; i < (*m); i++)
		{
			fread_s(&student[i], sizeof(struct Student), sizeof(struct Student), 1, fp);
		}
		do
		{
			printf("please input the student's number you want to search:");
			scanf_s("%d", &snum);
			for (i = 0; i < (*m); i++)
			{
				if (student[i].number== snum)
				{
					printf("No.%d\nname:%s\nChinese:%d\nmath:%d\nEnglish:%d\ntotal:%d\n",
						student[i].number, student[i].name, student[i].Chinese, student[i].math, student[i].English, student[i].total);
				}
			}
			printf("continue search?<y/n>:\n");
			ch = getchar();   /*上一行的转义字符“\n”代表回车换行，是帮你输入了一个回车，说以要回收一下回车符，不然cha就直接为回车符*/
			cha = getchar();
		} while (cha != 'n');
	}
	fclose(fp);
}
void delete()
{
	FILE* fp;
	if ((err = fopen_s(&fp, "成绩", "ab+")) != 0)
	{
		printf("can not open file (delete)!");
		exit(0);
	}
	else
	{
		for (i = 0; i < (*m); i++)
		{
			fread_s(&student[i], sizeof(struct Student), sizeof(struct Student), 1, fp);
		}
		do
		{
			printf("please input the student's number you want to delete:");
			scanf_s("%d", &snum);
			for (i = 0; i < (*m); i++)
			{
				if (snum == student[i].number)
				{
					for (j=i; j<(*m); j++)
					{
						student[j] = student[j + 1];   /*后面一个去覆盖他*/
					}
					(*m)--;
				}
			}
			printf("delete over!");
			printf("continue delete?<y/n>:\n");
			ch = getchar();   
			cha = getchar();
		} while (cha != 'n');
	}
	fclose(fp);
}
void modify()
{
	FILE* fp;
	num = 0;
	if ((err = fopen_s(&fp, "成绩", "ab+")) != 0)
	{
		printf("can not open file (input)!");
		exit(0);
	}
	else
	{
		do
		{
			printf("please input the student's number you want to modify:");
			scanf_s("%d", &snum);
			for (i = 0; i < (*m); i++)
			{
				if (student[i].number == snum)
				{
				A:printf("please input student's information:\n");
					printf("No.:");
					scanf_s("%d", &snum);
					student[i].number = snum;
					printf("name:");
					scanf_s("%s", student[i].name, 10);
					printf("Chinese grade:");
					scanf_s("%d", &student[i].Chinese);
					printf("math grade:");
					scanf_s("%d", &student[i].math);
					printf("English grade:");
					scanf_s("%d", &student[i].English);
					(student[i].total) = (student[i].Chinese) + (student[i].math) + (student[i].English);
					printf("total grade is :%d\n", student[i].total);
					if (fwrite(&student[i], sizeof(struct Student), 1, fp) == 1)
					{
						printf("the student's information successedly modify!\n");
					}
					else
					{
						printf("the student's information  can not successedly modify!\nplease input once again ");
						goto A;
					}
				}
			}
			printf("continue modify?<y/n>:\n");
			ch = getchar();  
			cha = getchar();
		} while (cha != 'n');
	}
	fclose(fp);
	printf("modify over!\n");
}
void order()
{
	int iMin;
	struct Student temp;
	FILE* fp;
	if ((err = fopen_s(&fp, "成绩", "ab+")) != 0)
	{
		printf("can not open file (delete)!");
		exit(0);
	}
	else
	{

		for (i = 0; i < (*m); i++)
		{
			fread_s(&student[i], sizeof(struct Student), sizeof(struct Student), 1, fp);
		}
		for (i = 0; i < ((*m)-1); i++)
		{
			iMin = student[i].total;
			for (j = i + 1; j < (*m); j++)
			{
				if (student[j].total <= iMin)
				{
					temp = student[j];
					student[j] = student[i];
					student[i] = temp;
				}
			}
		}
		for ( i = 0; i < (*m); i++)
		{
			printf("No.%d\nname:%s\nChinese:%d\nmath:%d\nEnglish:%d\ntotal:%d\norder:%d",
				student[i].number, student[i].name, student[i].Chinese, student[i].math, student[i].English, student[i].total,(i+1));
		}
		printf("press any key to exit order:");
		ch = getchar();   /*上一行的转义字符“\n”代表回车换行，是帮你输入了一个回车，说以要回收一下回车符，不然cha就直接为回车符*/
	
	}
	fclose(fp);

}
void count()
{
	num = 0;
	FILE* fp;
	if ((err = fopen_s(&fp, "成绩", "ab+")) != 0)
	{
		printf("can not open file (search)!");
		exit(0);
	}
	else
	{
		for (i = 0; i < (*m); i++)
		{
			fread_s(&student[i], sizeof(struct Student), sizeof(struct Student), 1, fp);
			num++;
		}
	}
	m = &num;
	printf("there are %d students' information in the system\n", *m);
	fclose(fp);
}

int main()
{
	printf("please input any key to enter the students' grade management system\n");
	ch=_getch();           /*只要输入了一个字符就立刻读入，不用回车，当做“任意键继续”，所属头文件是conio.h*/
	while (1)
	{
		menu();
	    loop:scanf_s("%d", &enter);
		switch (enter)
		{
		case 0:
			exit(0);
		case 1:
			input();
			break;
		case 2:
			search();
			break;
		case 3:
			delete();
			break;
		case 4:
			modify();
			break;
		case 5:
			order();
			break;
		case 6:
			count();
			break;
		default:
			printf("the number you input is wrong!please input the right number!\n");
			goto loop;
		}
	}
	return 0;
}
