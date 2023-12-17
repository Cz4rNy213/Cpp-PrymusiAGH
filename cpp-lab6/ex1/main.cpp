#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
// #include "vec2d.h"

using namespace std;



void addTwoFiles(const string& file1, const string& file2){
    ofstream result(file1, std::ios_base::app);
    std::ifstream text2(file2, std::ios_base::in);
    result << text2.rdbuf();
    result.close();
    text2.close();
}

int countLinesInText(const string& file){
    int counter = 0;
    string line;
    std::ifstream text(file, std::ios_base::in);
    while(getline(text, line)){
        counter++;
    }
    return counter;
}

int countCharactersInText(const string& file){
    int counter = 0;
    char ch;
    std::ifstream text(file, std::ios_base::in);
    while(text.get(ch)){
        counter++;
    }
    text.close();
    return counter;
}

void write2TxtFileDemo1(const char* fileName, const string &text)
{
  ofstream out;
  out.open(fileName); //=open(fileName,ios_base::trunc) - truncate the file if it exists
  if (!out) {
    cout << "Cannot open file " << fileName << endl;
  }

  out << text;
  out.close();
}

void write2TxtFileDemo2(const char* fileName, const string &text)
{
  ofstream out(fileName, ios::app); //ios::app - append to end-of-file.
  if (!out) {
    cout << "Cannot open file " << fileName << endl;
  }

  out << text;
  out.close();
}

string fileToString(const char* fileName)
{
  std::ifstream in(fileName);
  if (!in) {
    cout << "Cannot open file " << fileName << endl;
  }

  std::ostringstream buffer;
  buffer << in.rdbuf();
  in.close();

  return buffer.str();
}

void writeToFilesDemo(const char* fName)
{
  cout << "writeToFilesDemo..." << endl;
  write2TxtFileDemo1(fName, string("aaa\nbbb"));
  cout << "(1): " << fName << " now contains: " << endl << fileToString(fName) << endl;
  write2TxtFileDemo1(fName, string("\nccc\nddd"));
  cout << "(2): " << fName << " now contains: " << endl << fileToString(fName) << endl;

  write2TxtFileDemo1(fName, string("aaa\nbbb"));
  cout << "(3): " << fName << " now contains: " << endl << fileToString(fName) << endl;
  write2TxtFileDemo2(fName, string("\nccc\nddd"));
  cout << "(4): " << fName << " now contains: " << endl << fileToString(fName) << endl;
  write2TxtFileDemo2(fName, string("\neee\nfff"));
  cout << "(5): " << fName << " now contains: " << endl << fileToString(fName) << endl;
}

void getCharAndGetLineDemo(const char* fName)
{
  cout << "getCharAndGetLineDemo..." << endl;
  std::ifstream in(fName);
  if (!in) {
    cout << "Cannot open file " << fName << endl;
  }

  char ch;
  cout << "Reading character by character..." << endl;
  while (in.get(ch)) {
    cout << ch;
  }

  // reset "file pointer" to the beginning of the file
  in.clear();
  in.seekg (0, in.beg);
  // start reading again, but this time line by line

  cout << endl << "Now reading line by line..." << endl;
  for (string line; getline(in,line); ) {
    cout << line << endl;
  }

  // the same as above, but using 'while' loop
  string line;
  while (getline(in, line)) {
    cout << line << endl;
  }

  in.close();
}

int main()
{
  const char* fName = "textfile.txt";
  writeToFilesDemo(fName);
  cout << endl;
  getCharAndGetLineDemo(fName);
  return 0;
}