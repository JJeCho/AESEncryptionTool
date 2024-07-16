#include "cli.h"
#include <iostream>
#include <string>

void parseArguments(int argc, char* argv[], std::string& inputFile, std::string& outputFile, std::string& key, bool& encrypt) {
    if (argc != 8) {
        printUsage();
        exit(EXIT_FAILURE);
    }

    // Handle encryption/decryption flag separately
    std::string arg1 = argv[1];
    if (arg1 == "-e") {
        encrypt = true;
    } else if (arg1 == "-d") {
        encrypt = false;
    } else {
        printUsage();
        exit(EXIT_FAILURE);
    }

    // Parse the remaining arguments
    for (int i = 2; i < argc; i += 2) {
        std::string arg = argv[i];
        std::cout << "Arg: " << arg << ", Value: " << argv[i + 1] << std::endl;  // Debug output
        if (arg == "-i") {
            inputFile = argv[i + 1];
        } else if (arg == "-o") {
            outputFile = argv[i + 1];
        } else if (arg == "-k") {
            key = argv[i + 1];
        } else {
            printUsage();
            exit(EXIT_FAILURE);
        }
    }

    // Debug output to verify the parsed values
    std::cout << "Parsed arguments:" << std::endl;
    std::cout << "Input File: " << inputFile << std::endl;
    std::cout << "Output File: " << outputFile << std::endl;
    std::cout << "Key: " << key << std::endl;
    std::cout << "Encrypt: " << (encrypt ? "True" : "False") << std::endl;
}

void printUsage() {
    std::cout << "Usage: aes_tool.exe -e|-d -i <inputfile> -o <outputfile> -k <key>\n";
}
