#pragma once
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <cctype>
#include <locale>
#include <codecvt>

class RouteCipher
{
private:
    int key_;  // Используем соглашение об именовании для приватного члена данных
public:
    RouteCipher(int key);  // Добавляем идентификатор параметра для явности
    std::string encrypt(const std::string& plaintext);  // Вводим более осмысленное имя для входного текста
    std::string decrypt(const std::string& ciphertext);  // Вводим более осмысленное имя для зашифрованного текста
};
