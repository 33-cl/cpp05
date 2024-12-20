#include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : AForm("shrubberyCreationForm", 145, 137), _target(target)
{
    std::cout << "ShrubberyCreationForm's default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other)
{
    std::cout << "ShrubberyCreationForm's copy constructor called" << std::endl;
    *this = other;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm's destructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
        AForm::operator=(other);
    std::cout << "ShrubberyCreationForm's copy assignment operator called" << std::endl;
    return *this;
}

int ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
    if (!this->get_signed())
        return (std::cout << this->get_name() << " needs to be signed !" << std::endl, 1);
    else if (executor.get_grade() > this->get_gradeToExecute())
        return (std::cout << executor.get_name() << "'s grade isn't high enough to execute " << this->get_name() << std::endl, 1);
    else
    {
        std::string     filename = _target + "_shrubbery";
        std::ofstream   outfile(filename.c_str());
        if (outfile.fail())
        {
            std::cout << "Could not open output file" << std::endl;
            return 1;
        }
        outfile << "          .     .  .      +     .      .          .           \n     .       .      .     #       .           .               \n        .      .         ###            .      .      .       \n      .      .   '#:. .:##'##:. .:#'  .      .                \n          .      . '####'###'####'  .                         \n       .     '#:.    .:#'###'#:.    .:#'  .        .       .  \n  .             '#########'#########'        .        .       \n        .    '#:.  '####'###'####'  .:#'   .       .          \n     .     .  '#######'##'##'#######'                  .    \n                .'##'#####'#####'##'           .      .       \n    .   '#:. ...  .:##'###'###'##:.  ... .:#'     .           \n      .     '#######'##'#####'##'#######'      .     .        \n    .    .     '#####'#######'#####'    .      .            \n            .     '      000      '    .     .                \n       .         .   .   000     .        .       .           \n.. .. ..................O000O........................ ......\n          .     .  .      +     .      .          .           \n     .       .      .     #       .           .               \n        .      .         ###            .      .      .       \n      .      .   '#:. .:##'##:. .:#'  .      .                \n          .      . '####'###'####'  .                         \n       .     '#:.    .:#'###'#:.    .:#'  .        .       .  \n  .             '#########'#########'        .        .       \n        .    '#:.  '####'###'####'  .:#'   .       .          \n     .     .  '#######'##'##'#######'                  .    \n                .'##'#####'#####'##'           .      .       \n    .   '#:. ...  .:##'###'###'##:.  ... .:#'     .           \n      .     '#######'##'#####'##'#######'      .     .        \n    .    .     '#####'#######'#####'    .      .            \n            .     '      000      '    .     .                \n       .         .   .   000     .        .       .           \n.. .. ..................O000O........................ ......";
        outfile.close();
        return 0;
    }    
}