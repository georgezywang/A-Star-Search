#pragma once

#include <vector>
#include <string>

std::vector<std::vector<int>> Read_FPK_File(const std::string& fileName);
std::vector<int> Read_Knight_Distances();
void Print_FPK_State(const std::vector<std::vector<int>>& values);

template <typename C, typename T>
void A_Star_Alg(T* startState, bool gc, std::string inputFilePath);
void Run_FPK(const std::string& inputFilePath);
void Run_SQ(const std::string& inputFilePath);