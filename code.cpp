// bulls and cows.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <set>
#include <time.h>
#include <vector>

std::vector<int> request(std::set<std::vector<int>> Set)
{
	std::set<std::vector<int>>::iterator it = Set.begin();
	std::advance(it, rand() % Set.size());
	return *it;
}


void resheto(int bk, int kr, std::vector<int> answer, std::set<std::vector<int>>& Set) 
{
	//std::vector<std::set<std::vector<int>>::iterator> deletes;
	std::vector<std::vector<int>> deletes;

	for (auto& V : Set)
	{
		//check bk
		int count = 0;
		for (size_t i = 0; i < V.size(); i++)
		{
			if (answer[i] == V[i]) count++;
		}
		if (count != bk) 
		{
			//Set.erase(Set.find(V));
			deletes.push_back(V);
			continue;
		}

		

		count = 0;
		for (size_t i = 0; i < V.size(); i++)
		{
			for (size_t j = 0; j < V.size(); j++) 
			{
				if (answer[i] == V[j]) count++;
			}
		}
		if (count - bk != kr) 
		{
			deletes.push_back(V);
			continue;
		}		
	}

	for (auto& i : deletes)
	{
		Set.erase(Set.find(i));
	}
}

int main()
{
	srand(time(0));
	std::set<std::vector<int>> Set;
	std::string temp;
	for (int i = 0; i < 10; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			if (i == j)continue;
			std::vector<int> V;
			V.push_back(i);
			V.push_back(j);
			Set.insert(V);
		}
	}

	std::cout << "Poigraem?\n";
	int bk, kr;
	std::vector<int> answer;
	while (true)
	{
		answer = request(Set);
		std::cout << answer[0] << answer[1] << std::endl;
		std::cin >> bk >> kr;
		if (bk == 4 && kr == 0) break;
		resheto(bk, kr, answer, Set);
	}
	std::cout << "Ti proigral!\n";
}

