/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:50:56 by fefilipp          #+#    #+#             */
/*   Updated: 2023/03/30 15:19:20 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"


// PhoneBook::PhoneBook() : currentIndex(0) {
    
// }

// PhoneBook::~PhoneBook() {
//     return;
// }


void PhoneBook::addContact(Contact contact) {
    if (currentIndex >= 8) {
        currentIndex = 0;
    }
    contacts[currentIndex] = contact;
    currentIndex++;
}

Contact PhoneBook::getContact(int index) {
    if (index >= 0 && index < currentIndex) {
        return contacts[index];
    } else {
        // Return an empty contact if index is out of range
        return Contact("", "", "", "", "");
    }
}

void PhoneBook::displayContacts() {
    // Display column headers
    std::cout << "|         Index         |       First Name      |       Last Name       |       Nickname        |" << std::endl;
    std::cout << "|-----------------------|-----------------------|-----------------------|-----------------------|" << std::endl;

    for (int i = 0; i < currentIndex; i++) {
        Contact contact = contacts[i];
        std::string index = std::to_string(i);
        std::string firstName = contact.getFirstName();
        std::string lastName = contact.getLastName();
        std::string nickname = contact.getNickname();

        // // Truncate and align text
        index = index.substr(0, 21);
        firstName = firstName.substr(0, 21);
        lastName = lastName.substr(0, 21);
        nickname = nickname.substr(0, 21);
        index = std::string(21 - index.length(), ' ') + index;
        firstName = std::string(21 - firstName.length(), ' ') + firstName;
        lastName = std::string(21 - lastName.length(), ' ') + lastName;
        nickname = std::string(21 - nickname.length(), ' ') + nickname;

        // Display contact
        std::cout << "| " << index << " | " << firstName << " | " << lastName << " | " << nickname << " |" << std::endl;
    }
}