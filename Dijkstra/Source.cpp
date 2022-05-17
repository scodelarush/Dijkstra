#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <list>
#include <string>
#include <fstream>
#include "AdjList.h"

using namespace std;

string start, finish;
AdjList arr;
vector<string> route;
set<string> cities;
map<string, int> d;
map<string, string> p;
list<string> text;

void separate(string& cityA, string& cityB, string& there, string& back, string temp) { 
	int count = 1;
	for (int i = 0; i < temp.size(); i++) {
		if (temp[i] == ';') {
			count++;
			continue;
		}
		switch (count) {
		case 1:
			cityA += temp[i];
			break;
		case 2:
			cityB += temp[i];
			break;
		case 3:
			there += temp[i];
			break;
		case 4:
			back += temp[i];
			break;
		default:
			break;
		}
	}
}

void read(string path) { 
	ifstream input(path);
	if (!input.is_open()) {
		return;
	}
	while (!input.eof()) {
		string temp;
		getline(input, temp);
		text.push_back(temp);
	}
}

void parseText() { 
	while (text.size()) {
		string temp = text.front();
		text.pop_front();
		string cityA, cityB, there, back;
		separate(cityA, cityB, there, back, temp);
		cities.insert(cityA);
		cities.insert(cityB);

		if (there != "N/A") arr.insert(cityA, cityB, stoi(there));

		if (back != "N/A") arr.insert(cityB, cityA, stoi(back));
		
	}
}

void inputPlaces() {
	cout << "Enter start city\n";
	cin >> start;
	cout << "Enter finish city\n";
	cin >> finish;
}

void priceCounter() { 
	set<string> s;
	for (auto city : cities) {
		d.insert({ city,INT_MAX });
		p.insert({ city,city });
	}
	d[start] = 0;
	string cur = start;
	int c = 0;

	while (c != cities.size() - 1 && cur != finish) {
		s.insert(cur);
		pair <string, int> m;
		m.second = INT_MAX;
		for (auto x : d) {
			if (arr.exist(cur,x.first) && s.find(x.first) == s.end() && x.second > d[cur] + arr[cur][x.first]) {
				d[x.first] = d[cur] + arr[cur][x.first];
				p[x.first] = cur;
			}
			if (s.find(x.first) == s.end() && x.second < m.second) m = x;
		}
		c++;
		cur = m.first;
	}
}

void output() { 
	if (d[finish] == INT_MAX) {
		cout << "There is no way, that you are looking for\n";
		return;
	}
	cout << "Price is : " << d[finish] << '\n';
	cout << "Your route is : ";
	string cur = finish;
	vector <string> route;
	while (p[cur] != cur) {
		route.push_back(cur);
		cur = p[cur];
	}
	route.push_back(start);
	for (int i = route.size()-1; i > 0; i--)cout << route[i] << " ---> ";
	cout << route[0] << '\n';
}

int main() {
	read("info.txt");
	parseText();
	inputPlaces();
	priceCounter();
	output();
}