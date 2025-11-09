#include <stdio.h>
#include <ctype.h>

char changeCase(char ch);

int main()
{
    char input;
    printf("請輸入一個字母：");
    scanf("%c", &input);
    
    char result = changeCase(input);
    printf("轉換後的結果： %c\n", result);
    
    return 0;
}

char changeCase(char ch) {
    if(isupper(ch)) 
    {
        return tolower(ch);
    } 
    else if(islower(ch)) 
    {
        return toupper(ch);
    }
    return ch;
}
