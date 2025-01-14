#ifndef FILE_IO_H
#define FILE_IO_H

#include <vector>
#include <string>

std::vector<unsigned char> readFile(const std::string& filename);
void writeFile(const std::string& filename, const std::vector<unsigned char>& data);

#endif // FILE_IO_H
