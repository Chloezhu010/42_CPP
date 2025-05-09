#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>

/* contact class to store individual contact info */
class Contact
{
    private:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string darkSecret;
        bool        isInitialized;
    public:
        // contructor & destructor
        Contact();
        ~Contact();
        
        // setters
        bool    setFirstName(std::string name);
        bool    setLastName(std::string name);
        bool    setNickName(std::string name);
        bool    setPhoneNumber(std::string nbr);
        bool    setDarkSecret(std::string secret);

        // getters
        std::string getFirstName();
        std::string getLastName();
        std::string getNickName();
        std::string getPhoneNumber();
        std::string getDarkSecret();

        // utilities
        bool    isEmpty();
        bool    isComplete();
        void    setInitialized(bool value);
        bool    getInitialized();
};

#endif