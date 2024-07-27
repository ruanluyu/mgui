#include "pch.h"
#include "geo.h"

namespace mgui {
	namespace geo {
		namespace utils {
			Rectangle2Dpx ExpandRectangle(const Rectangle2Dpt rectPt)
			{
				return Rectangle2Dpx::FromMinMax(
					screen::quantize_point_to_pixel(rectPt.minX(), Q_FLOOR),
					screen::quantize_point_to_pixel(rectPt.minY(), Q_FLOOR),
					screen::quantize_point_to_pixel(rectPt.maxX(), Q_CEIL),
					screen::quantize_point_to_pixel(rectPt.maxY(), Q_CEIL)
				);
			}

			Rectangle2Dpx ShrinkRectangle(const Rectangle2Dpt rectPt)
			{
				return Rectangle2Dpx::FromMinMax(
					screen::quantize_point_to_pixel(rectPt.minX(), Q_CEIL),
					screen::quantize_point_to_pixel(rectPt.minY(), Q_CEIL),
					screen::quantize_point_to_pixel(rectPt.maxX(), Q_FLOOR),
					screen::quantize_point_to_pixel(rectPt.maxY(), Q_FLOOR)
				);
			}
		}
	}
}


