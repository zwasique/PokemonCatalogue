#include <iostream>
#include <vector>

//void menu();

int main (int argc, char** argv) {
    if (argc <1){
        std::cerr << "Supply at least one Pokemon*.txt file";
    }


    std::vector<std::string> files;
    files.reserve(argc);
    for (int i = 0; i < argc; i++){
        files.emplace_back(argv[i]);}


}
