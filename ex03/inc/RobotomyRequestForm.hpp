#ifndef ROOBOTOMYREQUESTFORM_HPP
# define ROOBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <fstream>

class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;

    public:
        RobotomyRequestForm(std::string const target);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        ~RobotomyRequestForm();

        RobotomyRequestForm&  operator=(const RobotomyRequestForm& other);

        int execute(Bureaucrat const& executor) const;
};

#endif