//./program myfile.txt "hello" "world"
#include "ft_sed.hpp"

int main(int ac, char **av)
{
    if(ac != 4)
    {
        std::cerr << "Usage: ./program <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    ft_sed(av[1], av[2], av[3]);
    return 0;
}