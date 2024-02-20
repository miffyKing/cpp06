#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

int main()
{

  Base *base = generate();

  identify(base);
  identify(*base);

  delete base;

  return 0;
}

Base *generate(void)
{
  int randVal = std::time(0) % 3;
  if (randVal == 0)
  {
    return new A();
  }
  else if (randVal == 1)
  {
    return new B();
  }
  else if (randVal == 2)
  {
    return new C();
  }
  else
    return new Base();
}

void identify(Base *p)
{
  if (dynamic_cast<A *>(p))
  {
    std::cout << "A"
              << "\n";
  }
  else if (dynamic_cast<B *>(p))
  {
    std::cout << "B"
              << "\n";
  }
  else if (dynamic_cast<C *>(p))
  {
    std::cout << "C"
              << "\n";
  }
  else
  {
    std::cout << "Unknown Type"
              << "\n";
  }
}

void identify(Base &p)
{
  try
  {
    A &a = dynamic_cast<A &>(p);
    std::cout << "A" << std::endl;
    (void)a;
  }
  catch (const std::bad_cast &badCast)
  {
    std::cerr << "Caught std:: A   bad_cast: " << badCast.what() << std::endl;
  }
  catch (const std::exception &otherException)
  {
    std::cerr << "Caught std::exception: " << otherException.what() << std::endl;
  }

  try
  {
    B &b = dynamic_cast<B &>(p);
    std::cout << "B" << std::endl;
    (void)b;
  }
  catch (const std::bad_cast &badCast)
  {
    std::cerr << "Caught std:: B   bad_cast: " << badCast.what() << std::endl;
  }
  catch (const std::exception &otherException)
  {
    std::cerr << "Caught std::exception: " << otherException.what() << std::endl;
  }

  try
  {
    C &c = dynamic_cast<C &>(p);
    std::cout << "C" << std::endl;
    (void)c;
  }
  catch (const std::bad_cast &badCast)
  {
    std::cerr << "Caught std::C   bad_cast: " << badCast.what() << std::endl;
  }
  catch (const std::exception &otherException)
  {
    std::cerr << "Caught std::exception: " << otherException.what() << std::endl;
  }
}

// 레퍼런스 에서는 트라이 캐치 반드시 쓰세요.
//