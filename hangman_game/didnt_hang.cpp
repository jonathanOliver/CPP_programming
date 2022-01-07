#include<vector>

extern std::vector<char> wrong_kicks;

bool didnt_hang(){
    return wrong_kicks.size() < 5;
}