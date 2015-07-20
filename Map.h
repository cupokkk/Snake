#ifndef _MAP_H_
#define _MAP_H_
#include <SFML\Graphics.hpp>
#include <vector>
using std::vector;
//Только один экземпляр может существовать. мб синглтон?
class Map
{
public:
	Map();
	Map(int h, int w);
	Map(const Map &);
	~Map();
private:
	//????
};
#endif