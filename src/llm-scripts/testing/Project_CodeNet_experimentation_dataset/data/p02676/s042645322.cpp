
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>

namespace ABC168
{

  class B
  {
  public:
    B() = default;
    ~B() = default;


    void Run()
    {

      std::string S;
      int K= 0;
      std::cin >> K;
      std::cin >> S;

      std::string answer = S;
      if (S.length() > K)
      {
        answer = S.substr(0, K);
        answer.append("...");
      }
        

      std::cout << answer << std::endl;
    }
  };

}
int main()
{

  ABC168::B prob;
  prob.Run();

  return 0;
}


