#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>
#include <cstring>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy): AForm(copy)
{
	*this = copy;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreation", 145, 137)
{
	_target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		_target = rhs.getTarget();
	}
	return *this;
}

std::string ShrubberyCreationForm::getTarget(void) const
{
	return _target;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	AForm::execute(executor);
	char	*f = (char *)_target.c_str();
	std::ofstream	file(strcat(f , "_shrubbery"));
	file << "                                                                                                   "<< std::endl;
	file << "                                                  ..      .--+++--..                               "<< std::endl;
	file << "                            ..-.....-..        .-++++-----+++++++++--.                             "<< std::endl;
	file << "                          -+++++++++++++---...+++++++++++++++++++#+++-.                            "<< std::endl;
	file << "                        .-++++++#+++++++++++++##++++#+++++++++++++-+++-.                           "<< std::endl;
	file << "                       .-+####+++++#######+++########++++#+#+++++++++-+++--.                       "<< std::endl;
	file << "                       .+#########+++++++++++++++######+########+#+++++++++-----.                  "<< std::endl;
	file << "                        ..+#++#+#++++++++#+++++++--+#########+##+####++#++--+++-+-..               "<< std::endl;
	file << "                         ...-+++++++##++++###+++++++#####+####++++++###++++-++++-+-.               "<< std::endl;
	file << "              -++++++-++++++-+++########+##++###+++++#++++#++++#+-...+++++++++++++--.              "<< std::endl;
	file << "            .-+++++#++++#+##+++++##############+++++++++++++-++#++++++++-+++++++++++--.            "<< std::endl;
	file << "         .  .+++++##############+###############+###++##+++++++++++.   .--+.++++++++++-.           "<< std::endl;
	file << "     .-+++++++++++++++################+###+++###+###++##+++++++++++.    -+++++++++++++-.           "<< std::endl;
	file << "    .++++##+#+++++++++++##############+####+++##+###+###++++++#++#+++++++++#+++++++-++--           "<< std::endl;
	file << "   -+++##+#+#######++++++##+###+##-+########+++++#######++++++++#++++++++++##++++++-.              "<< std::endl;
	file << "  .+###############++++++++-+#########+########++-##+###++-+++##++++####+++++--++++-.              "<< std::endl;
	file << " .-###############+##++++++++++######+##++#++++###++-###++++++++++++###+###++++--++-.              "<< std::endl;
	file << " ..+#####++##+++#+++#+++++##+++++######++++++++####++--+-++-++++++#####+++++++-.                   "<< std::endl;
	file << "  .+++++-.++++-.-+++###+##+++++++-++##+-++#+++++#+++##++++#++++++####+++++-..- ..+++---.           "<< std::endl;
	file << "          ..+++++###++####+++#+++#++++#+++#+-##+##++####++++#+######++++--.-+++++++++++---.        "<< std::endl;
	file << "         .+++++#######+#############++-+-##+#+####++##+++#+####+#++++++....-+++++++++++++--.       "<< std::endl;
	file << "      ..++#############++######+#+++##+######+---#####-+++#+#++++++++++.-+++#++##++++--+--.        "<< std::endl;
	file << "  .++++++#############+++#######+#######++######--+#+#+++++#++--+++++-------+#+++-++++++++-.       "<< std::endl;
	file << ".++++##################+##########+++++++++######-+#+++++#++--..--.+++##+###+++++++++#++++-+--.    "<< std::endl;
	file << ".-+########################++++#+###+#############--+++++#++++++-+++##########++++#+++###+++++-.   "<< std::endl;
	file << " .+##############+####++#++#########+###############++-+++++++++#####++-##+######+++++++#+++++--.  "<< std::endl;
	file << " +#############++#######+. .--+#####+################+++++++++#####--++###++###+++#++++++++++++-.  "<< std::endl;
	file << " .--++.-####++++..+#+##++. . --+#+##+#+++##############+++###############-++#+#+++#++++++++-+++-.  "<< std::endl;
	file << "    -+-+####+-.+. -####+++..  -++#+#+###+##############+++###+.+.-+++-+++-..++#++++-++++.... .     "<< std::endl;
	file << "    .+##+-++.--+-.+###+#++++ .###++#+###########+#####++-+##++.+  ..+ -+....+++...-.--+- . . .     "<< std::endl;
	file << "   .++-+-.-.---+.-+######+++.++++++#+# +++#####++###++++++#+++ -  ..+.-+    +++.   ++--- . .       "<< std::endl;
	file << "    .++...-.. .-.++##+############+-++ ..++-###++#######+++++..-  ..-.+-   .-++.   -++-- .         "<< std::endl;
	file << "    -+-...-..  .+++##+-++-++-+-.--.-++ . .+.#####+####+#+++++. -  ..-       --+.   --+-- .         "<< std::endl;
	file << "    ...   - .  ..+-++++.-++- ...+-.-++ .  --###++++++#+#+++++..-  ..-       . +.   .---- .         "<< std::endl;
	file << "    .-.   - .     .++-.-.+++....-- -++ .  -+###+-+#-+###+++++. -  ..-       . +-   ..-.- .         "<< std::endl;
	file << "     -    - .     .+.- +-+++.    - -++   .+####+-##+-++#+#-++. -   .-       . -.   .---- .         "<< std::endl;
	file << "          -       .--. -+-+.  .  - .-+  .-+####++-##++#++#--+. +   ..       ..+.   ..+-.           "<< std::endl;
	file << "          -        +   -++--     . .-+ ..-######++#+++-++#--+-..   ..       ..--    .-.. .         "<< std::endl;
	file << "          -        +   .--..     . .-+...#+##+##+#-#+#++++++-+.    ..       .--     .+-. .         "<< std::endl;
	file << "          -      . -    ....     . ..+ .###++####+++###-+##++-+-.  ..       ..-      ..            "<< std::endl;
	file << "          .        .   .--.      ..--+.####+++###+#++###++++++---.. .        .--     .             "<< std::endl;
	file << "          .      . .    . .      . -++###+-+++####-+-+###-++#+++---          ...                   "<< std::endl;
	file << "          -      . .            .+++#+-++++#+#+##++---###++-+++++++++.        -.                   "<< std::endl;
	file << "                   .       .-++++++##++#++###++##-+-++##+#++-++##+#+++-+-.    ..                   "<< std::endl;
	file << "                        .-++++#++##++++##+####+-----++######+++-++++++++++++--..                   "<< std::endl;
	file << "            -+++++++-++++#++######+#++++---+----#-+++++##+##-++++++++--#+++++--+++-.               "<< std::endl;
	file << "   .-++++++++++#####+++++#++++#+++---++-+++++++#+-+++#+++++++++-+++++++++--+++++++++++----.        "<< std::endl;
	file << "   --++-+++++++---+-++-+++++++++++++--+#+++-++++++++#+----+++++++++++-++++-+..... ...              "<< std::endl;
	file << "                                                                                                   "<< std::endl;
	file.close();
}

const char * ShrubberyCreationForm::NotSignedException::what() const throw()
{
	return "Form Not Signed!";
}

const char * ShrubberyCreationForm::GradeTooHighException::what() const throw()
{
	return "Grade Too High!";
}

const char * ShrubberyCreationForm::GradeTooLowException::what() const throw()
{
	return "Grade Too Low!";
}


std::ostream	&operator<<(std::ostream &out, const ShrubberyCreationForm &obj)
{
	out << "ShrubberyCreationForm : " << obj.getName() << " Signature grade : " << obj.getSignGrade() << " Execution grade : " << obj.getExecuteGrade() << "Target : " << obj.getTarget() << " Status : " << ((obj.getStatus())? "SIGNED" : "NOT SIGNED")<< std::endl;
	return out;
}
