#include <stdio.h>
#include <strings.h>


int main(){
    
    int x = 0;
    int y = 0;
    
    menu: printf("\nSelect Encryption/Decrytpion: \n Enter 1 to Encrypt. \n Enter 2 to Decrypt. \n Entry:");
    scanf("%d", &x);
    
    if(x == 1){
        printf("\n Select Encryption Type: \n Enter 1 for Rotation Encryption. \n Enter 2 for Substitution Encryption.\n Entry:");
        scanf("%d", &y);  
        if(y != 1 && y != 2){
            printf("\nEntry Not Recognised, Returning to Original menu.\n");
            goto menu;
        }
    }
    else if(x == 2){
        printf("\n Select Decryption Type. \n Enter 1 for Rotation Decryption with Key. \n Enter 2 for Rotation Decryption without Key. \n Enter 3 for Substitution Decryption with Key. \n Entry:");
        scanf("%d", &y); 
        if(y != 1 && y != 2 && y!=3){
            printf("\nEntry Not Recognised, Returning to Original menu.\n");
            goto menu;
        }
    }
    else if(x != 1 && x != 2){
        printf("\nEntry Not Recognised, Try Again.\n");
        goto menu;
    }
    
    
    if(x == 1){
        
        char EncryptionText[9999];
        printf("\n Enter Text for Encryption:");
        scanf("%[^\n]s", EncryptionText);  // this should read to newline but doesnt work properly in compilers?
        
        if(y == 1){
            int k=0;
            printf("/n Enter Encryption Key:");
            scanf("%d", &k);
            
            for(i=0; i<=strlen(EncryptionText); i++){
        
                if(EncryptionText[i] <'A'){
                    continue;   //32 is ASCII whitespace so this tells the code if it detects whitespace to not encrypt it.
                }
                else if(EncryptionText[i]>'Z' && EncryptionText[i]<'a'){
                    continue;
                }
                else if(EncryptionText[i]>'z'){
                    continue;
                }
                else if(EncryptionText[i]>=65 && EncryptionText[i]<=90){
                    EncryptionText[i] = EncryptionText[i]-65;  //Moves ASCII values to between 0 and 26 by substracting ASCII value for A
                    EncryptionText[i] = ((EncryptionText[i] + k)%26); //Rotates 13 places around alphabet. The % ensures it works for letters later by skipping back to start of alphabet
                    EncryptionText[i] = EncryptionText[i]+65; //Moves values back to ASCII values.
                }
                else if(EncryptionText[i]>='a' && EncryptionText[i]<='z'){
                    EncryptionText[i] = EncryptionText[i]-97; 
                    EncryptionText[i] = ((EncryptionText[i] + k)%26);   
                    EncryptionText[i] = EncryptionText[i]+65;
                }

             }
        
             printf("%s", EncryptionText);  //Prints the String
             return 0;
        }
        else if(y == 2){

            for(int i = 0; i<=strlen(EncryptionText); i++){
            
                if(EncryptionText[i]>='a' && EncryptionText[i]<='z'){
                EncryptionText[i] = EncryptKey[ ((int) EncryptionText[i]) - ((int) 'a')];
                }
                else if(EncryptionText[i]>='A' && EncryptionText[i]<='Z'){
                EncryptionText[i] = EncryptKey[ ((int) EncryptionText[i]) - ((int) 'A' ) ]; 
                }
            }
    
    printf("%s", EncryptionText);  

        }
    }
    
}