/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:50:59 by fefilipp          #+#    #+#             */
/*   Updated: 2023/03/14 15:51:04 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Contact.hpp"
#include "PhoneBook.hpp"

int main() {
    PhoneBook phonebook;
    std::string command;
    while (1) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::cin >> command;
        if (command == "ADD") {
            std::string firstName, lastName, nickname, phoneNumber, darkestSecret;
            std::cout << "Enter first name: ";
            std::cin >> firstName;
            std::cout << "Enter last name: ";
            std::cin >> lastName;
            std::cout << "Enter nickname: ";
            std::cin >> nickname;
            std::cout << "Enter phone number: ";
            std::cin >> phoneNumber;
            std::cout << "Enter darkest secret: ";
            std::cin >> darkestSecret;
            Contact contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
            phonebook.addContact(contact);
        } else if (command == "SEARCH") {
            phonebook.displayContacts();
            std::cout << "Enter index: ";
            int index;
            std::cin >> index;
            Contact contact = phonebook.getContact(index);
            std::cout << "First Name: " << contact.getFirstName() << std::endl;
            std::cout << "Last Name: " << contact.getLastName() << std::endl;
            std::cout << "Nickname: " << contact.getNickname() << std::endl;
            std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
            std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
        } else if (command == "EXIT") {
            break; 
        } else {
            std::cout << "Invalid command." << std::endl;
        }
    }

    return 0;
}