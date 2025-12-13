import std;
import math;
import math2;
import copy;

int main()
{
    std::cout << math::add(1, 2) << std::endl;
    std::cout << math2::add(2.0, 3.0) << std::endl;

    char src[]  = "hello";
    char dest[6]{};

    copy::copy(src, dest, 6);

    std::cout << dest << '\n';
}
