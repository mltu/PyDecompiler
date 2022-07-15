#pragma once
#include <iostream>
#include "color.hpp"

enum WriteEnum { Success, Failure, Info, Input };

void Write(std::string text, WriteEnum Enum) {
	if (Enum == Success) {
		std::cout << dye::grey("[") << dye::green("+") << dye::grey("] ") << dye::white(text) << std::endl;
	}

	else if (Enum == Failure) {
		std::cout << dye::grey("[") << dye::green("-") << dye::grey("] ") << dye::white(text) << std::endl;
	}

	else if (Enum == Info) {
		std::cout << dye::grey("[") << dye::yellow("~") << dye::grey("] ") << dye::white(text) << std::endl;
	}

	else if (Enum == Input) {
		std::cout << dye::grey("[") << dye::blue(">") << dye::grey("] ") << dye::white("");
	}
}
