/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:26:47 by fefilipp          #+#    #+#             */
/*   Updated: 2023/03/30 16:40:11 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
        return (1);
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::ifstream ifs(filename);
    if (!ifs.is_open())
    {
        std::cout << "Error: file " << filename << " could not be opened." << std::endl;
        return (1);
    }
    std::string output = filename + ".replace";
    std::ofstream ofs(output);
    if (!ofs.is_open())
    {
        std::cout << "Error: file " << output << " could not be opened." << std::endl;
        return (1);
    }
    std::string line;
    while (std::getline(ifs, line))
    {
        size_t pos = 0;
        size_t curr_index = 0;
        std::string tmp = "";
        while(line[curr_index])
        {
            if((pos = line.find(s1, curr_index)) != std::string::npos)
            {
                while (curr_index < pos)
                    tmp += line[curr_index++];
                curr_index += pos + s1.length();
                tmp += s2;
            }
            tmp += line[curr_index++];
        }
        ofs << tmp << std::endl;
    }
    ifs.close();
    ofs.close();
    return (0);
}