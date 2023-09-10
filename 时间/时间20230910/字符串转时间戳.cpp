#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

int main() {
	std::string strTime = "2023-09-10 15:30:00";

	std::tm tm = {};
	std::istringstream ss(strTime);
	ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");

	auto timestamp = std::chrono::system_clock::from_time_t(std::mktime(&tm));

	std::cout << "字符串时间: " << strTime << std::endl;
	std::cout << "时间戳: " << std::chrono::system_clock::to_time_t(timestamp) << std::endl;

	return 0;
}