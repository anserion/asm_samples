#include <stdio.h>
#include <conio.h>
extern int func1(int); //���������� ��� ��������
main()
{int a,b;
printf("a="); scanf("%d",&a);
b=func1(a); //�������� ������� func1 �� ������� �����
printf("b=%d\n",b);
getch();
return 0;
}
