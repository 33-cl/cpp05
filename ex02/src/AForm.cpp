#include "../inc/AForm.hpp"

AForm::AForm()
{
    _name = "AForm";
    _signed = false;
    _gradeToSign = 75;      //Arbitrarily chosen value
    _gradeToExecute = 75;   //Arbitrarily chosen value
    std::cout << "AForm's constructor called" << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name)
{
    if (gradeToSign > 150)
        throw GradeTooLowException();
    else if (gradeToSign < 1)
        throw GradeTooHighException();
    else
        _gradeToSign = gradeToSign;

    if (gradeToExecute > 150)
        throw GradeTooLowException();
    else if (gradeToExecute < 1)
        throw GradeTooHighException();
    else
        _gradeToExecute = gradeToExecute;

    _signed = false;
    std::cout << "AForm's constructor called" << std::endl;
}


AForm::AForm(const AForm& other) : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
    std::cout << "AForm's copy constructor called" << std::endl;
}

AForm::~AForm()
{
    std::cout << "AForm's destructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other) {
        this->_name = other._name;
        this->_signed = other._signed;
        this->_gradeToSign = other._gradeToSign;
        this->_gradeToExecute = other._gradeToExecute;
    }
    return *this;
}

std::string AForm::get_name(void) const
{
    return _name;
}

bool    AForm::get_signed(void) const
{
    return _signed;
}

int     AForm::get_gradeToSign(void) const
{
    return _gradeToSign;
}

int     AForm::get_gradeToExecute(void) const
{
    return _gradeToExecute;
}

void    AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (_signed)
        std::cout << get_name() << " is already signed" << std::endl;
    if (bureaucrat.get_grade() >= 150)
        throw GradeTooLowException();
    if (bureaucrat.get_grade() <= _gradeToSign)
        _signed = true;
}

const char  *AForm::GradeTooHighException::what() const throw() {
    return "grade too high...";
}

const char  *AForm::GradeTooLowException::what() const throw() {
    return "grade too low...";
}

std::ostream    &operator<<(std::ostream &output, AForm &form)
{
    output << "Form " << form.get_name() << ":" << std::endl
        << "signed            = " << form.get_signed() << std::endl
        << "min grade to sign = " << form.get_gradeToSign() << std::endl
        << "min grade to exec = " << form.get_gradeToExecute() << std::endl;
    return output;
}