#include<iostream>
#include<algorithm>

namespace MyMath {

  int Reminder(int &x, int &y)
  {
    if (x == 0 || y == 0) {
      throw("Invalid numbers!");
    }
    if ( x > y ) {
      std::swap(x,y);
    }
    return y%x;
  }

  int Gcd(int n, int m)
  {
    int msign(1);
    int nsign(1);

    if (n == 0 && m == 0) {
      return 0;
    }

    if (m < 0) {
      msign = -1;
    }

    if (n < 0) {
      nsign = -1;
    }

    while(true) {
      if (n == 0) {
        return m * msign;
      }
      if (m == 0) {
        return n * nsign;
      }
      auto rem = Reminder(n, m);
      m = std::abs(n);
      n = std::abs(rem);
    }
  }
}

void Help()
{
  std::cout << "USAGE: ./math <num1> <num2>\n";
}

int main(int argc, char** argv)
{
  if (argc != 3) {
    Help();
    return -1;
  }
  int val1 = std::stoi(argv[1]);
  int val2 = std::stoi(argv[2]);
  std::cout << "GCD = " << MyMath::Gcd(val1, val2) << "\n";
  std::cout << "std::__gcd () = " << std::__gcd(val1, val2)<< "\n";
  return 0;
}
