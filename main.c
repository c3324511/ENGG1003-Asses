#include <stdio.h>
#include <string.h>




int main() {
    
    const char str1[100] = "THIS IS TEXT";
    char str2[100];
    strcpy(str2, str1);
    
    int i=0, k=13;
    
    for(i=0; i<=strlen(str2); i++){
        
        if(str2[i] == 32){
            continue;
        }
        else if(str2[i]>=65 && str2[i]<=90){
        str2[i] = str2[i]-65;
        str2[i] = ((str2[i] + k)%26);
        str2[i] = str2[i]+65;
        }

    }
    
    
    printf("%s", str2);
    
    
    
    return 0;
}