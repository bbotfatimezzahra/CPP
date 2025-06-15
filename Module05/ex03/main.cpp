#include <cstdlib>
#include <iostream>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

using std::cout;
using std::cerr;
using std::endl;

int main (int argc, char **argv)
{
	(void)argc;
	(void)argv;
try {
	Bureaucrat hermano("Hermano", LOWEST_GRADE);

	Bureaucrat ebil("Ebil", HIGHEST_GRADE);
	cout << endl;

	cout << endl;
	Intern rando;
	AForm *acf = rando.makeForm("Shion","Ebil");
	cout << acf;
	AForm *scf = rando.makeForm("Shrubbery creation","Ebil");
	cout << *scf;
	AForm *ppf = rando.makeForm("Presidential pardon","Ebil");
	cout << *ppf;
	AForm *rrf = rando.makeForm("Robotomy request","Ebil");
	cout << *rrf;

	cout << endl;

	ebil.executeForm(*scf);
	scf->beSigned(ebil);
	ebil.executeForm(*scf);

	cout << endl;

	ebil.executeForm(*ppf);
	ppf->beSigned(ebil);
	ebil.executeForm(*ppf);

	cout << endl;

	ebil.executeForm(*rrf);
	rrf->beSigned(ebil);
	ebil.executeForm(*rrf);

	cout << endl;

	
	scf->execute(hermano);
	}
	catch (std::exception& e) {
		cerr << e.what() << endl;
	}

	cout << endl;
	return EXIT_SUCCESS;
}
