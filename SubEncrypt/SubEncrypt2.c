#include <stdio.h>
#include <string.h>
#include "SubEncrypt.h"

int main(){

    for(int i = 0; i<=strlen(SubEncrypt); i++){
    
        if(SubEncrypt[i]>='a' && SubEncrypt[i]<='z'){
        SubEncrypt[i] = EncryptKey[ ((int) SubEncrypt[i]) - ((int) 'a')];
        }
        else if(SubEncrypt[i]>='A' && SubEncrypt[i]<='Z'){
        SubEncrypt[i] = EncryptKey[ ((int) SubEncrypt[i]) - ((int) 'A' )  + 25];
        }
        

    }
    
    
    printf("%s", SubEncrypt);  




}