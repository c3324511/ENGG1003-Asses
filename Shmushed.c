#include <stdio.h> // including this library so scanf() and printf() functions can be used.
#include <string.h>  //including this library so the strlen() function can be used.


int main(){
    
    int x = 0; //initialising variable to use in the menu
    int y = 0; //initialising variable to use in the sub menu
    
    /*
     Okay so this menu works basically just by taking a user input and using that to initialise my variables. it asks for a value to put to 'x'
     and then uses if statements to control what it asks for when initilising 'y'. If x is put to 1, it runs to the encryption meny, and if x is set 
     to 2 it runs the decryption menu. If x is any other number it prints an error message and uses a goto statement (menu), to return to the start of the menu.
     If y is a number not recognised in the menu it does the same thing. The initialiseed variables are then used later to tell which part of the code to run.
     */
    
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
    
    /*
     Here we just use a bit of flow control using if statetments to make it so only the selected part of the program runs. Works pretty much the same as the menu flow control, based on input values for x and y.
     */
    
    
    if(x == 1){
        
        /*
         Here imma just initialising the string and reading user input to the string. This is the text that will be encrypted.
         */
        char x;
        char EncryptionText[9999];  //Initilasing array for the string.
        scanf("%c", &x);
        printf("\n Enter Text for Encryption:"); //Prompts user to enter the text for encryption.
        scanf("%[^\n]s", EncryptionText);  // this should read to newline but doesnt work properly in compilers?
        
        if(y == 1){
            
            /*
             This section is for a rotation encryption. it works just by applying some maths to the ascii values of the numbers to rotate
             them around a bit.
             */
            
            int k=0; //initialising k which stores the key we use.
            printf("/n Enter Encryption Key:"); //prompts user to enter the encryption key.
            scanf("%d", &k); //scans entered key and stores as k.
            
            for(int i=0; i<=strlen(EncryptionText); i++){
        
                if(EncryptionText[i] <'A'){
                    continue;   //32 is ASCII whitespace so this tells the code if it detects whitespace to not encrypt it.
                }
                else if(EncryptionText[i]>'Z' && EncryptionText[i]<'a'){
                    continue; //tells code not to encrypt anything thats not a letter.
                }
                else if(EncryptionText[i]>'z'){
                    continue; // also tells code not to encrypt non letters
                }
                else if(EncryptionText[i]>=65 && EncryptionText[i]<=90){ //encryption for capital letters.
                    EncryptionText[i] = EncryptionText[i]-65;  //Moves ASCII values to between 0 and 26 by substracting ASCII value for A
                    EncryptionText[i] = ((EncryptionText[i] + k)%26); //Rotates k places around alphabet. The % ensures it works for letters later by skipping back to start of alphabet
                    EncryptionText[i] = EncryptionText[i]+65; //Moves values back to ASCII values.
                }
                else if(EncryptionText[i]>='a' && EncryptionText[i]<='z'){ //encryption for lower case letters. returns them as capitals.
                    EncryptionText[i] = EncryptionText[i]-97; //Moves ASCII values to between 0 and 26 by substracting ASCII value for a
                    EncryptionText[i] = ((EncryptionText[i] + k)%26);   //Rotates k places around alphabet. The % ensures it works for letters later by skipping back to start of alphabet
                    EncryptionText[i] = EncryptionText[i]+65; //Moves values to ASCII values for capital letters.
                }

             }
        
             printf("%s", EncryptionText);  //Prints the encrypted text
             return 0;  //ends the code run. dont want it to run the rest when it doesnt need to.
        }
        else if(y == 2){
            
            /*
             Here we got the substitution encryption. It works by doing some mathsy stuff and by using a letters value to tell it how far along the key string the replacement is, and to then replace it with that.
             */
            
            char EncryptKey[26]; //initalises an array to take a string used as the key
            printf("\n Enter Encryption Key:"); //promts user to enter the key used for the encryption
            scanf("%s", EncryptKey); //reads the key and stores it in the EncryptKey array.

            for(int i = 0; i<=strlen(EncryptionText); i++){ //this loop is used to cylce through the text one letter at a time, until it reaches the value for the maximum in the string.
            
                if(EncryptionText[i]>='a' && EncryptionText[i]<='z'){ //this does the lower case letters.
                EncryptionText[i] = EncryptKey[ ((int) EncryptionText[i]) - ((int) 'a')]; //The letter we are at is replaced by the relevant letter in the key. This is done by taking the letters ascii value, subtracting the value for 'a' from it (so we get a number 0 for a, 1 for b, 2 for c, etc. because the first entry in a string is the 0th entry.), then replacing it with the character that is that distance along the key array. e.g. 'a' becomes 0 then is replaced by the 0th entry (which is actually the first letter) in the key.
                }
                else if(EncryptionText[i]>='A' && EncryptionText[i]<='Z'){ // this does capital letters, works exactly the same as lowercase letters, but adjusting for different ascii values of capitals.
                EncryptionText[i] = EncryptKey[ ((int) EncryptionText[i]) - ((int) 'A' ) ]; 
                }
            }
    
            printf("%s", EncryptionText); //prints the encrypted text
            return 0; //ends the code

        }
    }
    else if(x == 2){ //if decryption selected from menu
        
        char x; // this somehow makes scanf work? idk why but it ignores this
        char DecryptionText[9999]; //initialises array for text for decryption
        printf("\n Enter Text for Decryption:"); //prompts user to enter text for decryption
        scanf("%c", &x); // this somehow makes scanf work? idk why but it ignores this
        scanf("%[^\n]s", DecryptionText);  //reads text to encrypt from stdin.
        
        if(y == 1){ //if user selects rotation decryption with a key
            
            int k=0; //initalises k to be used as the key
            printf("\nEnter Decryption Key:"); // prompts user to enter decryption key
            scanf("%d", &k); //scans entered text and stores as k, to be used in the mathsy bit to rotate it.
            
            for(int i=0; i<=strlen(DecryptionText); i++){ //goes through text one character at a time until it reaches the end
        
                if(DecryptionText[i] == 32){
                    continue;   //32 is ASCII whitespace so this tells the code if it detects whitespace to not encrypt it.
                }
                else if(DecryptionText[i]>=65 && DecryptionText[i]<=90){ //this is for capital letters
                    DecryptionText[i] = DecryptionText[i]-65 +26 ;  //Moves ASCII values to between 0 and 26 by substracting ASCII value for A
                    DecryptionText[i] = ((DecryptionText[i] - k)%26); //Rotates k places inversely around alphabet. The %[mod operand] ensures it works for letters later by skipping back to start of alphabet
                    DecryptionText[i] = DecryptionText[i]+65; //Moves values back to ASCII values.
                }
                else if(DecryptionText[i]>='a' && DecryptionText[i]<='z'){ //this is for lower case letters, works same as for capital letters, returning rotated letters as capitals
                    DecryptionText[i] = DecryptionText[i]-97+26; 
                    DecryptionText[i] = ((DecryptionText[i] - k )%26);   
                    DecryptionText[i] = DecryptionText[i]+65;
                }
        
            }
            
            
            printf("%s", DecryptionText);  //Prints the decrypted text
              
            return 0; //END of code
        }
        else if(y == 2){ //if rotation decryption without key is selected
        
        /*
         k so this basically works by brute forcing every possible combination, and printing all combinations to the screen. It rotates through, and using a key of one, moves one rotation further each time, 
         then prints that result to the screen before rotating one further and printing that to the screen. User then has to go through and see which one it is. Tells user which key it has.
         */
                
            for(int k=1; k<=25; k++){ //there are only 25 possible rotations (assuming it isnt already decrypted text), this just sets it up to go through 25 times.    
                for(int i=0; i<strlen(DecryptionText); i++){ // goes through the text one character at time, and rotates it one place.   
                    if(DecryptionText[i]>=65 && DecryptionText[i]<=90){ //for capital letters, rotates one place around the alphabet and returns capital letter.
                        DecryptionText[i] = ((DecryptionText[i]-65+1)%26)+65; // lowers to between 1 and 26, adds on, then performs mod 26 takes remainder, then adds 65 to return to ascii values for capital letters.                 
                    }   
                    if(DecryptionText[i]>='a' && DecryptionText[i]<='z'){ //for lowercase letters, rotates one place around the alphabet and returns a capital. works same as for capital letters
                        DecryptionText[i] = ((DecryptionText[i]-'a'+1)%26)+65;                       
                    } 
                }   
                int x=26 - k; //this is just so when it prints it prints the associated encryption, because it prints the 25th rotation first, then the 24th etc.
                printf("\n%d: %s", x, DecryptionText); // prints the number of the rotation from the original (so the key used), and the text produced for that key.
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