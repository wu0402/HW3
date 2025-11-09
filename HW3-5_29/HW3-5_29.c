#include <stdio.h>

int GCD(int a, int b);

int LCM(int a, int b);

int main()
{
    int i, j;
    printf("請輸入兩個整數：");
    scanf("%d %d", &i, &j);
    
    printf("最小公倍數為：%d\n", LCM(i, j));
    return 0;
}

int GCD(int a, int b) 
{
    while(b != 0) 
	{
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int LCM(int a, int b)
{
    return ((a * b) / GCD(a, b));
}

