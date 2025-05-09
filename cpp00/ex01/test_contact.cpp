#include "Contact.hpp"

void    testContact()
{
    /* create a contact */
    Contact contact;

    /* test isEmpty & isComplete */
    std::cout << "is new contact empty? " << (contact.isEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "is new contact complete? " << (contact.isComplete() ? "Yes" : "No") << std::endl;
    /* test empty field */
    bool result = contact.setFirstName("");
    std::cout << "Could set empty firstName? " << (result ? "Yes" : "No") << std::endl;
    /* test setter function */
    result = contact.setFirstName("Chloe");
    std::cout << "Set first name: " << (result ? "Success" : "Failed") << std::endl;
    result = contact.setLastName("John");
    std::cout << "Set last name: " << (result ? "Success" : "Failed") << std::endl;
    result = contact.setNickName("CJ");
    std::cout << "Set nick name: " << (result ? "Success" : "Failed") << std::endl;
    result = contact.setPhoneNumber("123");
    std::cout << "Set phone nbr: " << (result ? "Success" : "Failed") << std::endl;
    result = contact.setDarkSecret("  ");
    std::cout << "Set dark secret: " << (result ? "Success" : "Failed") << std::endl;
    /* test isEmpty & isComplete again */
    std::cout << "is new contact empty? " << (contact.isEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "is new contact complete? " << (contact.isComplete() ? "Yes" : "No") << std::endl;
    /* track init status */
    if (contact.isComplete())
        contact.setInitialized(true);
    std::cout << "Contact init: " << (contact.getInitialized() ? "Success" : "Failed") << std::endl;
    // /* retrieve & display contact info */
    // std::cout << "First name " << contact.getFirstName() << std::endl;
    // std::cout << "Last name " << contact.getLastName() << std::endl;
    // std::cout << "Nick name " << contact.getNickName() << std::endl;
    // std::cout << "Phone number " << contact.getPhoneNumber() << std::endl;
    // std::cout << "Dark secret " << contact.getDarkSecret() << std::endl;
}

int main()
{
    testContact();
    return (0);
}