#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Stock
{
	int Dates = 0;
	int Supplies = 0;
};

class Compare
{
public:
	bool operator()(Stock s1, Stock s2)
	{
		return s1.Supplies < s2.Supplies;
	}
};

priority_queue<Stock, vector<Stock>, Compare> PQ;

int Find(int Day)
{
	vector<Stock> TempList;

	int FindValue = 0;
	bool bFind = false;
	while (bFind == false)
	{
		Stock PopedStock = PQ.top();
		PQ.pop();

		if (PopedStock.Dates <= Day)
		{
			bFind = true;
			FindValue = PopedStock.Supplies;
		}
		else
		{
			TempList.push_back(PopedStock);
		}
	}

	for (int i = 0; i < TempList.size(); ++i)
	{
		PQ.push(TempList[i]);
	}

	return Day + FindValue;

}

int solution(int stock, vector<int> dates, vector<int> supplies, int k)
{
	int Result = 0;

	//@Insert
	for (int i = 0; i < dates.size(); ++i)
	{
		Stock InsertStock;
		InsertStock.Dates = dates[i];
		InsertStock.Supplies = supplies[i];
		PQ.push(InsertStock);
	}

	int Days = stock;
	while (Days < k)
	{
		Days = Find(Days);
		++Result;
	}

	return Result;
}

int main()
{
	int CurrentStock = 4;
	int k = 30;

	vector<int> dates;
	dates.push_back(4);
	dates.push_back(10);
	dates.push_back(15);

	vector<int> supplies;
	supplies.push_back(20);
	supplies.push_back(5);
	supplies.push_back(10);

	//vector<int> dates;
	//dates.push_back(1);
	//dates.push_back(2);
	//dates.push_back(3);
	//dates.push_back(4);

	//vector<int> supplies;
	//supplies.push_back(10);
	//supplies.push_back(40);
	//supplies.push_back(20);
	//supplies.push_back(30);


	int Result = solution(CurrentStock, dates, supplies, k);

	return 0;
}

