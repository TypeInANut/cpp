#include <iostream>
#include <fstream>
#include <string>

void encryptFile(const std::string &inputFilePath, const std::string &outputFilePath, int key)
{
  std::ifstream inputFile(inputFilePath, std::ios::binary);
  std::ofstream outputFile(outputFilePath, std::ios::binary);

  char ch;
  while (inputFile.get(ch))
  {
      outputFile.put(ch + key);
  }

  inputFile.close();
  outputFile.close();
}

void decryptFile(const std::string &inputFilePath, const std::string &outputFilePath, int key)
{
  std::ifstream inputFile(inputFilePath, std::ios::binary);
  std::ofstream outputFile(outputFilePath, std::ios::binary);

  char ch;
  while (inputFile.get(ch))
  {
      outputFile.put(ch - key);
  }

  inputFile.close();
  outputFile.close();
}

int main()
{
  std::string inputFilePath, outputFilePath;
  int choice, key;

  std::cout << "1. Encrypt File\n";
  std::cout << "2. Decrypt File\n";
  std::cout << "Enter your choice: ";
  std::cin >> choice;

  std::cout << "Enter key (integer): ";
  std::cin >> key;

  std::cout << "Enter input file path: ";
  std::cin >> inputFilePath;
  std::cout << "Enter output file path: ";
  std::cin >> outputFilePath;

  if (choice == 1)
  {
      encryptFile(inputFilePath, outputFilePath, key);
  }
  else if (choice == 2)
  {
      decryptFile(inputFilePath, outputFilePath, key);
  }
  else
  {
      std::cout << "Invalid choice." << std::endl;
  }

  return 0;
}