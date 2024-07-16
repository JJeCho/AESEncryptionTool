# AESEncryptionTool

## Overview
AESEncryptionTool is a command-line tool designed for encrypting and decrypting files using the Advanced Encryption Standard (AES) algorithm. The tool is written in C++ and follows secure coding practices to ensure data confidentiality and integrity. The modular architecture allows for easy integration into existing systems.

## Features
- **AES Encryption**: Encrypt files using the AES-128 algorithm.
- **AES Decryption**: Decrypt previously encrypted files.
- **Key Management**: Secure key input via command-line arguments.
- **Command-line Interface**: Simple and intuitive command-line usage.

## Requirements
- **C++ Compiler**: Compatible with C++17.
- **CMake**: Version 3.10 or higher.
- **OpenSSL**: For AES encryption and decryption functions.
- **Visual Studio Code**: Recommended for development.

## Installation

### OpenSSL Installation on Windows
1. **Download OpenSSL Binaries**: 
   - Go to the [OpenSSL Binaries page](https://slproweb.com/products/Win32OpenSSL.html).
   - Download the "Win64 OpenSSL" or "Win32 OpenSSL" installer based on your system architecture.

2. **Install OpenSSL**:
   - Run the installer and follow the instructions.
   - During installation, select the option to add OpenSSL to the system PATH.

### Project Setup
1. **Clone the Repository**:
   ```
   git clone https://github.com/your-username/AESEncryptionTool.git
   cd AESEncryptionTool
   ```

2. **Install CMake:**:
   - Download and install CMake from CMake's official website.
   - Ensure CMake is added to your system PATH.

3. **Configure and Build the Project:**:
   ```
   cmake -B build
   cmake --build build
   ```

## Usage
Run the AESEncryptionTool executable with the following options:
### Encrypt a File
```
./AESEncryptionTool -e -i input.txt -o encrypted.bin -k mysecretkey
```
### Decrypt a File
```
./AESEncryptionTool -d -i encrypted.bin -o output.txt -k mysecretkey
```
### Command-line Arguments
   - -e: Encrypt the input file.
   - -d: Decrypt the input file.
   - -i <inputfile>: Specify the input file path.
   - -o <outputfile>: Specify the output file path.
   - -k <key>: Specify the encryption/decryption key.

## License
This project is licensed under the MIT License. See the LICENSE file for details.

## Acknowledgements
   - OpenSSL for the cryptographic functions.
   - CMake for the build system.
   - Visual Studio Code for the development environment.