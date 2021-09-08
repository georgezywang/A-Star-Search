#include <vector>
#include <queue>

#include "StateBase.hpp"

class SuperQueenState : public StateBase{
    public:
        int g;
        int f;

        SuperQueenState(int numQueen, int g) : numQueen(numQueen), g(g), currQueen(0){}

        template <typename C, typename T>
        void generateSuccessor(priority_queue<T*, vector<T*>, C>& pq){

        }

        bool reachGoalState(){
            if (this->currQueen == this->numQueen){
                return true;
            }

            return false;
        }

        void Print_Res(){}

    protected:
        void updateHeuristicSum(){}
    
    private:
        int numQueen;
        int currQueen;
};

class SQComp{
    public:
        bool operator() (const SuperQueenState* a, const SuperQueenState* b) const{
            return a->f > b->f;
        }
};