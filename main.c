#include <stdio.h>
#include <string.h>




int main() {
    
    const char str1[100] = "This is Text";
    char str2[100];
    strcpy(str2, str1);
    
    printf("%s", str1);
    
    
    
    return 0;
}