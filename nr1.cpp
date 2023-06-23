#include <iostream>
#include <fstream>
#include<string>
#include<vector>
#include<algorithm>
struct Elf{
    std::vector<int> calories;

    unsigned int sum(){
        unsigned int s=0;
        for(auto i:calories){
            s+=i;
        }
        return s;
    }
};
void load_input(std::vector<Elf>& vect,std::string path){
   std::ifstream iif{path};
     Elf currElf;
   while(iif.good()){
    std::string line;
  
    std::getline(iif,line,'\n');
    if(line!=""){
        int converted=std::stoi(line);
        currElf.calories.push_back(converted);
    }
    else{
        vect.push_back(currElf);
        currElf=Elf{};
    }
   }
}
unsigned int get_max_sum(std::vector<Elf> elves){
    unsigned int max=0;
    for(auto e:elves){
        auto s=e.sum();
        if(s>max)max=s;
    }
    return max;
}
int main(int argc,const char** argv){
    if(argc<=1){
        std::cerr<<"No path provided"<<std::endl;
        return -1;
    }
    std::string path=argv[1];
    std::vector<Elf> elves;
    load_input(elves,path);
    std::cout<<get_max_sum(elves)<<std::endl;
    
}