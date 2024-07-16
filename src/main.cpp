#include "cli.h"
#include "aes.h"
#include "file_io.h"
#include <iostream>

int main(int argc, char* argv[]) {
    std::string inputFile, outputFile, key;
    bool encrypt = true;

    parseArguments(argc, argv, inputFile, outputFile, key, encrypt);

    if (encrypt) {
        encryptFile(inputFile, outputFile, key);
        std::cout << "File encrypted successfully.\n";
    } else {
        decryptFile(inputFile, outputFile, key);
        std::cout << "File decrypted successfully.\n";
    }

    return 0;
}
