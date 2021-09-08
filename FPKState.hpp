#include <vector>
#include <queue>

#include "StateBase.hpp"

using namespace std;

class FPKState : public StateBase{
    public:
        FPKState* parent;
        FPKState(vector<vector<int>> currState, int g, FPKState* parent, vector<int>* knightDistances) : currState(currState), parent(parent), knightDistances(knightDistances){
            this->g = g;
            this->updateHeuristicSum();
        };

        template <typename C, typename T>
        void generateSuccessor(priority_queue<T*, vector<T*>, C>& pq) {
            int zeroi;
            int zeroj;

            for (int i = 0; i < this->currState.size(); i++){
                for (int j = 0; j < this->currState[0].size(); j++){
                    if (!this->currState[i][j]){
                        zeroi = i;
                        zeroj = j;
                    }
                }
            }
            
            for (int i = 0; i < this->currState.size(); i++){
                for (int j = 0; j < this->currState[0].size(); j++){
                    if (canJumpTo(zeroi, zeroj, i, j)){
                        swap(this->currState[zeroi][zeroj], this->currState[i][j]);
                        FPKState* child = new FPKState(this->currState, this->g + 1, this, this->knightDistances);
                        pq.push(child);
                        swap(this->currState[zeroi][zeroj], this->currState[i][j]);
                    }
                }
            }
        }

        bool reachGoalState() override {
            for (int i = 0; i < this->currState.size(); i++){
                for (int j = 0; j < this->currState[0].size(); j++){
                    if (currState[i][j] != 0 && (4 * i + j) != (currState[i][j] - 1)){
                        return false;
                    }
                }
            }
            return true;
        }

        void Print_Res() override {
            if (this->parent){
                this->parent->Print_Res();
            }

            for (auto& i : this->currState){
                for (auto j : i){
                    cout << j << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
    
    protected:
        void updateHeuristicSum() override {
            int h = calcH();
            this->f = this->g + h;
        }

    private:
        vector<vector<int>> currState;
        vector<int>* knightDistances;

        int calcH(){
            int distSum = 0;
            for (int i = 0; i < this->currState.size(); i++){
                for (int j = 0; j < this->currState[0].size(); j++){
                    int currLoc = 4 * i + j;
                    int currNum = this->currState[i][j] - 1;

                    if (currNum == -1){
                        continue;
                    }

                    distSum += (*(this->knightDistances))[16 * currLoc + currNum];
                }
            }

            return distSum;
        }

        bool canJumpTo(int x1, int y1, int x2, int y2){
            if (abs(x1 - x2) == 1 && abs(y1 - y2) == 2 || (abs(x1 - x2) == 2 && abs(y1 - y2) == 1)){
                return true;
            }

            return false;
        }
};

class FPKComp{
    public:
        bool operator() (const FPKState* a, const FPKState* b) const{
            return a->f > b->f;
        }
};