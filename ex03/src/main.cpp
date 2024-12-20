#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

int main()
{
    try {
        Bureaucrat              *fred = new Bureaucrat(137);
        ShrubberyCreationForm   *form1 = new ShrubberyCreationForm("tree");

        fred->incrementGrade();
        fred->signForm(*form1);
        form1->execute(*fred);
    } catch (const std::exception &e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    std::cout << "\n-------------\n\n";

    try {
        Bureaucrat              *fred = new Bureaucrat(3);
        RobotomyRequestForm     *form1 = new RobotomyRequestForm("tree");

        fred->incrementGrade();
        fred->signForm(*form1);
        form1->execute(*fred);
        fred->executeForm(*form1);
    } catch (const std::exception &e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    std::cout << "\n-------------\n\n";

    try {
        Bureaucrat              *fred = new Bureaucrat(3);
        PresidentialPardonForm  *form1 = new PresidentialPardonForm("tree");

        fred->incrementGrade();
        fred->signForm(*form1);
        form1->execute(*fred);
    } catch (const std::exception &e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    return 0;
}

