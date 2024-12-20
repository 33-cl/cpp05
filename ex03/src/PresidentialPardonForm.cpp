#include "../inc/PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

PresidentialPardonForm::PresidentialPardonForm(std::string const target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
    std::cout << "PresidentialPardonForm's default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other)
{
    std::cout << "PresidentialPardonForm's copy constructor called" << std::endl;
    *this = other;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm's destructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (this != &other)
        AForm::operator=(other);
    std::cout << "PresidentialPardonForm's copy assignment operator called" << std::endl;
    return *this;
}

int PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
    if (!this->get_signed())
    {
        std::cout << this->get_name() << " needs to be signed !" << std::endl;
        return 1;
    }
    else if (executor.get_grade() > this->get_gradeToExecute())
    {
        std::cout << executor.get_name() << "'s grade isn't high enough to execute " << this->get_name() << std::endl;
        return 1;
    }
    else
    {
        std::cout << _target << " has been pardoned by Zaphod Beeblerox" << std::endl;
        return 0;
    }
}