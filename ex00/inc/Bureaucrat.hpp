#ifndef BUREAUCRAT_CPP
# define BUREAUCRAT_CPP

# include <iostream>

class Bureaucrat
{
    private:
        std::string _name;
        int         _grade; 

    public:
        Bureaucrat();
        Bureaucrat(int grade);
        Bureaucrat(std::string name);
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat& other);
        ~Bureaucrat();

        Bureaucrat&  operator=(const Bureaucrat& other);

        std::string     get_name(void) const;
        int             get_grade(void) const;

        void            incrementGrade(void);
        void            decrementGrade(void);

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

#endif