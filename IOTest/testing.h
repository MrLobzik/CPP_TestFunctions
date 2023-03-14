#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>

void testing(void (*testing_func)(std::istream& input, std::ostream& output), int testCount);