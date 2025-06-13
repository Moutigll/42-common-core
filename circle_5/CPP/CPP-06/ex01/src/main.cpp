/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 09:46:20 by ele-lean          #+#    #+#             */
/*   Updated: 2025/06/13 09:47:15 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Serializer.hpp"

int	main(void) {
	Data		data;

	data.id = 42;
	data.name = "hello world";

	uintptr_t	raw = Serializer::serialize(&data);
	Data*		ptr = Serializer::deserialize(raw);

	std::cout << "Original pointer : " << &data << "\n";
	std::cout << "Deserialized ptr : " << ptr << "\n";
	std::cout << "ID: " << ptr->id << ", Name: " << ptr->name << "\n";

	if (ptr == &data)
		std::cout << "✅ Same address, success\n";
	else
		std::cout << "❌ Different pointer, fail\n";

	return 0;
}
