#include <stdio.h>

int power(int a, int b);

int main()
{
    int i, j;
    printf("請輸入底數與次方：");
    scanf("%d %d", &i, &j);
    
    printf("結果為：%d\n", power(i, j));
    return 0;
}

int power(int a, int b)
{
    if (b == 0) return 1;                
    return a * power(a, b - 1);
}

