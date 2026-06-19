#include <iostream>
#include <string>

#include "Cipher.h"
#include "GammaCipher.h"
#include "FileManager.h"

using namespace std;

void showMenu() {
    cout << "=== FileCryptoLab ===" << endl;
    cout << "1. Encrypt file" << endl;
    cout << "2. Decrypt file" << endl;
    cout << "0. Exit" << endl;
    cout << "Choose action: ";
}

int main() {
    int mode;
    string inputFile;
    string outputFile;
    string key;

    showMenu();
    cin >> mode;

    if (mode == 0) {
        cout << "Program finished" << endl;
        return 0;
    }

    if (mode != 1 && mode != 2) {
        cout << "Wrong choice" << endl;
        return 0;
    }

    cout << "Input file name: ";
    cin >> inputFile;

    cout << "Output file name: ";
    cin >> outputFile;

    cout << "Key: ";
    cin >> key;

    if (key.empty()) {
        cout << "Key cannot be empty" << endl;
        return 0;
    }

    string text = FileManager::readFile(inputFile);

    if (text.empty()) {
        cout << "File is empty or not found" << endl;
        return 0;
    }

    GammaCipher cipher(key);

    string result;

    if (mode == 1) {
        result = cipher.encrypt(text);
        cout << "File encrypted" << endl;
    } else {
        result = cipher.decrypt(text);
        cout << "File decrypted" << endl;
    }

    FileManager::writeFile(outputFile, result);

    cout << "Result saved to: " << outputFile << endl;

    return 0;
}