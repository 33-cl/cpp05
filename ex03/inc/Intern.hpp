#ifndef INTER_HPP
# define INTERN_HPP

# include <iostream>
# include <AForm.hpp>


class Intern
{
    public:
        Intern();
        Intern(const Intern& other);
        ~Intern();

        Intern&  operator=(const Intern& other);

        AForm    *makeForm(std::string name, std::string target) const;
};

Intern::Intern()
{
    std::cout << "Intern's default constructor called" << std::endl;
}

Intern::Intern(const Intern& other)
{
    std::cout << "Intern's copy constructor called" << std::endl;
    *this = other;
}

Intern::~Intern()
{
    std::cout << "Intern's destructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& other)
{
    std::cout << "Intern's copy assignment operator called" << std::endl;
    return *this;
}

AForm    *Intern::makeForm(std::string name, std::string target) const
{
    std::string form_names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    void        AForm::forms[3] = {&Intern::ShrubberyCreationForm()};
    
}

#endif