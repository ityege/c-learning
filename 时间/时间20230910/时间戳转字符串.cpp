#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <chrono>
#include <ctime>

int main() {
	// 获取当前时间戳
	auto now = std::chrono::system_clock::now();
	std::time_t timestamp = std::chrono::system_clock::to_time_t(now);

	// 将时间戳转换为字符串
	char buffer[80];
	std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&timestamp));
	std::string strTime = buffer;

	std::cout << "时间戳: " << timestamp << std::endl;
	std::cout << "字符串时间: " << strTime << std::endl;

	return 0;
}