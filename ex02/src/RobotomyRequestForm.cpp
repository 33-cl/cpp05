#include "../inc/RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string const target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    std::cout << "RobotomyRequestForm's default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other)
{
    std::cout << "RobotomyRequestForm's copy constructor called" << std::endl;
    *this = other;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm's destructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
        AForm::operator=(other);
    std::cout << "RobotomyRequestForm's copy assignment operator called" << std::endl;
    return *this;
}

int RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
    if (!this->get_signed())
        std::cout << this->get_name() << " needs to be signed !" << std::endl;
    else if (executor.get_grade() > this->get_gradeToExecute())
        std::cout << executor.get_name() << "'s grade isn't high enough to execute " << this->get_name() << std::endl;
    else
    {
        std::srand(std::time(0));
        if (std::rand() % 2 == 0)
            std::cout << _target << " has been robotomised" << std::endl;
        else
            std::cout << "robotomatisation failed..." << std::endl;
    }
    return 0;
}