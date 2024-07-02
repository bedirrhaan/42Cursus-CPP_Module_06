#pragma once

#include <iostream>
#include <exception>
#include <cstdlib>
#include <cctype>
#include <iomanip>
#include <limits>

class ScalarConverter
{
    private:
        ScalarConverter();
        ~ScalarConverter();

        ScalarConverter &operator=(const ScalarConverter& other);
        ScalarConverter(const ScalarConverter& other);

    public:
        static void			convert(std::string input);
        
		static void			toChar(std::string input);
		static void			toInt(std::string input);
		static void			toFloat(std::string input);
		static void			toDouble(std::string input);


};

