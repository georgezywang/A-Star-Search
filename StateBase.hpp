#pragma once

#include <vector>
#include <queue>

using namespace std;

class StateBase{
    public:
        int g;
        int f;

        StateBase(){}
        template <typename C, typename T>
        void generateSuccessor(priority_queue<T*, vector<T*>, C>& pq){}
        virtual bool reachGoalState(){}
        virtual void Print_Res(string& inputFilePath){
            inputFilePath.insert(inputFilePath.find(".txt"), "_output");
        }
        virtual ~StateBase() = default;

    protected:
        virtual void updateHeuristicSum(){}
        
        bool canJumpTo(int x1, int y1, int x2, int y2){
            if (abs(x1 - x2) == 1 && abs(y1 - y2) == 2 || (abs(x1 - x2) == 2 && abs(y1 - y2) == 1)){
                return true;
            }

            return false;
        }
};