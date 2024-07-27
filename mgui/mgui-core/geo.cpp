#include "pch.h"
#include "geo.h"

namespace mgui {
	namespace geo {
		namespace utils {
			Rectangle2Dpx ExpandRectangle(const Rectangle2Dpt rectPt)
			{
				rectPt.minX();

				return Rectangle2Dpx();
			}

			Rectangle2Dpx ShrinkRectangle(const Rectangle2Dpt rectPt)
			{
				return Rectangle2Dpx();
			}
		}
	}
}


