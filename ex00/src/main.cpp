#include "../inc/Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat b1("Alice", 1);
        std::cout << b1.get_name() << " has grade " << b1.get_grade() << std::endl;

        std::cout << "Incrementing grade..." << std::endl;
        b1.incrementGrade(); // Should throw GradeTooHighException
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cout << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n-----------\n" << std::endl;

    try {
        Bureaucrat b2("Bob", 150);
        std::cout << b2.get_name() << " has grade " << b2.get_grade() << std::endl;

        std::cout << "Decrementing grade..." << std::endl;
        b2.decrementGrade(); // Should throw GradeTooLowException
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cout << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}