#include<stdio.h>
#include<string.h>
int main()
{
	struct per
	{
		char id[10];
		char name[10];
		int number;
		char sex[10];	
		union data
		{
			char subject[10];
			int class;
		}st;

	}people[2] = {0};
	printf("first input identity(teacher/student),then input name ,then number,then sex,then subject/class\n");
	
	for (int i = 0; i < 2; i++)
	{
		scanf_s("%s%s%d%s", people[i].id,9, people[i].name,9, &people[i].number, people[i].sex,9);
		if (strcmp(people[i].id , "teacher")==0)
		{
			scanf_s("%s",people[i].st.subject, 9);
		}
		else 
		{
			scanf_s("%d", &people[i].st.class);
		}
	}
	for (int i = 0; i < 2; i++)
	{
		if (strcmp(people[i].id, "teacher") == 0)
		{
			
			printf("%s\t%s\t%d\t%s\t%s\n", people[i].name, people[i].id, people[i].number, people[i].sex, people[i].st.subject);
		}
		else
		{
			printf("%s\t%s\t%d\t%s\t%d\n", people[i].name, people[i].id, people[i].number, people[i].sex, people[i].st.class);
		}
	}
	return 0;
}


