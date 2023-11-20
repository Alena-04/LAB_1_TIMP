#include "RouteCipher.h"
using namespace std;

bool isValid(const string& inputString)
{
    for(auto character : inputString)
        if (!isalpha(character) || !isupper(character))
            return false;
    return true;
}

int main()
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    int cipherKey;
    string inputText;
    unsigned operation;
    cout<<"Cipher ready. Input key: ";
    cin>>cipherKey;
    cout<<"Key loaded\n";
    RouteCipher textCipher(cipherKey);
    do {
        cout<<"Cipher ready. Input operation (0-exit, 1-encrypt, 2-decrypt): ";
        cin>>operation;
        if (operation > 2) {
            cout<<"Illegal operation\n";
        } else if (operation > 0) {
            cout<<"Cipher ready. Input text: ";
            cin>>inputText;
            if (isValid(inputText)) {
                if (operation == 1) {
                    cout<<"Encrypted text: "<<textCipher.encrypt(inputText)<<endl;
                } else {
                    cout<<"Decrypted text: "<<textCipher.decrypt(inputText)<<endl;
                }
            } else {
                cout<<"Operation aborted: invalid text\n";
            }
        }
    } while (operation != 0);
    return 0;
}
