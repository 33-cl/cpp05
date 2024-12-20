#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>

class Form
{
    private:
        std::string     _name;
        bool            _signed;
        int             _gradeToSign;
        int             _gradeToExecute;

    public:
        Form();
        Form(std::string name, int gradeToSign, int gradeToExecute);
        Form(const Form& other);
        ~Form();
        Form&  operator=(const Form& other);

        void    beSigned(Bureaucrat &bureaucrat);

        std::string     get_name(void) const;
        bool            get_signed(void) const;
        int             get_gradeToSign(void) const;
        int             get_gradeToExecute(void) const;

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream    &operator<<(std::ostream &o, Form &a);

#endif