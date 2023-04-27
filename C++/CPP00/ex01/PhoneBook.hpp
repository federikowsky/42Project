/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:51:06 by fefilipp          #+#    #+#             */
/*   Updated: 2023/03/14 15:51:06 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>

#include "Contact.hpp"

class PhoneBook {
private:
    Contact contacts[8];
    int currentIndex;

public:
    PhoneBook() : currentIndex(0) {}
    ~PhoneBook() {}

    void addContact(Contact contact);

    Contact getContact(int index);

    void displayContacts();

};

#endif 