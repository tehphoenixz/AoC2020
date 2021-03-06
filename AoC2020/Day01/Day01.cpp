#include "Day01.h"
#include "../Helpers/Helpers.h"

namespace Day01 {
    std::vector<int> input = Helpers::ReadAllLines<int>("./Day01Input.txt");

    int A(std::vector<int> input) {
        for (auto& a : input) {
            for (auto& b : input) {
                if (a + b == 2020) {
                    return a * b;
                }
            }
        }
        return -1;
    }

    int B(std::vector<int> input) {
        for (auto& a : input) {
            for (auto& b : input) {
                for (auto& c : input) {
                    if (a + b + c == 2020) {
                        return a * b * c;
                    }
                }
            }
        }
        return -1;
    }
}