#include "Day3.h"
#include "../Helpers/Helpers.h"

namespace Day3 {
    std::vector<std::string> input = Helpers::ReadAllLines<std::string>("./Day3Input.txt");

    std::vector<std::vector<bool>> ParseInput(std::vector<std::string> input) {
        std::vector<std::vector<bool>> trees = {};
        for (auto& row : input) {
            trees.push_back({});
            for (auto& cell : row) {
                trees[trees.size() - 1].push_back(cell == '#');
            }
        }
        return trees;
    }

    long long A(std::vector<std::string> input, int xSlope, int ySlope) {
        auto trees = ParseInput(input);
        int x = 0;
        int y = 0;
        int treeCount = 0;
        while (y < trees.size()) {
            if (trees[y][x]) {
                treeCount++;
            }
            y += ySlope;
            x = (x + xSlope) % trees[0].size();
        }
        return treeCount;
    }

    long long B(std::vector<std::string> input) {
        return A(input, 1, 1)
            * A(input, 3, 1)
            * A(input, 5, 1)
            * A(input, 7, 1)
            * A(input, 1, 2);
    }
}