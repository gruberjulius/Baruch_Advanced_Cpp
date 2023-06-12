#include <iostream>
#include <cstdio>

// PART a 
// function object file finalizer
struct File_Finalizer {
    void operator()(FILE* file) {
        std::cout << "closing with File Finalizer" << std::endl;
        fclose(file);
    }
};

// PART b 
// free function file finalizer
void free_Func_File_Finalizer(FILE* file) {
    std::cout << "closing with free File Finalizer" << std::endl;
    fclose(file);
}

// stored lambda function file finalizer
auto lambda_File_Finalizer = [](FILE* file) {
    std::cout << "closing with lambda File Finalizer" << std::endl;
    fclose(file);
};

int main() {
    FILE* file;
    // opening the file in write mode
    file = fopen("file.txt", "w");
    //opening different 
    std::shared_ptr<FILE> mySharedFile1(file, File_Finalizer());
    std::shared_ptr<FILE> mySharedFile2(file, free_Func_File_Finalizer);
    std::shared_ptr<FILE> mySharedFile3(file, lambda_File_Finalizer);
    // PART D)
    try {
        FILE* file;
        file = fopen("file.txt", "w");
        if (file != nullptr) {
            for (int i = 0; i < 10; i++) {
                fprintf(file, "print Number: %d\n", i);
                if (i == 3) {
                    throw 1;
                }
            }
        }
    }
    catch (int e) {
        FILE* file_copy;
        file_copy = fopen("file.txt", "w");
        if (file_copy != nullptr) {
            fclose(file_copy);
        }
    }
    return 0;
}

