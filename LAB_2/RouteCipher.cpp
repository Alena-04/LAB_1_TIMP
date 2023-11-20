#include "RouteCipher.h"
#include <vector>
#include <string>

RouteCipher::RouteCipher(int key) {
    key_ = key;  
}

std::string RouteCipher::encrypt(const std::string& plaintext) {
    int numRows = key_, numCols = plaintext.length();
    std::vector<std::vector<char>> matrix(numRows, std::vector<char>(numCols, ' '));

    int direction = 0;
    int rowIndex = 0, colIndex = 0;

    for (int i = 0; i < numCols; i++) {
        if (rowIndex == 0 || rowIndex == numRows - 1)
            direction = 1 - direction;
        matrix[rowIndex][colIndex++] = plaintext[i];
        if (direction)
            rowIndex++;
        else
            rowIndex--;
    }

    std::string ciphertext;
    for (int i = 0; i < numRows; i++)
        for (int j = 0; j < numCols; j++)
            if (matrix[i][j] != ' ')
                ciphertext += matrix[i][j];

    return ciphertext;
}

std::string RouteCipher::decrypt(const std::string& ciphertext) {
    int numRows = key_, numCols = ciphertext.length();
    std::vector<std::vector<char>> matrix(numRows, std::vector<char>(numCols, ' '));

    int direction = 0;  // Инициализация переменной direction
    int rowIndex = 0, colIndex = 0;

    for (int i = 0; i < numCols; i++) {
        if (rowIndex == 0)
            direction = 1;
        if (rowIndex == numRows - 1)
            direction = 0;
        matrix[rowIndex][colIndex++] = '*';
        if (direction)
            rowIndex++;
        else
            rowIndex--;
    }

    int index = 0;
    for (int i = 0; i < numRows; i++)
        for (int j = 0; j < numCols; j++)
            if (matrix[i][j] == '*' && index < numCols)
                matrix[i][j] = ciphertext[index++];

    std::string plaintext;
    rowIndex = 0, colIndex = 0;
    for (int i = 0; i < numCols; i++) {
        if (rowIndex == 0)
            direction = 1;
        if (rowIndex == numRows - 1)
            direction = 0;
        if (matrix[rowIndex][colIndex] != '*')
            plaintext.push_back(matrix[rowIndex][colIndex++]);  // Использование push_back() для добавления символов
        if (direction)
            rowIndex++;
        else
            rowIndex--;
    }

    return plaintext;
}
