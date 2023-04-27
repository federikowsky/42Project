/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:38:03 by fefilipp          #+#    #+#             */
/*   Updated: 2023/03/30 19:38:06 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << " " << std::endl;
    std::cout << "  CALLING CONSTRUCTOR " << std::endl;
    std::cout << " " << std::endl;

    const Animal *_animal_ = new Animal();
    const Animal *_dog_ = new Dog();
    const Animal *_cat_ = new Cat();
    const WrongAnimal *_wAnimal_ = new WrongAnimal();
    const WrongAnimal *_wCat_ = new WrongCat();

    std::cout << " " << std::endl;
    std::cout << "  CALLING TYPE " << std::endl;
    std::cout << " " << std::endl;

    std::cout << _dog_->getType() << " " << std::endl;
    std::cout << _cat_->getType() << " " << std::endl;
    std::cout << _wCat_->getType() << " " << std::endl;

    std::cout << " " << std::endl;
    std::cout << "  CALLING VERSE " << std::endl;
    std::cout << " " << std::endl;

    _animal_->makeSound();
    _dog_->makeSound();
    _cat_->makeSound();
    _wAnimal_->makeSound();
    _wCat_->makeSound();

    std::cout << " " << std::endl;
    std::cout << "  CALLING DECONSTRUCTOR " << std::endl;
    std::cout << " " << std::endl;

    delete _animal_;
    delete _dog_;
    delete _cat_;
    delete _wAnimal_;
    delete _wCat_;

    return 0;
}