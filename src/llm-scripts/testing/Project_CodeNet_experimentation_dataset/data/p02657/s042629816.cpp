#include <iostream>
#include <string>

namespace ABC169
{

  class A
  {
  public:
    A() = default;
    ~A() = default;


    void Run()
    {

      int A = 0;
      int B = 0;
      std::cin >> A;
      std::cin >> B;

      std::cout << A*B << std::endl;
    }
  };

}
int main()
{

  ABC169::A prob;
  prob.Run();

  return 0;
}
