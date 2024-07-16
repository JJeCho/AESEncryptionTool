#include "aes.h"
#include "file_io.h"
#include <openssl/aes.h>
#include <vector>
#include <iostream>
#include <cstring>

void encryptFile(const std::string& inputFile, const std::string& outputFile, const std::string& key) {
    // Read the input file
    std::vector<unsigned char> buffer = readFile(inputFile);

    // Prepare AES key and IV
    unsigned char aesKey[AES_BLOCK_SIZE];
    unsigned char iv[AES_BLOCK_SIZE];
    memset(aesKey, 0, AES_BLOCK_SIZE);
    memset(iv, 0, AES_BLOCK_SIZE);
    memcpy(aesKey, key.c_str(), std::min(key.size(), sizeof(aesKey)));

    // Encrypt data
    AES_KEY encryptKey;
    AES_set_encrypt_key(aesKey, 128, &encryptKey);

    // Padding for AES block size
    size_t bufferSize = buffer.size();
    size_t paddingLength = AES_BLOCK_SIZE - (bufferSize % AES_BLOCK_SIZE);
    buffer.resize(bufferSize + paddingLength, paddingLength);

    std::vector<unsigned char> encrypted(buffer.size());

    AES_cbc_encrypt(buffer.data(), encrypted.data(), buffer.size(), &encryptKey, iv, AES_ENCRYPT);

    // Write the encrypted data to output file
    writeFile(outputFile, encrypted);
}

void decryptFile(const std::string& inputFile, const std::string& outputFile, const std::string& key) {
    // Read the encrypted file
    std::vector<unsigned char> buffer = readFile(inputFile);

    // Prepare AES key and IV
    unsigned char aesKey[AES_BLOCK_SIZE];
    unsigned char iv[AES_BLOCK_SIZE];
    memset(aesKey, 0, AES_BLOCK_SIZE);
    memset(iv, 0, AES_BLOCK_SIZE);
    memcpy(aesKey, key.c_str(), std::min(key.size(), sizeof(aesKey)));

    // Decrypt data
    AES_KEY decryptKey;
    AES_set_decrypt_key(aesKey, 128, &decryptKey);

    std::vector<unsigned char> decrypted(buffer.size());

    AES_cbc_encrypt(buffer.data(), decrypted.data(), buffer.size(), &decryptKey, iv, AES_DECRYPT);

    // Remove padding
    size_t paddingLength = decrypted.back();
    decrypted.resize(decrypted.size() - paddingLength);

    // Write the decrypted data to output file
    writeFile(outputFile, decrypted);
}
