#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

Bureaucrat::Bureaucrat() : _name("bureaucrat"), _grade(150)
{
    std::cout << "Bureaucrat's constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(int grade)
{
    _name = "bureaucrat";
    if (grade > 150)
        throw GradeTooLowException();
    else if (grade < 1)
        throw GradeTooHighException();
    else
        _grade = grade;
    std::cout << "Bureaucrat's constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name) : _name(name)
{
    _grade = 150;
    std::cout << "Bureaucrat's constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    if (grade > 150)
        throw GradeTooLowException();
    else if (grade < 1)
        throw GradeTooHighException();
    else
        _grade = grade;
    std::cout << "Bureaucrat's constructor called" << std::endl;
}


Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
    std::cout << "Bureaucrat's constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat's destructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other) {
        this->_name = other.get_name();
        this->_grade = other.get_grade();
    }
    return *this;
}

const std::string& Bureaucrat::get_name(void) const
{
    return _name;
}

int Bureaucrat::get_grade(void) const
{
    return _grade;
}

void    Bureaucrat::incrementGrade(void)
{
    if (_grade <= 1)
        throw GradeTooHighException();
    _grade--;
}

void    Bureaucrat::decrementGrade(void)
{
    if (_grade >= 150)
        throw GradeTooLowException();
    _grade++;
}

void    Bureaucrat::signForm(Form &form)
{
    if (form.get_signed())
        std::cout << _name << " couldn't sign " << form.get_name() << " because it's already signed" << std::endl;
    else if (_grade > form.get_gradeToSign())
        std::cout << _name << " couldn't sign " << form.get_name() << " because the bureaucrat's grade isn't high enough" << std::endl;
    else
    {
        std::cout << _name << " signed " << form.get_name() << std::endl;
        form.beSigned(*this);
    }
}

const char  *Bureaucrat::GradeTooHighException::what() const throw() {
    return "grade too high...";
}

const char  *Bureaucrat::GradeTooLowException::what() const throw() {
    return "grade too low...";
}