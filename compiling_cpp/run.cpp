#include <iostream>
#include <filesystem>
#include <cstdlib>
#include <string>
#include <cstring>

void run(std::string& program, int argc, char* argv[]) {
    std::string sourceFile = program;

    // If the file doesn't end with ".cpp", append it
    if (sourceFile.size() < 4 or sourceFile.substr(sourceFile.size() - 4) != ".cpp") {
        sourceFile += ".cpp";
    }
    else {
        // Remove the .cpp extension for the binary file name
        program = program.substr(0, program.size() - 4);
    }

    std::string binaryFile = program + ".exe";  // Change the output to .exe for Windows

    // Check if the binary exists and if the source is newer than the binary
    if (!std::filesystem::exists(binaryFile) or std::filesystem::last_write_time(sourceFile) > std::filesystem::last_write_time(binaryFile)) {
        // Construct the compile command
        std::string compileCommand = "clang++ -o " + binaryFile + " -std=c++20 " + sourceFile;

        // Compile the program
        int compileResult = std::system(compileCommand.c_str());
        if (compileResult != 0) {
            // std::cerr << "Compilation failed!" << std::endl;
            return;
        }
    }

    // Run the compiled program with any additional arguments
    std::string runCommand = binaryFile;

    // Append additional arguments if they exist
    for (int i = 2; i < argc; ++i) {
        runCommand += " " + std::string(argv[i]);
    }

    // Execute the program
    // std::cout << "Running command: " << runCommand << std::endl;  // Show the command being run
    int runResult = std::system(runCommand.c_str());

    // if (runResult != 0) {
    // std::cerr << "Execution failed!" << std::endl;
    // }
}

int main(int argc, char* argv[]) {
    if (argc < 2  or
        (argc == 2 and
         (std::strcmp(argv[1], "help")   == 0 or
          std::strcmp(argv[1], "-h")     == 0 or
          std::strcmp(argv[1], "-help")  == 0 or
          std::strcmp(argv[1], "--h")    == 0 or
          std::strcmp(argv[1], "--help") == 0))) {

        std::cerr << "This program has been made to make C++ compiling easier by typing less\n"
                  << "It uses clang++ compiler and C++20 standard\n"
                  << "It supports Command Prompt (cmd) and PowerShell\n\n"
                  << "Usage: " << argv[0] << " <program_name_without_.cpp> [args...]" << std::endl;
        return 1;
    }

    std::string program = argv[1];
    run(program, argc, argv);

    return 0;
}

