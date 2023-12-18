#include "RouteCipher.h"
#include <iostream>
#include <vector>
#include <string>

RouteCipher::RouteCipher(int key) {
    key_ = key;  
}

std::string RouteCipher::encrypt(const std::string& plaintext) {
    int length = plaintext.length();
    int key = key_;  // Сохраняем значение ключа
    int numRows = key;  // Используем сохраненное значение ключа
    int numCols = (length + numRows - 1) / numRows;
    std::vector<std::string> matrix(numRows, std::string(numCols, ' '));

    std::string encryptedText;
    int charIndex = 0;

    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            if (charIndex < length) {
                matrix[row][col] = plaintext[charIndex];
                charIndex++;
            } else {
                matrix[row][col] = '.';
            }
        }
    }

    for (int col = 0; col < numCols; col++) {
        for (int row = 0; row < numRows; row++) {
            if (matrix[row][col] != '.') {
                encryptedText += matrix[row][col];
            }
        }
    }

    return encryptedText;
}

std::string RouteCipher::decrypt(const std::string& ciphertext) {
    int length = ciphertext.length();
    int key = key_;  // Сохраняем значение ключа
    int numRows = key;  // Используем сохраненное значение ключа
    int numCols = (length + numRows - 1) / numRows;
    std::vector<std::string> matrix(numRows, std::string(numCols, ' '));

    std::string decryptedText;
    int charIndex = 0;

    for (int col = 0; col < numCols; col++) {
        for (int row = 0; row < numRows; row++) {
            matrix[row][col] = ciphertext[charIndex];
            charIndex++;
        }
    }

    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            if (matrix[row][col] != '.') {
                decryptedText += matrix[row][col];
            }
        }
    }

    return decryptedText;
}
