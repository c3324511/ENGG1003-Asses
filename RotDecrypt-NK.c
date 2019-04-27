#include <stdio.h>
#include <string.h>


int main(){
    
    char RotDecryptNK[] = "uryyb jbeyq";
    printf("%s", RotDecryptNK);
    int k=13;    
     
    for(int i=0; i<=100; i++){
        
        if(RotDecryptNK[i]>=65 && RotDecryptNK[i]<=90){
            RotDecryptNK[i] = RotDecryptNK[i]-65 +26 ;  //Moves ASCII values to between 0 and 26 by substracting ASCII value for A
            RotDecryptNK[i] = ((RotDecryptNK[i] - k)%26); //Rotates 13 places around alphabet. The % ensures it works for letters later by skipping back to start of alphabet
            RotDecryptNK[i] = RotDecryptNK[i]+65; //Moves values back to ASCII values.
            printf("%s", RotDecryptNK);
     }   

    }    

    printf("%s", RotDecryptNK);
    
}