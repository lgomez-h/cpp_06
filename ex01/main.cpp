/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-h <lgomez-h@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 17:46:39 by lgomez-h          #+#    #+#             */
/*   Updated: 2025/06/27 17:46:45 by lgomez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main() {
    Data data;
    data.number = 123;
    data.text = "Prueba de serialización";

    // Serializar el puntero
    unsigned long num = Serializer::serialize(&data);

    // Deserializar el puntero
    Data* ptr = Serializer::deserialize(num);

    // Mostrar resultados
    std::cout << "Dirección original:   " << &data << std::endl;
    std::cout << "Dirección recuperada: " << ptr << std::endl;
    std::cout << "number: " << data.number << std::endl;
    std::cout << "text:   " << data.text << std::endl;
    std::cout << "number: " << ptr->number << std::endl;
    std::cout << "text:   " << ptr->text << std::endl;

    if (ptr == &data)
        std::cout << "¡Serialización correcta!" << std::endl;
    else
        std::cout << "Error en la serialización." << std::endl;

    return 0;
}
