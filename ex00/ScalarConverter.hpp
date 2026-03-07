/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-h <lgomez-h@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:36:46 by lgomez-h          #+#    #+#             */
/*   Updated: 2025/06/26 18:00:51 by lgomez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class ScalarConverter {
    private:
    ScalarConverter();
    ~ScalarConverter();
    
    public:
    static void convert(const std::string &literal);
};
