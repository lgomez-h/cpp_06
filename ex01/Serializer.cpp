/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-h <lgomez-h@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 17:26:59 by lgomez-h          #+#    #+#             */
/*   Updated: 2025/06/27 17:45:56 by lgomez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::~Serializer() {}

Serializer::Serializer(const Serializer&) {}

Serializer& Serializer::operator=(const Serializer&){
    return *this;
}

unsigned long Serializer::serialize(Data* ptr) {
    return reinterpret_cast<unsigned long>(ptr);
}

Data* Serializer::deserialize(unsigned long num) {
    return reinterpret_cast<Data*>(num);
}




