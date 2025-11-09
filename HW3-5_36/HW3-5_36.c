#include <stdio.h>
#include <limits.h>

void hanoi(int n, char src, char dst, char aux, unsigned long long *count) {
    if (n == 0) return;
    hanoi(n - 1, src, aux, dst, count);
    printf("Move disk %d from %c to %c\n", n, src, dst);
    (*count)++;
    hanoi(n - 1, aux, dst, src, count);
}

unsigned long long minimal_moves(int n) {
	int i;
    unsigned long long m = 0ULL;
    for (i = 0; i < n; ++i) {
        if (m > ULLONG_MAX / 2) return ULLONG_MAX; 
        m = m * 2ULL + 1ULL;
    }
    return m;
}

int main(void) {
    int n;
    printf("請輸入漢諾塔盤數 n (>= 0)：");
    if (scanf("%d", &n) != 1) return 1;
    if (n < 0) return 1;

    unsigned long long moves = minimal_moves(n);
    if (moves == ULLONG_MAX) {
        printf("最少步數: 超過 unsigned long long 可表示範圍\n");
    } else {
        printf("最少步數: %llu\n", moves);
    }

    if (n <= 20) {
        unsigned long long count = 0ULL;
        printf("列印移動步驟：\n");
        hanoi(n, 'A', 'C', 'B', &count);
        printf("已列印 %llu 步驟\n", count);
    } else {
        printf("盤數過多（n > 20），為避免輸出過大不列印每一步驟。\n");
    }

    return 0;
}

