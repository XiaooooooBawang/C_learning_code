#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
int main()
{
	struct node* head, * p, * q,*t;  /*head是头指针,p是上一个节点，q是新节点*/
	int n, a, i;
	scanf_s("%d", &n);
	head = NULL;
	for ( i = 0; i < n; i++)
	{
		scanf_s("%d", &a);
		p = (struct node*)malloc(sizeof(struct node));
		q = (struct node*)malloc(sizeof(struct node));

		if (p==NULL||q==NULL)
		{
			printf("创建链表失败");
		}
		else
		{
			p->data = a;
			p->next = NULL;
			if (head == NULL)
			{
				head = p;
			}
			else
			{
				q->next = p;
			}
			q = p;
		}
	}
	t = head;
	while (t!=NULL)
	{
		printf("%d ", t->data);
		t = t->next;
	}
	free(q);

}