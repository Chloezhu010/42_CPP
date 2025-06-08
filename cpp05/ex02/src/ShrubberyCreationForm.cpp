#include "../incl/ShrubberyCreationForm.hpp"

/* default constructor */
ShrubberyCreationForm::ShrubberyCreationForm(): AForm("default", 145, 137), _target("default")
{
    std::cout << "ShrubberyCreationForm: Default constructor called" << std::endl;
}

/* constructor */
ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm(target, 145, 137), _target(target)
{
    std::cout << "ShrubberyCreationForm: Constructor called" << std::endl;
}

/* copy constructor */
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
{
    std::cout << "ShrubberyCreationForm: Copy constructor called" << std::endl;
    *this = other;
}

/* copy assignment operator */
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    std::cout << "ShrubberyCreationForm: Copy assignment operator called" << std::endl;
    if (this == &other) {
        return *this;
    }
    return *this;
}

/* destructor */
ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm: Destructor called" << std::endl;
}

/* member functions */
void    ShrubberyCreationForm::executeAction() const
{
    std::string file_name = this->getName() + "_shrubbery";

    // create and open the file with file_name
    std::ofstream outfile(file_name.c_str());
    if (outfile.is_open())
    {
        // ASCII tree
        outfile << "    /\\    \n";
        outfile << "   /  \\   \n";
        outfile << "  /++++\\  \n";
        outfile << " /  ++  \\ \n";
        outfile << "    ||    \n";
        outfile << "    ||    \n";
        outfile << "~~~~~~~~~~\n";
        // close the file
        outfile.close();
        std::cout << "🎉🎉 Successfully create " << file_name << std::endl;
    }
    else
    {
        std::cerr << "❌❌ Failed to create file " << file_name << std::endl;
    }
}

/* getter */
std::string    ShrubberyCreationForm::getName() const
{
    return (this->_target);
}
