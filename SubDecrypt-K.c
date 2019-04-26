#include <stdio.h>
#include <string.h>
#include "SubDecrypt-K.h"



int main(){
    
    char SubDecryptCopy[strlen(SubDecrypt)];
    
   for(int i=0; i<=strlen(SDecryptKey); i++){
        for(int j=0; j<=strlen(SubDecrypt); j++){
            if(SDecryptKey[i] == SubDecrypt[j] && SubDecrypt[j] != ' ' ){
                SubDecryptCopy[j] = i+1000+65; // To Put it outside ascii range so it doesnt get confused with other characters
            }
        }
    }
    
    for(int l=0; l<=strlen(SubDecrypt); l++){
        if(SubDecrypt[l]>='A' && SubDecrypt[l]<='Z'){
            SubDecryptCopy[l] = SubDecryptCopy[l] - 1000;
        }
        
    }
    
    
    
    printf("%s", SubDecryptCopy);
    
}