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
bool comp(Elf e1,Elf e2){
    return e2.sum()<e1.sum();
}
int main(int argc,const char** argv){
    if(argc<=1){
        std::cerr<<"No path provided"<<std::endl;
        return -1;
    }
    bool task2=argc>=3;
    std::string path=argv[1];
    std::vector<Elf> elves;
    load_input(elves,path);
    std::sort(elves.begin(),elves.end(),comp);

    int n=task2?3:1;
    int s=0;
    for(int i=0;i<n;i++){
        s+=elves[i].sum();
    }
    std::cout<<s<<std::endl;
    
}