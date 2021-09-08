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
        virtual void Print_Res(){}

    protected:
        virtual void updateHeuristicSum(){}
};