/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:11:57 by ele-lean          #+#    #+#             */
/*   Updated: 2025/03/21 18:21:00 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "fstream"

int	main(int ac, char **ar)
{
	if (ac != 4)
	{
		std::cout << "Error: wrong number of arguments" << std::endl;
		return (1);
	}
	std::string		filename = ar[1];
	std::string		outfilename = filename + ".replace";
	std::string		s1 = ar[2];
	std::string		s2 = ar[3];
	std::string		line;
	
	std::ifstream	ifs(filename.c_str());
	if (!ifs.is_open())
	{
		std::cout << "Error: Can't open file" << std::endl;
		return (1);
	}
	std::ofstream	ofs(outfilename.c_str());
	if (!ofs.is_open())
	{
		std::cout << "Error: Can't create file" << std::endl;
		return (1);
	}
	while (std::getline(ifs, line))
	{
		std::string new_line = "";
		size_t startpos = 0;
		size_t pos;
		while ((pos = line.find(s1, startpos)) != std::string::npos)
		{
			new_line.append(line, startpos, pos - startpos);
			new_line.append(s2);
			startpos = pos + s1.length();
		}
		new_line.append(line, startpos, line.length() - startpos);
		ofs << new_line << std::endl;
	}
	ifs.close();
	ofs.close();
	return (0);
}