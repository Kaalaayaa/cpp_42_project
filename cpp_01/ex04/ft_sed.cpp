#include "ft_sed.hpp"

void ft_sed (std::string filename, std::string s1, std::string s2)
{
    if(s1.empty())
        return;
    std::ifstream input(filename);
    std::ofstream output(filename + ".replace");

    if(!input)
    {
        std::cerr << "Error opening file" << std::endl;
        return;
    }
    if(!output)
    {
        std::cerr << "Error creating file" << std::endl;
        return;
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
}