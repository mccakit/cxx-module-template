import std;
import math;
import copy;

int main()
{
    std::cout << math::add(1, 2) << std::endl;
    char src[]  = "hello";
    char dest[6]{};

    copy::copy(src, dest, 6);

    std::cout << dest << '\n';
}
