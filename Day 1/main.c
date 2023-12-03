#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char input[] = "g1ivm7ng";

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
    


    int is_first = 0;
    int first;
    int last;
    char ch;
    int result = 0;
    for (ch = getc(fptr); ch != EOF; ch = getc(fptr)) {
        

        if (isdigit(ch) != 0)
        {
            if (is_first == 0) {
                first = (int) (ch - 48);
                is_first = 1;
            }
            else {
                last = (int) (ch - 48);
            }
            
        }
        if (ch == '\n')
        {
            
            result += (first + last);
            is_first = 0;
        }
    }
    fclose(fptr);
    printf("The result is %d\n", result);
    return 0;
}
