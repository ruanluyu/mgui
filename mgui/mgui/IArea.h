#pragma once

#include "Point.h"

namespace mgui {
	template<class PointT>
	class IArea2D {
	public:
		virtual float Contains(const PointT& p) const = 0;
	};

	using IArea2Di = IArea2D<Point2Di>;
	using IArea2Df = IArea2D<Point2Df>;

}