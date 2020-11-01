
#include <iostream>
#include <fstream>
#include <string>

void saveAsText(const std::string filename) {
	
	std::ofstream myfile;
	myfile.open (filename);
	
	if (myfile.is_open()){
		myfile << "This is a line.\n";
		myfile << "This is another line.\n";
		myfile.close();
	}
	else {
		std::cout << "Unable to open file";
		return;
	}
	
	std::cout << "Text will be saved to " << filename << std::endl;
}

int loadFromFile(const std::string filename) {
	
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
	
}