/*
https://www.hackerrank.com/challenges/printing-tokens
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);

    for(char *i = s; *i !=NULL ; i++){
        if(*i==' ')
        *i='\n';
    }
    printf("%s",s);
    
    return 0;
}
