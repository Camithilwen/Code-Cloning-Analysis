#include <iostream>
#include <algorithm>
#include <vector>
typedef int TInt;
typedef std::vector<TInt> TList;

TList Input()
{
    int Count;
    std::cin >> Count;
    TList List(Count);
    for(int i = 0; i < Count; ++i){
        std::cin >> List[i];
    }
    return List;
}
int insertionSort(TList& A, int g)
{
    int cnt = 0;
    for(int i = g; i < A.size(); ++i){
        TInt v = A[i];
        int j = i - g;
        while(j >= 0 && A[j] > v){
            A[j+g] = A[j];
            j = j - g;
            cnt++;
        }
        A[j+g] = v;
    }
    return cnt;
}
void Reverse(TList& List)
{
    TList R;
    for(TList::reverse_iterator It = List.rbegin();
        It != List.rend();
        ++It)
    {
        R.push_back(*It);
    }
    std::swap(R, List);
}
TList GetG(int Max)
{
    TList G;
    int h = 1;
    while(h <= Max){
        G.push_back(h);
        h = 3 * h + 1;
    }
    // Reverse(G);
    std::reverse(G.begin(), G.end());
    return G;
}
int shellSort(TList& A, const TList& G)
{
    int cnt = 0;
    for(TList::const_iterator It = G.begin();
        It != G.end();
        ++It){
        cnt += insertionSort(A, *It);
    }
    return cnt;
}
void OutputLine(const TList& List)
{
    TList::const_iterator It = List.begin();
    std::cout << *(It++);
    for(; It != List.end(); ++It){
        std::cout << " " << *It;
    }
    std::cout << std::endl;
}
void Output(const TList& List)
{
    TList::const_iterator It = List.begin();
    // std::cout << *(It++);
    for(; It != List.end(); ++It){
        std::cout << *It << std::endl;
    }
}
int main()
{
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    TList A = Input();
    TList G = GetG(A.size());
    int cnt = shellSort(A, G);
    std::cout << G.size() << std::endl;
    OutputLine(G);
    std::cout << cnt << std::endl;
    Output(A);
    return 0;   
}