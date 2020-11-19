
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>


void saveAsText(const std::string filename, std::string& content) {
	
	std::string path_tosave = "resources/";
	const char *file_ending = ".txt";
	std::string f = path_tosave + filename + file_ending;
			
	std::ofstream myfile;
	myfile.open(f);
	
	if (myfile.is_open()){
		myfile << content;
		myfile.close();
	}
	else {
		std::cout << "Unable to open file";
		return;
	}
	
	std::cout << "Data will be saved to " << filename << std::endl;
}

std::string loadFromFile(const std::string filename) {
	
	std::string path = "resources/";
	//std::string a = filename;
	const char *b = ".txt";
	std::string f = path + filename + b;
	
	std::string output;
	std::ostringstream oss;
	std::ifstream myfile(f);
	
	if(myfile.is_open()) {
		oss << myfile.rdbuf();
		output = oss.str();
		myfile.close();
	} else {
		std::cout << "Unable to open file" << std::endl;
		output = "";
	}
	
	return output;
	
	/*
	std::ifstream myfile(filename);
	std::string line;
	if (myfile.is_open())
	{
		while ( getline (myfile, line) )
		{
			std::cout << line << '\n';
		}
		myfile.close();
	}
	else {
		std::cout << "Unable to open file"; 
		return 0;
	}
	
	std::cout << "Data is loaded from " << filename << std::endl;
	return 1;
	*/
}