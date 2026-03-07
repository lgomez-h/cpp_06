/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-h <lgomez-h@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:50:08 by lgomez-h          #+#    #+#             */
/*   Updated: 2025/07/01 16:50:15 by lgomez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

// Declaración de las funciones
Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main() {
	std::srand(std::time(0));
    	Base* obj = generate();
    	std::cout << "Identificando con puntero: ";
    	identify(obj);
    	std::cout << "Identificando con referencia: ";
    	identify(*obj);
    	delete obj;
    	return 0;
}
