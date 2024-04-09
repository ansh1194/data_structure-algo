
#include <unordered_set>
#include <vector>
#include <iostream>

void printDuplicate(std::vector<int> arr){

    std::unordered_set<int> intSet;
    std::unordered_set<int> dup;

    for(auto i= arr.begin(); i!=arr.end(); i++){
        if(intSet.find(*i) == intSet.end()){
            intSet.insert(*i);
        }else{
            dup.insert(*i);
        }

    }

    for (auto i = dup.begin(); i!=dup.end(); i++){
        std::cout << *i<< std::endl;
    }
}


int main(){

    std::vector<int> arr = {1,2,3,4,1,2,3,2,3};

    printDuplicate(arr);
}