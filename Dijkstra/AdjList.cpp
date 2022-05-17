#include "AdjList.h"
using namespace std;

map<string, int>& AdjList::operator[](string key)
{
	return g[key];
}

bool AdjList::exist(string key)
{
	return g.find(key) != g.end();
}

bool AdjList::exist(string key1, string key2)
{
	if (!exist(key1))return false;
	else return g[key1].find(key2) != g[key1].end();
}

void AdjList::insert(string key1, string key2, int data)
{
	if (exist(key1)) g[key1].insert({ key2,data });
	else {
		map<string, int> temp;
		temp.insert({ key2,data });
		g.insert({ key1,temp });
	}
}




