/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 11:33:10 by chloe             #+#    #+#             */
/*   Updated: 2025/06/06 11:56:38 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

// int main()
// {
//     int a = 10, b = 0;

//     (void)a;
//     try
//     {
//         if (b == 0)
//             throw runtime_error("Division by zero");
//     } catch (runtime_error &e)
//     {
//         cout << "Caught an exception: " << e.what() << endl;
//     }
//     return (0);
// }

int main()
{
    try
    {
        throw "42paris"; // this is a const char*
    // } catch (string e) // try to catch a std::string
    } catch (const char* &e)
    {
        cout << "Caught an string: " << e << endl;
    }
}