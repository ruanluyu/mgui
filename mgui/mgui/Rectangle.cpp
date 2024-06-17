#include "Rectangle.h"

#include "math.h"


mgui::Rectangle2Di mgui::RadialCeil(const Rectangle2Df& rect)
{
	return Rectangle2Di::FromMinMax(
		static_cast<int>(floorf(rect.minX())),
		static_cast<int>(floorf(rect.minY())),
		static_cast<int>(ceilf(rect.maxX())),
		static_cast<int>(ceilf(rect.maxY()))
	);
}

mgui::Rectangle2Di mgui::RadialFloor(const Rectangle2Df& rect)
{
	return Rectangle2Di::FromMinMax(
		static_cast<int>(ceilf(rect.minX())),
		static_cast<int>(ceilf(rect.minY())),
		static_cast<int>(floorf(rect.maxX())),
		static_cast<int>(floorf(rect.maxY()))
	);
}