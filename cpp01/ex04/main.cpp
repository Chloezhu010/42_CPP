/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <czhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 21:24:20 by chloe             #+#    #+#             */
/*   Updated: 2025/05/20 12:02:52 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream> // for open file

void    replaceFileInfo(const std::string &filename,
                        const std::string &s1,
                        const std::string &s2)
{
    std::string     line; // to be processed line
    size_t          pos; // search position
    bool            found = false; // track occurance of s1
    
    // open input file
    std::ifstream   input(filename.c_str());
    if (!input)
    {
        std::cerr << "Error: Failed to open file" << std::endl;
        return ;
    }
    // create output file
    std::ofstream   output((filename + ".replace").c_str());
    if (!output)
    {
        std::cerr << "Error: Failed to create output file" << std::endl;
        input.close();
        return ;
    }
    // process file line by line
    while (std::getline(input, line))
    {
        pos = 0;
        while (true)
        {
            // check occurance of s1
            if (line.find(s1) != std::string::npos)
                found = true;
            pos = line.find(s1, pos);
            if (pos == std::string::npos)
                break ;
            // remove the matched s1
            line.erase(pos, s1.length());
            // insert s2
            line.insert(pos, s2);
            pos += s2.length();
        }
        output << line;
        if (!input.eof())
            output << '\n';
    }
    if (!found)
        std::cout << "String "<< s1 << " not found" << std::endl;
    // close file
    input.close();
    output.close();
}

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cout << "Usage: " << av[0] << " <filename> <s1> <s2>" << std::endl;
        return (1);
    }
    replaceFileInfo(av[1], av[2], av[3]);
    return (0);
}
