/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-h <lgomez-h@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 17:26:45 by lgomez-h          #+#    #+#             */
/*   Updated: 2025/06/27 17:50:32 by lgomez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

struct Data ;

class Serializer {
private:
    Serializer();
    ~Serializer();
    Serializer(const Serializer&);
    Serializer& operator=(const Serializer&);
public:
    static unsigned long serialize(Data* ptr);
    static Data* deserialize(unsigned long num);
};   


