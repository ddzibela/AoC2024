#include <iostream>

#include "solution.hpp"

#include <regex>

namespace Day3
{


	int part1(const std::string& filename)
	{
		auto input = utils::read_file_content(filename);

		std::regex mulRegex(R"(mul\((\d+),(\d+)\))");
		auto rit = std::sregex_iterator(input.begin(), input.end(), mulRegex);
		auto rend = std::sregex_iterator();

		long result = 0;

		for (; rit != rend; rit++) {
			std::smatch match = *rit;
			int a = std::stoi(match[1].str());
			int b = std::stoi(match[2].str());
			result += a * b;
		}

		return result;
	}

	int part2(const std::string& filename)
	{
		auto input = utils::read_file_content(filename);

		std::regex mulRegex(R"((mul\((\d+),(\d+)\))|(do\(\))|(don't\(\)))");
		auto rit = std::sregex_iterator(input.begin(), input.end(), mulRegex);
		auto rend = std::sregex_iterator();

		long result = 0;
		bool work = true;
		//[1] is mul instruction [2] is a [3] is b [4] is do [5] is don't
		for (; rit != rend; rit++) {
			std::smatch match = *rit;
			if (match[1].matched && work) {
				int a = std::stoi(match[2].str());
				int b = std::stoi(match[3].str());
				result += a * b;
			}
			if (match[4].matched)
				work = true;
			if (match[5].matched)
				work = false;
		}

		return result;
	}
}
