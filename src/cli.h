#ifndef CLI_H
#define CLI_H

#include <string>

void parseArguments(int argc, char* argv[], std::string& inputFile, std::string& outputFile, std::string& key, bool& encrypt);
void printUsage();

#endif // CLI_H
