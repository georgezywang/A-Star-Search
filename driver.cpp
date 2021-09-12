#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <assert.h>

#ifndef NO_INCLUDE_BOOST
    #include <boost/program_options.hpp>
#endif

#include "FPKState.hpp"
#include "SuperQueenState.hpp"
#include "driver.hpp"

using namespace std;

#ifndef NO_INCLUDE_BOOST
    namespace po = boost::program_options;
#endif

vector<vector<int>> Read_FPK_File(const string& fileName){
    ifstream fpkFile(fileName);
    vector<vector<int>> values;
    string line;

    while (getline(fpkFile, line)){
        string lineValue;
        vector<int> lineValues;
        stringstream ss(line);

        while(getline(ss, lineValue, ',')){
            lineValues.push_back(stoi(lineValue));
        }
        values.push_back(lineValues);
    }
    return values;
}

vector<int> Read_Knight_Distances(){
    ifstream kd("knight_distance.txt");
    vector<int> values;
    string line;

    getline(kd, line);
    line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end());
    for (auto i : line){
        values.push_back(atoi(&i));
    }
    // for (auto i : values){
    //     cout << i << endl;
    // }

    return values;
}

void Print_FPK_State(const vector<vector<int>>& values){
    for (auto& line : values){
        for (auto i : line){
            cout << i << " ";
        }
        cout << endl;
    }
}

template <typename C, typename T>
void A_Star_Alg(T* startState, bool gc, string inputFilePath){
    priority_queue<T*, vector<T*>, C> pq;
    pq.push(startState);

    vector<T*> rmd;
    while (!pq.empty()){
        T* currS = pq.top();

        if (currS->reachGoalState()){
            currS->Print_Res(inputFilePath);
            break;
        }

        pq.pop();
        currS->generateSuccessor(pq);

        if (gc){
            delete currS;
        }
        else{
            rmd.push_back(currS);
        }
        
    }

    while (!pq.empty()){
        T* res = pq.top();
        pq.pop();
        delete res;
    }

    if (gc){
        for (T* res : rmd){
            delete res;
        }
    }
}

void Run_FPK(const string& inputFilePath){
    vector<vector<int>> startState = Read_FPK_File(inputFilePath);
    vector<int> knightDistances = Read_Knight_Distances();
    assert(knightDistances.size() == 256);
    
    FPKState* currStart = new FPKState(startState, 0, NULL, &knightDistances);
    A_Star_Alg<FPKComp>(currStart, false, inputFilePath);
}

void Run_SQ(const string& inputFilePath){
    ifstream queenFile(inputFilePath);
    string line;
    getline(queenFile, line);
    int numQueen = stoi(line);
    assert(numQueen >= 0);

    SuperQueenState* currStart = new SuperQueenState(numQueen, 0, {});
    currStart->f = 0;
    A_Star_Alg<SQComp>(currStart, true, inputFilePath);
}

int main(int ac, char* av[]){
    #ifndef NO_INCLUDE_BOOST
        po::options_description desc("Allowed options");
        desc.add_options()
                ("filePath", po::value<string>(), "path for input file")
                ("pSet", po::value<int>(), "problem number")
            ;
        
        po::variables_map vm;
        po::store(po::parse_command_line(ac, av, desc), vm);
        po::notify(vm);

        if(!vm.count("filePath") || !vm.count("pSet")){
            throw invalid_argument("Invalid Argument Received");
        }

        int problem = vm["pSet"].as<int>();
        string inputFilePath = vm["filePath"].as<string>();

    #else
        #pragma message("Disabled Boost Program Option")

        assert(ac == 5);
        if (strcmp(av[1], "--filePath") || strcmp(av[3], "--pSet")){
            throw invalid_argument("Invalid Argument Received");
        }

        string inputFilePath = av[2];
        int problem = atoi(av[4]);
    #endif

    switch (problem){
        case 1:
            Run_FPK(inputFilePath);
            break;
        case 2:
            Run_SQ(inputFilePath);
            break;

        default:
            throw invalid_argument("Invalid Argument Received");
    }
    
    return EXIT_SUCCESS;
}