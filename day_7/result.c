#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp;
    char number[20];
    int i;
    int result;

    result = 0;
    i = 0;
    fp = fopen("output.txt", "r");
    fgets(number, 20, fp);
    while(number[i] != '.')
    {
        result += atoi(number);
        fgets(number, 20, fp);
    }
    printf("%d\n", result);
}