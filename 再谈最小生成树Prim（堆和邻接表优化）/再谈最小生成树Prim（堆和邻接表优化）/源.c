#include<stdio.h>             //堆优化的思想就是用堆来管理dis的值
int heap[100], dis[100], pos[100],book[100];
int first[100], next[100],u[100],v[100],w[100];
int n, m,inf=999999,count,sum,k,j,size;     //n点，m边
void swap(int x,int y)
{
	int t;
	t = heap[x];
	heap[x] = heap[y];
	heap[y] = t;
	t = pos[heap[x]];           //也要同步更新pos
	pos[heap[x]] = pos[heap[y]];
	pos[heap[y]] = t;
}
void siftdown(int a)
{
	int flag = 0,t;
	while (flag==0&&2*a<=size)
	{
		if (dis[heap[a]-1] > dis[heap[2 * a]-1])
			t = 2 * a;
		else
			t = a;
		if (2*a+1<=size)
		{
			if (dis[heap[t]-1]>dis[heap[2*a+1]-1])
				t = 2 * a + 1;
		}
		if (t != a)
		{
			swap(a, t);
			a =t;
		}
		else
			flag = 1;
		
	}
}
void siftup(int a)
{
	int flag = 0;
	if (a==1)
	{
		return;
	}
	while (flag==0&&a/2>=1)
	{
		if (dis[heap[a]-1] < dis[heap[a / 2]-1])
		{
			swap(a, a / 2);
			a /= 2;
		}
		else
			flag = 1;
	}
}
int pop()
{
	int t;
	t = heap[1];
	pos[heap[1]] = 0;
	heap[1] = heap[size];
	pos[heap[1]] = 1;
	size--;
	siftdown(1);
	return t;
}

int main()
{
	scanf_s("%d%d", &n, & m);
	size = n;
	for (int i = 0; i < m; i++)
	{
		scanf_s("%d%d%d", &u[i], &v[i], &w[i]);
	}
	//开始邻接表存储边
	for (int i = m; i < 2*m; i++)       //无向图双向存储
	{
		u[i] = v[i - m];
		v[i] = u[i - m];
		w[i] = w[i - m];
	}
	for (int i = 0; i < n; i++)      
	{
		first[i] = -1;
	}
	for (int i = 0; i < 2*m; i++)     //注意是双向图，两倍m的条数,但上面first还是n，因为first存的是某点的第一条出边，点数不变
	{
		next[i] = first[u[i]-1];
		first[u[i]-1] = i;
	}
	for (int i = 0; i < n; i++)
	{
		dis[i] = inf;
	}
	for (int i = 1; i <= n; i++)    //初始化堆和顶点位置
	{
		heap[i] = i;
		pos[i] = i;
	}
	//prim核心算法
	k = first[0];          //将起点1的出边录入dis中
	while (k!=-1)
	{
		dis[v[k]-1] = w[k];
		k = next[k];
	}
	//起点是1
	book[0] = 1;      
	dis[0] = 0;
	pos[1] = 0;
	count++;
	pop();   //此时堆顶是1，起点是1，弹出1号顶点；
	while (count < n)
	{
		j = pop();
		book[j-1] = 1;
		count++;
		sum+=dis[j-1];
		k = first[j-1];
		while (k != -1)
		{
			if (book[v[k]-1] == 0 && dis[v[k]-1] >w[k])
			{
				dis[v[k]-1] = w[k];   //松弛成功后dis只会变小，所以下面就是向上调整
				siftup(pos[v[k]]);   //此时pos的作用出现了，搜索邻接表的时候是不知这个顶点在堆中位置的，所以要用pos记录
			}
			k = next[k];
		}
	}
	printf("%d", sum);
}