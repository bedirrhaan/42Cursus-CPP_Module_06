#include "ScalarConverter.hpp"

bool is_pseudo(const std::string input)
{
    if (input == "nanf" || input == "-inff" || input == "+inff" || input == "nan" || \
        input == "-inf" || input == "+inf" || input == "inf" || input == "inff" || input == "nanff")
        return true;
    return false;
}

bool isNumeric(std::string input)
{
    int sign = 0;

    if(input[0] == '-' || input[0] == '+')
        sign++;
    for ( int i = sign; i < (int)input.length(); i++)
    {
        if(!std::isdigit(input[i]))
        {
            if((input[i] == '.' && input[input.length() - 1] == 'f') || input[i] == '.' || input[i] == 'f')
            {
                for(int x = ++i; x < (int)input.length() - 1; x++)
                {
                    if(!std::isdigit(input[x]))
                        return false;
                }
                return true;
            }
            return false;
        }
    }
    return true;
}

int main(int ac, char **av)
{

    if (ac == 2)
    {
        std::string input = av[1];

        if(isNumeric(input) || input.length() == 1 || is_pseudo(input))
            ScalarConverter::convert(av[1]);
        else
            std::cout << "Undefined arg!!" << std::endl;
        return 0;
    }   

    std::cout << "Error: This program accepts only 1 argument!" << std::endl;
    return 0;
}