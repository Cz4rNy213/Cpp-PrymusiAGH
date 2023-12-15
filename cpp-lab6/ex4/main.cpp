#include <iostream>
#include <sstream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <stdexcept>
#include <string>


class Preprocessor {
    public:
        Preprocessor(): define_token_map(), result(), text_strings(), text_stream(){}

        void readFile(const char*);
        void processTokens();
    private:
        bool handleInclude(std::string&, std::string&);
        bool handleDefine(const std::string&, std::string&, int&);
        int convertStringToInt(std::string& value_string);
        bool validDefName(std::string);
        void writeResultToFile(const std::ostringstream& text);

        std::unordered_map<std::string, int> define_token_map;
        std::ostringstream result;
        std::string text_strings;
        std::ostringstream text_stream;
};

void Preprocessor::readFile(const char* file_name){
    std::ifstream file(file_name);
    if (!file){
        throw std::runtime_error("Can not open file in readFile function");
    }
    text_stream << file.rdbuf();
    text_strings = text_stream.str();
}

void Preprocessor::processTokens(){
    std::istringstream text(text_strings);

    std::string line;
    while (getline(text, line)){
            std::istringstream line_stream(line);
            std::string token;
        while(line_stream >> token){
            if (token == "#inkluduj"){
            std::string header_file;
            line_stream >> header_file;
            if(!handleInclude(token, header_file)){
                std::cerr << "Error in handling #inkluduj. Exiting...\n";
                std::exit(EXIT_FAILURE);
            }
            result << token + ' ';
            result << header_file + ' ';
        }
        else if (token == "#definiuj"){
            std::string def_name;
            std::string value_string;
            int value;
            line_stream >> def_name;
            line_stream >> value_string;
            if(!handleDefine(def_name, value_string, value)){
                std::cerr << "Error in handling #definiuj. Exiting...\n";
                std::exit(EXIT_FAILURE);
            }
            define_token_map[def_name] = value;
        }
        else{
            auto it = define_token_map.find(token);
            if (it != define_token_map.end()){
                result << it->second << ' ';
            }
            else{
                result << token + ' ';
            }
        }
        } 
        result << "\n";
    }
    writeResultToFile(result);
}

bool Preprocessor::handleInclude(std::string& token, std::string& header_file){
    if (header_file[0] != '<' && header_file[header_file.size()] - 1 != '>'){
        throw std::runtime_error("Incorrect header file: " + header_file);
        return false;
    }
    else if (header_file.size() <= 2){
        throw std::runtime_error("Incorrect header file: " + header_file);
        return false;
    }
    token = "#include";
    return true;
}

bool Preprocessor::handleDefine(const std::string& def_name, std::string& value_string, int& value){
    if (!validDefName(def_name)){
        throw std::runtime_error("Incorrect #definiuj name: " + def_name);
        return false;
    }
    value = convertStringToInt(value_{...}string);
    return true;
}


int Preprocessor::convertStringToInt(std::string& value_string){
    try {
        return std::stoi(value_string);
    }
    catch (const std::invalid_argument&){
        throw std::invalid_argument("Error: invalid argument. #definiuj value is not int!" + value_string);
        std::exit(EXIT_FAILURE);
    }
    catch (const std::out_of_range&){
        throw std::out_of_range("Error: out of range. #definiuj value is out of range of int");
        std::exit(EXIT_FAILURE);
    }
}

bool Preprocessor::validDefName(std::string def_name){
    for (int i = 0; i < def_name.size(); i++){
        if (!((def_name[i] >= 'A' && def_name[i] <= 'Z') || def_name[i] == '_')){
            return false;
        }
    }
    return true;
}

void Preprocessor::writeResultToFile(const std::ostringstream& result){
    std::ofstream outfile("result.cpp");
    outfile << result.str();
}

int main(){
    Preprocessor preprocessor;
    preprocessor.readFile("input.cpp");
    preprocessor.processTokens();
    return 0;
}