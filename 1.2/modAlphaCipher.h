#pragma once
#include <string>
using namespace std;
class Cipher
{
private:
    int p;
public:
    Cipher()=delete;
    Cipher(int w);
    wstring zakodirovatCipher(Cipher w, wstring& s);
    wstring raskodirovatCipher(Cipher w, wstring& s);
};
