#include <stdio.h>
#include <limits.h>

unsigned long long fibonacci(unsigned int n);
unsigned int max_fibonacci_index(void);

int main(void)
{
    unsigned int n;
    printf("請輸入欲計算的 Fibonacci 編號 n (從 0 開始)：");
    if (scanf("%u", &n) != 1) return 1;

    unsigned int max_idx = max_fibonacci_index();
    if (n > max_idx) {
        printf("注意：n = %u 超過系統可表示的最大 Fibonacci 編號 %u，結果會發生溢位。\n", n, max_idx);
    }

    unsigned long long fn = fibonacci(n);
    printf("F(%u) = %llu\n", n, fn);

    printf("系統可表示的最大 Fibonacci 編號: %u\n", max_idx);
    
    printf("該值為: %llu\n", fibonacci(max_idx));

    return 0;
}

unsigned long long fibonacci(unsigned int n)
{
	unsigned int i; 
    if (n == 0) return 0ULL;
    if (n == 1) return 1ULL;

    unsigned long long a = 0ULL;
    unsigned long long b = 1ULL;
    for (i = 2; i <= n; ++i) {
        unsigned long long next = a + b;
        a = b;
        b = next;
    }
    return b;
}

unsigned int max_fibonacci_index(void)
{
    
    unsigned long long a = 0ULL;
    unsigned long long b = 1ULL;
    unsigned int idx = 1; 

    while (ULLONG_MAX - b >= a) {
        unsigned long long next = a + b;
        a = b;
        b = next;
        ++idx;
    }
    return idx;
}

