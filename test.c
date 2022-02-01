#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void t(char *s) {
    s++;
   s++;
   *s = '\0';
   s++;
    printf("%s\n", s);


}

int main(){
    char *test_ptr;

    char *s =(char*) malloc(sizeof(char)*10);
    strcpy(s, "hello");
    test_ptr = s;
    test_ptr++;
    printf("Test ptr: %s \n", test_ptr);
    printf("Test ptr: %s\n", s);
    t(test_ptr);
    printf("Test ptr: %s\n", s);
    free(s);
    return 0;
}