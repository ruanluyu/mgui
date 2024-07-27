#pragma once
#include "pch.h"




namespace mgui {

	namespace screen {

		static const int pixel_fraction_bits = 2;
		static const int subpixels_per_pixel = 1 << pixel_fraction_bits;
		using pixel_loc_type = fpm::fixed<int32_t, int64_t, pixel_fraction_bits>;
		using point_loc_type = double;

		int get_pixels_per_point();
		void set_pixels_per_point(int pixels_per_point);

		point_loc_type pixel_to_point(pixel_loc_type);

		enum quantization_mode {
			Q_FLOOR,
			Q_ROUND,
			Q_CEIL,
		};
		extern pixel_loc_type point_to_pixel(const point_loc_type& v, quantization_mode mode = Q_ROUND);
	}
	
}


