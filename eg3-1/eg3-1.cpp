#include <stdio.h>
int main()
{
    FILE *fp;
    FILE *fptr;
    int c;
    int n = 0;
    // cout if " appear in the first time
    int COUNT = 0;
    
    fp = fopen("problem.txt", "r");
    fptr = fopen("answer.txt", "w");
    if (fp == NULL)
    {
        perror("Error in opening file");
        return (-1);
    } 
    do 
    {
        c = fgetc(fp);
        
        if (feof(fp))
        {
            break;
        }
        if (c == '\"' && COUNT % 2 == 1)
        {
            fprintf(fptr, "``");
            COUNT ++;
            printf("%d", COUNT);
        }
        if (c == '\"' && COUNT % 2!= 1)
        {
            putc(c, fptr);
            COUNT++;
            printf("%d", COUNT);
        }
        
        else {
            putc(c, fptr);
        }
        
    }
    while (1);
    fclose(fp);
    fclose(fptr);
    return 0;
}