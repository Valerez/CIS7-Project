#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

// declares class for the Vigenere cypher key, encryption, and decryption
class Vigenere
{
private:
    
public:
    // variable that holds the key to be implemented in the encryption and decryption
    string key;

    // collects the string key and adds each of the key characters to an array
    Vigenere(string key)
    {
      for(int i=0; i<key.size(); ++i)
      {
          if(key[i] >= 'A' && key[i] <= 'Z')
            this->key += key[i];
          else if(key[i] >= 'a' && key[i] <= 'z')
            this->key += key[i] + 'A' - 'a';
      } 
    }

    // collects the input from the user, encrypts string, and returns  // encrypted string
    string encrypt(string message)
    {
      string encytdTxt;
    
      for(int i=0,j=0;i<message.length(); ++i)
      {
        char c = message[i];
        
        if(c >= 'a' && c < 'z')
            c += 'A' - 'a';
        //else if (c < 'A' || c < 'Z')
            //continue;
        
        encytdTxt += (c + key[j] - 2 * 'A') % 26 + 'A';
        j = (j + 1) % key.length();
      }   
      return encytdTxt;
    }

    // collects the input from the user, decrypts string, and returns
    // decrypted message
    string decrypt(string message)
    {
      string dcyptTxt;
    
      for(int i=0, j=0; i < message.length(); ++i)
      {
        char c = message[i];
        
        if(c >= 'a' && c <= 'z')
            c += 'A' - 'a';
        //else if(c < 'A' || c > 'Z')
            //continue;
        
        dcyptTxt += (c - key[j] + 26) % 26 + 'A';
        j = (j + 1) % key.length();
      }
    
      return dcyptTxt;
    }  
};

//Function Prototypes
void menu();
string removeSpaces(string);

int main(int argc, char** argv) 
{
    //accepts user input for
    string inKey = " ",   // key
            inEn = " ",   // encryption message
            inDe = " ";   // decryption message

    // holds string that displays for
    string  outEn = " ",  // encrypted message
            outDe = " ";  // decrypted message

    // stores new string without spaces for
    string  newKey = " ", // key
            newEn = " ",  // encrpted message
            newDe = " ";  // decryted message
    
    // variable for menu choice
    char choice = 0;
    
    // accepts user input for the key
    cout << "Enter your Encryption and Decryption Key: ";
    getline(cin, inKey);

    // calls function to clear spaces from the string 
    newKey = removeSpaces(inKey);

    // defines the instance of the Vigenere class and stores key in vig object
    Vigenere vig(newKey);

    // do-while loop for the menu      
    do
    {
        // calls the function that displays menu
        menu();

        // accepts users menu choice 
        cout << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore();
        
        // switch for menu choice, whether it is '1' or '2'
        switch(choice)
        {
            case '1':
            {
                // accepts user input for a string to encrypt
                cout << "\nEnter the message you'd like to encrypt: ";
                getline(cin, inEn);

                // calls function that removes spaces from string
                // and stores in newEn
                newEn = removeSpaces(inEn);
                
                // stores string in vig object that encrypts message and 
                // stores in outEn
                outEn = vig.encrypt(newEn);
                
                // displays encypted message
                cout << "\nEncrypted Message: " << outEn << endl;
                break;
            }
              
            case '2':
            {
                // displays last encypted message
                cout << "\nYour last encrypted message is: " << outEn;

                // accepts user input for a string to decrypt
                cout << "\n\nEnter the message you'd like to decrypt: ";
                getline(cin, inDe);

                // calls function that removes spaces from string and stores 
                // in newDe
                newDe = removeSpaces(inDe);

                // stores string in vig object which decrypts message and
                // stores in outDe
                outDe = vig.decrypt(newDe);

                // displays decrypted message
                cout << "\nDecrypted Message: " << outDe << endl;
                        
                break;
            }            
        }                      
    }while(choice >='1' && choice <='2');
    
    return 0;
}

// function that displays a menu
void menu()
{
    cout << "\nMENU: Vigenere Cipher\n1. Encrypt Message\n2. Decrypt Message\n";
}

// function that removes spaces from any given string 
string removeSpaces(string input)
{
  input.erase(remove(input.begin(), input.end(), ' '), input.end());

  return input;

}
