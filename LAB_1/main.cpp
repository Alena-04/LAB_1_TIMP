#include <iostream>
#include "modAlphaCipher.h"

int main()
{
    try {
        std::wstring open_text;
        std::locale loc("ru_RU.UTF-8");
        std::locale::global(loc);
        std::wcin.imbue(loc);
        std::wcout.imbue(loc);
        std::wcout << L"Шифрование текста\n";
        std::wcout << L"Введите текст: ";
        std::getline(std::wcin, open_text);
        std::wstring key;
        std::wcout << L"Введите ключ: ";
        std::getline(std::wcin, key);
        modAlphaCipher cipher(key);
        std::wstring cipher_text = cipher.encrypt(open_text);
        std::wcout<< L"Зашифрованный текст: "<<cipher_text<< std::endl;
        std::wstring decrypted_text = cipher.decrypt(cipher_text);
        std::wcout << L"Расшифрованный текст: " << decrypted_text << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
