#include <stdio.h>
#include <string.h>


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
            
            for(int i=0; i<=strlen(EncryptionText); i++){
        
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
            
            char EncryptKey[26];
            printf("\n Enter Encryption Key:");
            scanf("%s", EncryptKey);

            for(int i = 0; i<=strlen(EncryptionText); i++){
            
                if(EncryptionText[i]>='a' && EncryptionText[i]<='z'){
                EncryptionText[i] = EncryptKey[ ((int) EncryptionText[i]) - ((int) 'a')];
                }
                else if(EncryptionText[i]>='A' && EncryptionText[i]<='Z'){
                EncryptionText[i] = EncryptKey[ ((int) EncryptionText[i]) - ((int) 'A' ) ]; 
                }
            }
    
            printf("%s", EncryptionText); 
            return 0;

        }
    }
    else if(x == 2){
        
        char DecryptionText[9999];
        printf("\n Enter Text for Decryption:");
        scanf("%[^\n]s", DecryptionText);  // this should read to newline but doesnt work properly in compilers?
        
        if(y == 1){
            
            int k=0;
            printf("\nEnter Decryption Key:");
            scanf("%d", &k);
            
            for(int i=0; i<=strlen(DecryptionText); i++){
        
                if(DecryptionText[i] == 32){
                    continue;   //32 is ASCII whitespace so this tells the code if it detects whitespace to not encrypt it.
                }
                else if(DecryptionText[i]>=65 && DecryptionText[i]<=90){
                    DecryptionText[i] = DecryptionText[i]-65 +26 ;  //Moves ASCII values to between 0 and 26 by substracting ASCII value for A
                    DecryptionText[i] = ((DecryptionText[i] - k)%26); //Rotates k places inversely around alphabet. The %[mod operand] ensures it works for letters later by skipping back to start of alphabet
                    DecryptionText[i] = DecryptionText[i]+65; //Moves values back to ASCII values.
                }
                else if(DecryptionText[i]>='a' && DecryptionText[i]<='z'){
                    DecryptionText[i] = DecryptionText[i]-97+26; 
                    DecryptionText[i] = ((DecryptionText[i] - k )%26);   
                    DecryptionText[i] = DecryptionText[i]+97;
                }
        
            }
            
            
            printf("%s", DecryptionText);  //Prints the String
              
            return 0; //END of code
        }
        else if(y == 2){
                
            for(int k=1; k<=25; k++){                
                for(int i=0; i<strlen(DecryptionText); i++){                
                    if(DecryptionText[i]>=65 && DecryptionText[i]<=90){
                        DecryptionText[i] = ((DecryptionText[i]-65+1)%26)+65;                       
                    }   
                }   
                int x=26 - k;
                printf("\n%d: %s", x, DecryptionText);
            }
        }
        else if(y == 3){
            
            char SDecryptKey[26];
            printf("Enter Decryption Key:");
            scanf("%s", SDecryptKey);
            
            char DecryptionTextCopy[9999];
    
            for(int i=0; i<strlen(SDecryptKey); i++){
                for(int j=0; j<strlen(DecryptionText); j++){
                    if(SDecryptKey[i] == DecryptionText[j] ){
                        DecryptionTextCopy[j] = i+1000+65; // To Put it outside ascii range so it doesnt get confused with other characters
                    }
                }
            }
            
            for(int l=0; l<strlen(DecryptionText); l++){
                if(DecryptionText[l]>='A' && DecryptionText[l]<='Z'){
                    DecryptionTextCopy[l] = DecryptionTextCopy[l] - 1000;
                }
                else if(DecryptionText[l] == 32){
                    DecryptionTextCopy[l] = 32;
                }
                
            }
            
            printf("%s", DecryptionTextCopy);
            
            return 0;
            
        }
    }
    
}