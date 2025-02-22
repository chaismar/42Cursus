#include <iostream>
#include <fstream>

inline bool exists_test (const std::string& name) {
    std::ifstream f(name.c_str());
    return f.good();
}

int check_args(int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << "check nb args\n";
        return (1);
    }
    if (exists_test(av[1]) == 0)
    {
        std::cerr << "file doesn't exist\n";
        return (1);
    }
    return (0);
}

int    replace(std::string fileName, std::string s1, std::string s2)
{
    std::ifstream file(fileName.c_str());
    if (!file.is_open())
    {
        std::cout << "file isn't open";
        return (1);
    }
    std::ofstream Myfile2((fileName + ".replace").c_str());
    for (std::string buffer; std::getline(file, buffer); )
    {
        size_t i = buffer.find(s1);
        while (i != std::string::npos) 
        {
            buffer.erase(i, s1.length());
            buffer.insert(i, s2);
            i = buffer.find(s1);
        }
        if (file.eof())
            Myfile2 << buffer;
        else 
            Myfile2 << buffer << "\n";
    }
    return (0);
}

int main(int ac, char **av)
{
    if (check_args(ac, av) == 1)
        return(1);
    return replace(av[1], av[2], av[3]);
}