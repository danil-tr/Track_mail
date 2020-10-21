#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* Input(int *length)
{
    int MAX_SIZE = 10;
    int cur_length = 0;
    *length = 0;
    char* buffer = (char *) calloc(MAX_SIZE, sizeof(char));

    while( scanf("%10[^\n]%n", buffer + *length, &cur_length) != 0)
    {   scanf("%*1[\n]");
        *length += cur_length;
        if ( *length > MAX_SIZE/2 )
        {
            MAX_SIZE *= 2;
            buffer = (char*) realloc(buffer, MAX_SIZE * sizeof(char) );
            printf("\nРасширение\n");
        }

    }
    *(buffer + *length) = '\0';
    return buffer;

}

int main()
{
    int string_length = 0;
    char *str = NULL;

    str = Input(&string_length); 
    printf("String: %s, length: %d\n", str, string_length);
    
    free(str);
    return 0;
}
