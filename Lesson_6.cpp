//Написать программу, которая создаст два текстовых файла, примерно по 50 - 100 символов в каждом(особого значения не имеет);
//Написать функцию, «склеивающую» эти файлы, предварительно буферизуя их содержимое в динамически выделенный сегмент памяти нужного размера.
//* Написать программу, которая проверяет присутствует ли указанное пользователем при запуске программы слово в указанном пользователем файле(для простоты работаем только с латиницей).


#include <iostream>
#include <string>
#include <fstream>

int main() {

	//	1
	std::string path1 = "file1.txt", path2 = "file2.txt";
	std::ofstream file1, file2;
	
	std::string text1 = "C++ is a general-purpose programming language created by Bjarne Stroustrup as an extension of the C programming language, or C with Classes.";
	std::string text2 = "The language has expanded significantly over time, and modern C++ now has object-oriented, generic, and functional features in addition to facilities for low-level memory manipulation";

	file1.open(path1, std::fstream::in | std::fstream::out | std::fstream::app);
	file2.open(path2, std::fstream::in | std::fstream::out | std::fstream::app);
	if (!file1.is_open() || !file2.is_open()) {
		std::cout << "error" << std::endl;
	}
	else {
		std::cout << "success" << std::endl;
		file1 << text1;
		file2 << text2;
	}

	//	2

	std::string* memory1;
	std::string* memory2;
	memory1 = new std::string(text1);
	memory2 = new std::string(text2);
	if (!memory1 || !memory2) {
		std::cout << "memory error" << std::endl;
	}
	else {
		file1 << std::endl << "new file begins here:" << std::endl << memory2;
	}


	file1.close();
	file2.close();

	return 0;
}