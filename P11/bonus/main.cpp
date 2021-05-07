//An Nguyen
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include <map>

int main(int argc, char *argv[])
{
	std::ifstream ifs{argv[1]};
	if(!ifs) 
	{
		std::cerr << "ERROR: Invalid file name.\n";
		exit(EXIT_FAILURE);
	}
	std::map<std::string,int> words;
	std::string word;
	while(ifs >>word)
	{
		if(words.find(word)!=words.end())
		{
			words[word]++;
		}
		else
		{
			words.insert(std::pair<std::string,int>(word,1));
		}
	}
	ifs.close();
	for(auto const& v: words)
	{
		std::cout << std::left <<std::setw(15) << v.first 
	<< std::left << std::setw(15) << v.second << std::endl;
	}
	
	std::string border(25,'=');
	while(true)
	{
		std::cout << border
		<< "\nList words with which frequency? ";
		int freq;
		std::cin >> freq;
		if(freq==0) break;
		else {
			for(auto const& v: words)
			{
				if(v.second == freq)
				{
					std::cout << std::left <<std::setw(15) << v.first << std::left <<std::setw(15) << v.second <<"\n";
				}
			}
		}
		
	}
}

