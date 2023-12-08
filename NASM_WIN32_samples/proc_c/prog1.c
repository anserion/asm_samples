#include <stdio.h>
#include <conio.h>
extern int func1(int); //информация для сборщика
main()
{int a,b;
printf("a="); scanf("%d",&a);
b=func1(a); //вызываем функцию func1 из другого файла
printf("b=%d\n",b);
getch();
return 0;
}
