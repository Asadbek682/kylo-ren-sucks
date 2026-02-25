#include <iostream>
#include <fstream>
#include <string>

class FileHandler {
private:
    std::fstream file;
    std::string filename;
    
public:
    FileHandler(const std::string& fname, std::ios::openmode mode) 
        : filename(fname) {
        file.open(fname, mode);
        if (!file.is_open()) {
            throw std::runtime_error("Failed to open file: " + fname);
        }
        std::cout << "File opened: " << fname << std::endl;
    }
    
    ~FileHandler() {
        if (file.is_open()) {
            file.close();
            std::cout << "File closed: " << filename << std::endl;
        }
    }
    
    void write(const std::string& data) {
        if (file.is_open()) {
            file << data << std::endl;
        }
    }
    
    std::string read() {
        std::string line, content;
        file.clear();
        file.seekg(0);
        while (std::getline(file, line)) {
            content += line + "\n";
        }
        return content;
    }
};

int main() {
    try {
        FileHandler fh("test.txt", std::ios::out | std::ios::in | std::ios::trunc);
        fh.write("Hello, RAII!");
        fh.write("Resource management in C++");
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}
