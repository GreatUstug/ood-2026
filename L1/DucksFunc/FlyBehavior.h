//
// Created by maxim on 11.09.2026.
//

#ifndef DUCKSFUNC_FLY_H
#define DUCKSFUNC_FLY_H
#include <functional>
#include <iostream>

namespace Fly
{
inline std::function<void()> WithWings()
{
	return []() mutable {
		std::cout << "I'm flying with wings!!\n";
	};
}

inline std::function<void()> NoWay()
{
	return []() {
	};
}
}

#endif //DUCKSFUNC_FLY_H