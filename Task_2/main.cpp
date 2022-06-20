//https://contest.yandex.ru/contest/35212/run-report/65257123/

#include <iostream>
#include <algorithm>
#include <vector>

int findMaxHeightOfTower(std::vector<std::pair<int, int>>& athletes)
{
	std::sort(athletes.begin(), athletes.end());
	int height = 0;
	int cumulativeWeight = 0;
	for (const auto& athlete : athletes) {
		const int weight = athlete.first;
		const int strength = athlete.second;
		if (strength >= cumulativeWeight) {
			height++;
			cumulativeWeight += weight;
		}
	}
	return height;
}

int main()
{
	std::vector<std::pair<int, int>> athletes;
	int weight, strenght;
	while (std::cin >> weight >> strenght) {
		athletes.push_back({ weight, strenght });
		if (!std::cin)
			break;
	}

	std::cout << findMaxHeightOfTower(athletes);
	return 0;
}
