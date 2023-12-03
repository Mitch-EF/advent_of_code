#include <stdio.h>
#include <ctype.h>

char input[] = "g1ivm7ng";

int main()
{
    int pair[2];
    int pos = 0;
    int index = 0;
    char ch = input[pos];
    
    

    while(ch != '\0') {
        //printf("%c", ch);
        if (isdigit(ch) != 0 && ch != '\0') {
            pair[index] = (int) (ch - 48);
            index++;
        }
        pos ++ ;
        ch = input[pos];
    }
    
    for(int i = 0; i < 2; i++) {
        printf("%d", pair[i]);
    }
    printf("\n");
    
    return 0;
}
