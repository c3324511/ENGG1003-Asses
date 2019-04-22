#include <stdio.h>
#include <string.h>
#include "SubDecrypt-K.h"



int main(){
    
    for(int i=0; i<=strlen(SDecryptKey); i++){
        for(int j=0; j<=strlen(SubDecrypt); j++){
            if(SDecryptKey[i] == SubDecrypt[j]){
                SubDecrypt[j] = i+1000; // To Put it outside ascii range so it doesnt get confused with other characters
            }
        }
        
    }
    
    for(int l=0; l<=strlen(SubDecrypt); l++){
        SubDecrypt[l] = SubDecrypt[l] - 1000;
    }
    
    printf("%s", SubDecrypt);
    
}