#pragma once

#include <vector>
#include <queue>
#include <unordered_set>
#include <fstream>
#include <string>

#include "StateBase.hpp"

using namespace std;

class SuperQueenState : public StateBase{
    public:
        SuperQueenState(int numQueen, int h, vector<pair<int, int>> currState) : numQueen(numQueen), h(h), currState(currState) {
            this->g = 0;
        }

        template <typename C, typename T>
        void generateSuccessor(priority_queue<T*, vector<T*>, C>& pq){
            int startIdx = 0;

            if (this->currState.size()){
                startIdx = this->currState[this->currState.size() - 1].first + 1;
            }

            if (startIdx == numQueen){
                return;
            }

            unordered_set<int> occupied;
            for (auto& coord : this->currState){
                occupied.insert(coord.second);
            }

            for (int i = 0; i < numQueen; i++){
                if (occupied.find(i) == occupied.end()){
                    this->currState.push_back(pair<int, int>(startIdx, i));
                    SuperQueenState* child = new SuperQueenState(this->numQueen, this->h, this->currState);
                    child->updateHeuristicSum();
                    pq.push(child);
                    this->currState.pop_back();
                }
            }
        }

        bool reachGoalState(){
            if (this->currState.size() == numQueen){
                return true;
            }

            return false;
        }

        void Print_Res(string& inputFilePath){
            StateBase::Print_Res(inputFilePath);
            ofstream output;
            output.open(inputFilePath);
            output << "nAttacks = " << this->h << endl;
            output << endl;

            vector<vector<int>> grid(numQueen, vector<int>(numQueen));
            for (int i = 0; i < numQueen; i++){
                for (int j = 0; j < numQueen; j++){
                    if (this->currState[i].second == j){
                        grid[i][j] = 1;
                    }
                    else{
                        grid[i][j] = 0;
                    }
                }
            }

            for (auto& i : grid){
                for (auto j : i){
                    output << j << " ";
                }
                output << endl;
            }

            output.close();
        }

    protected:
        void updateHeuristicSum(){
            if (currState.size()){
                pair<int, int>& comp = currState[currState.size() - 1];
                for (size_t i = 0; i < currState.size() - 1; i++){
                    if (this->canJumpTo(comp.first, comp.second, currState[i].first, currState[i].second) || abs(comp.first - currState[i].first) == abs(comp.second - currState[i].second)){
                        (this->h)++;
                        continue;
                    }
                }
            }

            this->f = this->h + this->g;
        }
    
    private:
        int numQueen;
        int h;
        vector<pair<int, int>> currState;
};

class SQComp{
    public:
        bool operator() (const SuperQueenState* a, const SuperQueenState* b) const{
            return a->f > b->f;
        }
};