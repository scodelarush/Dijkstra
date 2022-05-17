#pragma once
#include <map>
#include <iostream>
#include <string>

using namespace std;

class AdjList
{
	map<string, map<string, int>> g;

public:
	map<string, int>& operator[](string key);
	bool exist(string key);
	bool exist(string key1, string key2);
	void insert(string key1, string key2, int data);
};

