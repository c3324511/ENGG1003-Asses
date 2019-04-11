#include <stdio.h>  //Includes standard library
#include <string.h>  //Includes String Library



int main() {
    
    
    char str2[10000];  //Initialising str2 to handle up to 10000 characters
    
    
    int i=0, k;     //Initialising variables i and k as integers. i is used as a counter in a loop later, and k is used as the encryption key
    
     printf("Enter encryption text:");
     scanf("%[^\n]s", str2);
    
    start:printf("\nEnter Encryption Key:"); // tells user to enter encryption key
    scanf("%d", &k);  // scans and stores encryprion key as variable k
    
    if(k<0 || k>26){
        printf("Key must be between 0 and 26\n");
        //goto start;
    }
    else if(k>=0 && k<=26){
        
    }
    /*
     The If - Else if loop detects if k is an integer between 0 and 26
     If K is outside these values it tells the user it must be between 0 and 26
     and jumps back to telling the user to enter a key, then scans what the user imputs
     and does this until its a number between 0 and 26
     But if you enter a letter it runs and doesnt cipher the text
     */
    
    
    for(i=0; i<=strlen(str2); i++){
        
        if(str2[i] == 32){
            continue;   //32 is ASCII whitespace so this tells the code if it detects whitespace to not encrypt it.
        }
        else if(str2[i]>=65 && str2[i]<=90){
            str2[i] = str2[i]-65;  //Moves ASCII values to between 0 and 26 by substracting ASCII value for A
            str2[i] = ((str2[i] + k)%26); //Rotates 13 places around alphabet. The % ensures it works for letters later by skipping back to start of alphabet
            str2[i] = str2[i]+65; //Moves values back to ASCII values.
        }
        else if(str2[i]>='a' && str2[i]<='z'){
            str2[i] = str2[i]-97; 
            str2[i] = ((str2[i] + k)%26);   
            str2[i] = str2[i]+65;
        }

    }
    
    
    printf("%s", str2);  //Prints the String
    
    
    
    return 0; //END of code
}