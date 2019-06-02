#include <fstream>
#include <iostream>
#include <string>

void encrypt(std::ifstream &file, int key, std::string &filename) {
    std::ofstream eFile;
    std::string suffix = ".ef";
    std::string encrypted;
    std::string plain;
    char character;
    while (file.get(character)) {
        plain += character;
    }
    for (int i = 0; i < int(plain.length()); i++) {
        encrypted += char(int(plain[i]) xor key);
    }
    filename += suffix;
    eFile.open(filename);
    eFile.write(encrypted.c_str(), encrypted.length());
    eFile.close();
}


int main(int argc, char *argv[]) {
      if ( argc != 3 )
          std::cout<<"usage: "<< argv[0] <<" <filename> <key>\nnote: the longer the key, the more secure the encryption" << std::endl;
      else {
          std::string filename = std::string(argv[1]);
          int key = atoi(argv[2]);
          std::ifstream fileObj (argv[1]);
          encrypt(fileObj, key, filename);
      }
}
