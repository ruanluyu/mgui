#pragma once
#include "pch.h"




namespace mgui {

	namespace screen {

		static const int pixel_fraction_bits = 2;
		static const int subpixels_per_pixel = 1 << pixel_fraction_bits;
		using PixelLocT = fpm::fixed<int32_t, int64_t, pixel_fraction_bits>;
		using PointLocT = double;

		int get_pixels_per_point();
		void set_pixels_per_point(int pixels_per_point);

		PointLocT pixel_to_point(PixelLocT);

		enum QuantizationMode {
			Q_FLOOR,
			Q_ROUND,
			Q_CEIL,
		};
		extern PixelLocT quantize_point_to_pixel(const PointLocT& v, QuantizationMode mode = Q_ROUND);
	}
	
}


