/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-h <lgomez-h@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:54:23 by lgomez-h          #+#    #+#             */
/*   Updated: 2025/06/26 18:31:58 by lgomez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cerrno>
#include <limits>

static bool isCharLiteral(const std::string &literal) {
    return (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
        || (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]));
}
static bool isSpecialFloat(const std::string &literal) {
    return literal == "-inff" || literal == "+inff" || literal == "nanf";
}

static bool isSpecialDouble(const std::string &literal) {
    return literal == "-inf" || literal == "+inf" || literal == "nan";
}

void ScalarConverter::convert(const std::string &literal) {
    // CHAR
    if (isCharLiteral(literal)) {
    char c = (literal.length() == 1) ? literal[0] : literal[1];
    std::cout << "char: '" << c << "'\n";
    std::cout << "int: " << static_cast<int>(c) << "\n";
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f\n";
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << "\n";
    return;
}

    // FLOAT SPECIAL CASES
    if (isSpecialFloat(literal)) {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: " << literal << "\n";
        std::cout << "double: " << literal.substr(0, literal.length() - 1) << "\n";
        return;
    }

    // DOUBLE SPECIAL CASES
    if (isSpecialDouble(literal)) {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: " << literal << "f\n";
        std::cout << "double: " << literal << "\n";
        return;
    }

    char *endptr = NULL;
    errno = 0;

    // FLOAT
    if (literal[literal.length() - 1] == 'f' && literal.find('.') != std::string::npos){
        float f = std::strtof(literal.c_str(), &endptr);
        if (errno || endptr != literal.c_str() + literal.size() - 1){
            std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
            return;
        }
        int i = static_cast<int>(f);
        char c = static_cast<char>(i);
        if (std::isprint(c) && i == f)
            std::cout << "char: '" << c << "'\n";
        else if (i == f)
            std::cout << "char: Non displayable\n";
        else
            std::cout << "char: impossible\n";
        if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min())
            std::cout << "int: impossible\n";
        else
            std::cout << "int: " << i << "\n";
        std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f\n";
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(f) << "\n";
        return;
    }

    // DOUBLE
    if (literal.find('.') != std::string::npos) {
        double d = std::strtod(literal.c_str(), &endptr);
        if (errno || endptr != literal.c_str() + literal.size()) {
            std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
            return;
        }
        int i = static_cast<int>(d);
        char c = static_cast<char>(i);
        if (std::isprint(c) && i == d)
            std::cout << "char: '" << c << "'\n";
        else if (i == d)
            std::cout << "char: Non displayable\n";
        else
            std::cout << "char: impossible\n";
        if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
            std::cout << "int: impossible\n";
        else
            std::cout << "int: " << i << "\n";
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f\n";
        std::cout << "double: " << std::fixed << std::setprecision(1) << d << "\n";
        return;
    }

    // INT
    long l = std::strtol(literal.c_str(), &endptr, 10);
    if (errno || endptr != literal.c_str() + literal.size() || l > std::numeric_limits<int>::max() || l < std::numeric_limits<int>::min()) {
        std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
        return;
    }
    int i = static_cast<int>(l);
    char c = static_cast<char>(i);
    if (std::isprint(c))
        std::cout << "char: '" << c << "'\n";
    else
        std::cout << "char: Non displayable\n";
    std::cout << "int: " << i << "\n";
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f\n";
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(i) << "\n";
}
