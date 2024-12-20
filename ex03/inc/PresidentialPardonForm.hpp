#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;

    public:
        PresidentialPardonForm(std::string const target);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        ~PresidentialPardonForm();

        PresidentialPardonForm&  operator=(const PresidentialPardonForm& other);

        int execute(Bureaucrat const& executor) const;
};

#endif