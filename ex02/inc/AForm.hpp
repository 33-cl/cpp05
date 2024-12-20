#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>

class AForm
{
    private:
        std::string     _name;
        bool            _signed;
        int             _gradeToSign;
        int             _gradeToExecute;

    public:
        AForm();
        AForm(std::string name, int gradeToSign, int gradeToExecute);
        AForm(const AForm& other);
        ~AForm();
        AForm&  operator=(const AForm& other);

        std::string     get_name(void) const;
        bool            get_signed(void) const;
        int             get_gradeToSign(void) const;
        int             get_gradeToExecute(void) const;

        void            beSigned(Bureaucrat& bureaucrat);
        virtual int     execute(Bureaucrat const& executor) const = 0;

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

std::ostream    &operator<<(std::ostream &o, AForm &a);

#endif