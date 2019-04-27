#include <stdio.h>
#include <string.h>


int main(){
    
    char RotDecryptNK[] = "WTAAD LDGAS";    
    
        
    int i=0;
    
    for(int k=1; k<=25; k++){
        
        for(i=0; i<strlen(RotDecryptNK); i++){
        
            if(RotDecryptNK[i]>=65 && RotDecryptNK[i]<=90){
                RotDecryptNK[i] = ((RotDecryptNK[i]-65+1)%26)+65;
     
                
            }   

        }   
        int x=26 - k;
        
        printf("\n%d: %s", x, RotDecryptNK);
    }


    
    
}