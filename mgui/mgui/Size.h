#pragma once
namespace mgui {
	template<class T>
	struct Size2D
	{
		T x, y;
		Size2D(T x = 0, T y = 0) :x(x), y(y) {}
	};

	using Size2Di = Size2D<int>;
	using Size2Df = Size2D<float>;
}


