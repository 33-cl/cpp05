#include "../inc/Form.hpp"

int main()
{
    try {
        // Test de création de bureaucrates
        Bureaucrat john("John", 1);  // Grade le plus élevé
        Bureaucrat doe("Doe", 150); // Grade le plus bas
        Bureaucrat mid("Mid", 75);  // Grade moyen

        std::cout << john.get_name() << " has grade " << john.get_grade() << std::endl;
        std::cout << doe.get_name() << " has grade " << doe.get_grade() << std::endl;
        std::cout << mid.get_name() << " has grade " << mid.get_grade() << std::endl;

        // Test des exceptions pour la création
        try {
            Bureaucrat tooLow("TooLow", 151); // Trop bas
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

        try {
            Bureaucrat tooHigh("TooHigh", 0); // Trop haut
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

        // Test des incréments et décréments de grade
        try {
            john.incrementGrade(); // Devrait lever une exception (grade déjà 1)
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

        try {
            doe.decrementGrade(); // Devrait lever une exception (grade déjà 150)
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

        mid.incrementGrade();
        std::cout << mid.get_name() << " after increment: grade " << mid.get_grade() << std::endl;

        mid.decrementGrade();
        std::cout << mid.get_name() << " after decrement: grade " << mid.get_grade() << std::endl;

        // Test de création de formulaires
        Form contract("Contract", 50, 50);
        Form lowForm("LowForm", 150, 150);

        std::cout << &contract << std::endl;
        std::cout << &lowForm << std::endl;

        // Test de signature de formulaires
        john.signForm(contract); // Devrait signer
        mid.signForm(contract);  // Ne devrait pas signer (grade trop bas)

        doe.signForm(lowForm); // Devrait signer
        john.signForm(lowForm); // Déjà signé

        // Test des exceptions pour les grades dans les formulaires
        try {
            Form invalidForm("InvalidForm", 0, 150); // Grade trop haut
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

        try {
            Form invalidForm("InvalidForm", 150, 200); // Grade trop bas
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    } catch (const std::exception &e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    return 0;
}

