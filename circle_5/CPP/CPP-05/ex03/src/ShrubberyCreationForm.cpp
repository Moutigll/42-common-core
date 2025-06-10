/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 21:14:05 by ele-lean          #+#    #+#             */
/*   Updated: 2025/06/10 22:03:55 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("Shrubbery Creation Form", 145, 137), _target(target) {
		if (_target.empty()) {
			this->_target = "default_target";
		}
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other), _target(other._target) {
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void	ShrubberyCreationForm::executeAction() const {
	std::ofstream	ofs((_target + "_shrubbery").c_str());
	if (!ofs.is_open()) {
		std::cerr << "Failed to open the file." << std::endl;
		return;
	}

	ofs << "      ,.,\n";
	ofs << "      MMMM_    ,..,\n";
	ofs << "        \"_ \"__\"MMMMM          ,...,,\n";
	ofs << " ,..., __.\" --\"    ,.,     _-\"MMMMMMM\n";
	ofs << "MMMMMM\"___ \"_._   MMM\"_.\"\" _ \"\"\"\"\"\"\n";
	ofs << " \"\"\"\"\"    \"\" , \\_.   \"_. .\"\n";
	ofs << "        ,., _\"__ \\__./ .\"\n";
	ofs << "       MMMMM_\"  \"_    ./\n";
	ofs << "        ''''      (    )\n";
	ofs << " ._______________.-'____\"---._.\n";
	ofs << "  \\                          /\n";
	ofs << "   \\________________________/\n";
	ofs << "   (_)                    (_)\n";

	ofs.close();
}
