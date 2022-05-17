#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\cherk\source\repos\Dijkstra\Dijkstra\Source.cpp"
#include "C:\Users\cherk\source\repos\Dijkstra\Dijkstra\AdjList.h"
#include "C:\Users\cherk\source\repos\Dijkstra\Dijkstra\AdjList.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DijkstraTests
{
	TEST_CLASS(DijkstraTests)
	{
	public:
		
		TEST_METHOD(separateTest)
		{
			std::string temp = "Saint-Petersburg;Moscow;10;20", cityA, cityB, there, back;
			separate(cityA, cityB, there, back, temp);
			Assert::IsTrue(cityA == "Saint-Petersburg" && cityB == "Moscow" && there == "10" && back == "20");
		}

		TEST_METHOD(ParseTextTest)
		{
			text.push_back("Saint-Petersburg;Moscow;10;20");
			text.push_back("Moscow;Khabarovsk;40;35");
			text.push_back("Saint-Petersburg;Khabarovsk;14;N/A");
			text.push_back("Vladivostok;Khabarovsk;13;8");
			text.push_back("Vladivostok;Saint-Petersburg;N/A;20");
			parseText();
			std::string Khab = "Khabarovsk", Msk = "Moscow", Sp = "Saint-Petersburg", Vlad = "Vladivostok";
			Assert::IsTrue(arr[Khab][Msk] == 35 && arr[Khab][Vlad] == 8 && arr[Msk][Khab] == 40 && arr[Msk][Sp] == 20 && 
				arr[Sp][Khab] == 14 && arr[Sp][Msk] == 10 && arr[Sp][Vlad] == 20 && arr[Vlad][Khab] == 13);
		}

		TEST_METHOD(PriceCounterTest)
		{
			text.push_back("Saint-Petersburg;Moscow;10;20");
			text.push_back("Moscow;Khabarovsk;40;35");
			text.push_back("Saint-Petersburg;Khabarovsk;14;N/A");
			text.push_back("Vladivostok;Khabarovsk;13;8");
			text.push_back("Vladivostok;Saint-Petersburg;N/A;20");
			parseText();
			start = "Moscow", finish = "Khabarovsk";
			priceCounter();
			Assert::IsTrue(d["Khabarovsk"] == 34 && d["Moscow"] == 0 && d["Saint-Petersburg"] == 20 && d["Vladivostok"] == 40);
			Assert::IsTrue(p["Khabarovsk"] == "Saint-Petersburg" && p["Moscow"] == "Moscow" && p["Saint-Petersburg"] == "Moscow"
				               && p["Vladivostok"] == "Saint-Petersburg");
		}
	};
}
