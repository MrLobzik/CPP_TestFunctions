#pragma once

#include "testing.h"

void testing(void (*testing_func)(std::istream& input, std::ostream& output), int testCount) {
    std::ifstream fin;
    std::ofstream fout;
    for (int i = 1; i <= testCount; ++i) {
        std::string path = "tests/input" + std::to_string(i);
        path += ".txt";
        fin.open(path);
        path = "tests/user_output" + std::to_string(i);
        path += ".txt";
        fout.open(path);
        auto begin_t = std::chrono::high_resolution_clock::now();
        testing_func(fin, fout);
        auto end_t = std::chrono::high_resolution_clock::now();
        fin.close();
        fout.close();

        std::vector<std::string> output, user_output;
        path = "tests/output" + std::to_string(i);
        path += ".txt";
        fin.open(path);
        for (int j = 0; !fin.eof(); ++j) {
            std::string buf;
            std::getline(fin, buf);
            output.push_back(buf);
        }
        fin.close();
        path = "tests/user_output" + std::to_string(i);
        path += ".txt";
        fin.open(path);
        for (int j = 0; !fin.eof(); ++j) {
            std::string buf;
            std::getline(fin, buf);
            user_output.push_back(buf);
        }
        fin.close();

        bool test_result = true;
        if (output.size() != user_output.size()) test_result = false;
        for (int j = 0; j < output.size() && test_result; ++j) {
            if (output[j] != user_output[j]) {
                test_result = false;
                break;
            }
        }
        std::cout << "test " << i << ": " << test_result << "\t" << std::chrono::duration_cast<std::chrono::microseconds>(end_t - begin_t).count() / 1000.f << " ms" << std::endl;
    }
}