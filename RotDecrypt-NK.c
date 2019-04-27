#include <stdio.h>
#include <string.h>


int main(){
    
    char RotDecryptNK[] = "GDKKN VNQKC";
    
        
    int i=0;
    
    for(int k=1; k<=25; k++){
        
        for(i=0; i<=1000; i++){
        
            if(RotDecryptNK[i]>=64 && RotDecryptNK[i]<=90){
                RotDecryptNK[i] = RotDecryptNK[i]-65+26;
                RotDecryptNK[i] = ((RotDecryptNK[i] - k)%26);
                RotDecryptNK[i] = RotDecryptNK[i]+65; 
                
            }   

        }   
        
        printf("\n%d: %s", k, RotDecryptNK);
    }


    
    
}