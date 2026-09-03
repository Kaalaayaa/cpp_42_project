#include "ft_sed.hpp"

bool ft_sed(std::string filename, std::string s1, std::string s2)
{
    if(s1.empty())
    {
        std::cerr << "Error: s1 must not be empty" << std::endl;
        return false;
    }
    std::ifstream input(filename);
    if(!input)
    {
        std::cerr << "Error: cannot open file " << filename << std::endl;
        return false;
    }
    std::ofstream output(filename + ".replace");
    if(!output)
    {
        std::cerr << "Error: cannot create file " << filename << ".replace" << std::endl;
        return false;
    }
    std::string line;
    while(std::getline(input, line))
    {
        size_t pos = line.find(s1, 0);
        while(pos != std::string::npos)
        {
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos = pos + s2.length();
            pos = line.find(s1, pos);
        }
        output << line;
        if(!input.eof())
            output << '\n';
    }
    return true;
}