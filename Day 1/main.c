#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{

    if (argc != 2) {
        printf("%s\n", "Provide only one input file");
        return 1;
    }

    FILE *fptr;
    fptr = fopen(argv[1], "r");
    if (fptr == NULL)
    {
        printf("File could not be opened");
        return 1;
    }
    

    bool two_nums = false;
    bool is_first = true;
    char first;
    char last;
    char ch;
    int result = 0;
    for (ch = getc(fptr); ch != EOF; ch = getc(fptr)) {
        

        if (isdigit(ch) != 0)
        {
            if (is_first) {
                first = ch;
                is_first = false;
            }
            else {
                last = ch;
                two_nums = true;
            }
            
        }
        if (ch == '\n')
        {        
            if (two_nums == false)
            {
                char temp[] = {first, first, '\0'};
                result += atoi(temp);
            }
            else 
            {
                char temp[3] = {first, last, '\0'};
                result += atoi(temp);
            }   
            printf("current result:%d\n",result);
            is_first = true;
            two_nums = false;
        }
    }
    fclose(fptr);
    printf("The result is %d\n", result);
    return 0;
}
