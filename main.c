#include <stdio.h>
#include <string.h>




int main() {
    
    const char str1[100] = "THIS IS TEXT";
    char str2[100];
    
    
    int i=0, k, r=0;
    
    printf("\nEnter Eccryption Text: ");    
    scanf("%[^\n]", str2;
    
    
    
    
    start:printf("\nEnter Encryption Key:");
    scanf("%d", &k);
    
    if(k<0 || k>26){
        printf("Key must be between 0 and 26\n");
        goto start;
    }
    else if(k>=0 && k<=26){
        
    }
    
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