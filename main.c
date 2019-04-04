#include <stdio.h>  //Includes standard library
#include <string.h>  //Includes String Library




int main() {
    
    
    char str2[10000];  //Initialising str2 to handle up to 10000 characters
    
    
    int i=0, k;  //Initialising variables i and k as integers. i is used as a counter in a loop later, and k is used as the encryption key
    
    printf("\nEnter Eccryption Text: ");    //tells user to enter text to encrypt
    scanf("%[^\n]", str2);   //reads text user inputs and stores as string str2
    /*
     So I think this just reads through and scans until
     it reaches a new line, rather than whitespace as %s
     normally does.
     */
    
    
    
    
    start:printf("\nEnter Encryption Key:"); // tells user to enter encryption key
    scanf("%d", &k);  // scans and stores encryprion key as variable k
    
    if(k<0 || k>26){
        printf("Key must be between 0 and 26\n");
        goto start;
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