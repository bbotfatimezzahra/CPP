#include <cstdlib>
#include <iostream>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main (int argc, char **argv)
{
	(void)argc;
	(void)argv;
try {
	Bureaucrat hermano("Hermano", LOWEST_GRADE);

	Bureaucrat ebil("Ebil", HIGHEST_GRADE);
	std::cout << std::endl;

	std::cout << std::endl;
	Intern rando;
	AForm *acf = rando.makeForm("Shion","Ebil");
	std::cout << acf;
	AForm *scf = rando.makeForm("Shrubbery creation","Ebil");
	std::cout << *scf;
	AForm *ppf = rando.makeForm("Presidential pardon","Ebil");
	std::cout << *ppf;
	AForm *rrf = rando.makeForm("Robotomy request","Ebil");
	std::cout << *rrf;

	std::cout << std::endl;

	ebil.executeForm(*scf);
	scf->beSigned(ebil);
	ebil.executeForm(*scf);

	std::cout << std::endl;

	ebil.executeForm(*ppf);
	ppf->beSigned(ebil);
	ebil.executeForm(*ppf);

	std::cout << std::endl;

	ebil.executeForm(*rrf);
	rrf->beSigned(ebil);
	ebil.executeForm(*rrf);

	std::cout << std::endl;

	
	scf->execute(hermano);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	return EXIT_SUCCESS;
}
