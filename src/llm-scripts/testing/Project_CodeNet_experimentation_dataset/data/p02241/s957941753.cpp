#include <algorithm>
#include <vector>
#include <iostream>

typedef std::vector<int> TTree;
struct TPath
{
    int Id1;
    int Id2;
    int Cost;
    TPath(int AId1, int AId2, int ACost)
     : Id1(AId1), Id2(AId2), Cost(ACost)
    {}
};
bool Compare(const TPath& Left, const TPath& Right)
{
    if(Left.Cost  < 0) return false;
    if(Right.Cost < 0) return true;
    return Left.Cost < Right.Cost;
}


int main()
{
    int n;
    std::cin >> n;
    std::vector<TTree*> Table(n, NULL);
    for(std::size_t i = 0; i < n; ++i){
        Table[i] = new std::vector<int>(1, i);
    }
    std::vector<TPath> PathList;
    PathList.reserve(n*n);
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            int Cost;
            std::cin >> Cost;
            PathList.push_back(TPath(i, j, Cost));
        }
    }
    std::sort(PathList.begin(), PathList.end(), Compare);
    
    int Total = 0;
    for(std::vector<TPath>::const_iterator It = PathList.begin();
        It != PathList.end(); ++It)
    {
        const TPath& Path = *It;
        TTree* Tree1 = Table[Path.Id1];
        TTree* Tree2 = Table[Path.Id2];
        if(Tree1 == Tree2){
            continue;
        }
        Tree1->insert(Tree1->end(), Tree2->begin(), Tree2->end());
        for(std::size_t j = 0; j < Tree2->size(); ++j){
            int Id = (*Tree2)[j];
            Table[Id] = Tree1;
        }
        delete Tree2;
        Total += Path.Cost;
        // std::cout << "[" << Path.Id1 << "]" << "[" << Path.Id2 << "] = " << Path.Cost << std::endl;
    }
    std::cout << Total << std::endl;
    return 0;
}