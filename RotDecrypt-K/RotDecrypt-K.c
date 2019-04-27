#include <stdio.h>  //Includes standard library
#include <string.h>  //Includes String Library
#include "RotDecrypt-K.h"



int main() {
    
    
      int i=0;     
  
  
        
    for(i=0; i<=strlen(RotDecrypt); i++){
        
        if(RotDecrypt[i] == 32){
            continue;   //32 is ASCII whitespace so this tells the code if it detects whitespace to not encrypt it.
        }
        else if(RotDecrypt[i]>=65 && RotDecrypt[i]<=90){
            RotDecrypt[i] = RotDecrypt[i]-65 +26 ;  //Moves ASCII values to between 0 and 26 by substracting ASCII value for A
            RotDecrypt[i] = ((RotDecrypt[i] - k)%26); //Rotates 13 places around alphabet. The % ensures it works for letters later by skipping back to start of alphabet
            RotDecrypt[i] = RotDecrypt[i]+65; //Moves values back to ASCII values.
        }
        else if(RotDecrypt[i]>='a' && RotDecrypt[i]<='z'){
            RotDecrypt[i] = RotDecrypt[i]-97+26; 
            RotDecrypt[i] = ((RotDecrypt[i] - k )%26);   
            RotDecrypt[i] = RotDecrypt[i]+97;
        }

    }
    
    
    printf("%s", RotDecrypt);  //Prints the String
    
    
    
    return 0; //END of code
}