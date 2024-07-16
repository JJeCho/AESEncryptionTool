#ifndef AES_H
#define AES_H

#include <string>

void encryptFile(const std::string& inputFile, const std::string& outputFile, const std::string& key);
void decryptFile(const std::string& inputFile, const std::string& outputFile, const std::string& key);

#endif // AES_H
