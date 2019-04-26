#include <stdio.h>
#include <string.h>
#include "SubDecrypt-K.h"



int main(){
    
    printf("%lu\n", strlen(SubDecrypt));   
    int j=0;
    int i=0;
    if(i<strlen(SubDecrypt)){
        if(j<strlen(SDecryptKey)){
            if(SDecryptKey[j] == SubDecrypt[i]){
                SubDecrypt[i] = j+65+1000; // To Put it outside ascii range so it doesnt get confused with other character
            }
        j++;
        }

     i++;   
    }
    
    
    for(int l=0; l<=strlen(SubDecrypt); l++){
        SubDecrypt[l] = SubDecrypt[l] - 1000;
        
    }
    printf("%lu\n", strlen(SubDecrypt));
    printf("%s\n", SubDecrypt);
    
}