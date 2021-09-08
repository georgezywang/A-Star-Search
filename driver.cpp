#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <assert.h>

#include <boost/program_options.hpp>

#include "FPKState.hpp"
#include "SuperQueenState.hpp"

using namespace std;
namespace po = boost::program_options;

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
void A_Star_Alg(T* startState, bool gc){
    priority_queue<T*, vector<T*>, C> pq;
    pq.push(startState);

    vector<T*> rmd;
    while (!pq.empty()){
        T* currS = pq.top();

        if (currS->reachGoalState()){
            currS->Print_Res();
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

int main(int ac, char* av[]){
    po::options_description desc("Allowed options");
    desc.add_options()
            ("filePath", po::value<string>(), "path for input file")
            ("numQueen", po::value<int>(), "number of queens")
        ;
    
    po::variables_map vm;
    po::store(po::parse_command_line(ac, av, desc), vm);
    po::notify(vm);

    if(vm.count("filePath")){
        string inputFilePath = vm["filePath"].as<string>();
        vector<vector<int>> startState = Read_FPK_File(inputFilePath);
        vector<int> knightDistances = Read_Knight_Distances();
        assert(knightDistances.size() == 256);
        
        FPKState* currStart = new FPKState(startState, 0, NULL, &knightDistances);
        A_Star_Alg<FPKComp>(currStart, false);
        return EXIT_SUCCESS;
    }
    
    if (vm.count("numQueen")){
        int numQueen = vm["numQueen"].as<int>();
        SuperQueenState* currStart = new SuperQueenState(numQueen, 0, {});
        currStart->f = 0;
        A_Star_Alg<SQComp>(currStart, true);
    }
    
    return EXIT_SUCCESS;
}