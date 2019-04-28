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
        printf("\n Enter Text for Encryption:");
        
    }
    
}