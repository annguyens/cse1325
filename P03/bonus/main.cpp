#include "color.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <time.h>

void fillVector(std::vector<Color>& vect)
{
	srand(time(NULL));
	int r{0},g{0},b{0},i;
	
	for(i=0;i<13;i++)
	{
		r = (rand() % 255)+1; 
		g = (rand() % 255)+1; 
		b = (rand() % 255)+1;
		
		Color color{r,g,b};
		vect.push_back(color);
	}
	return;
}

int main() {
	std::vector<Color> color;
	int i;
	fillVector(color);
	std::sort(color.begin(),color.end());
	
	for(i=0;i<color.size();i++)
	{
		std::cout << color[i] << color[i].to_string() << '\n';
	}
}


