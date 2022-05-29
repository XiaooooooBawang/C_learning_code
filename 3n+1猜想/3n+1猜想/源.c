#include<stdio.h>
int main()
{
    int a, b = 0;
    scanf("%d", &a);
    do
    {
 
        if ((a % 2) == 0)
        {
           a = a / 2;
           b++;
        }
        else
        {
            a = (3 * a + 1) / 2;
            b++;
        }
    } while (a != 1);
    printf("%d", b);
}
