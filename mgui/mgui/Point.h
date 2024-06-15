#pragma once

namespace mgui {

	template<class T>
	struct Point2D {
		T x, y;
		Point2D(T x = 0, T y = 0):x(x), y(y){}
	};

	using Point2Di = Point2D<int>;
	using Point2Df = Point2D<float>;
}


