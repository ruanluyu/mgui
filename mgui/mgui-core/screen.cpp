#include "pch.h"
#include "screen.h"

namespace mgui {

	namespace screen {

		static int _pixels_per_point = 2;

		int get_pixels_per_point()
		{
			return _pixels_per_point;
		}
		void set_pixels_per_point(int pixels_per_point)
		{
			_pixels_per_point = pixels_per_point;
		}
		

		pixel_loc_type point_to_pixel(const point_loc_type& v, quantization_mode mode)
		{
			switch (mode)
			{
			case mgui::screen::Q_FLOOR:
				return pixel_loc_type(floor(v * _pixels_per_point * subpixels_per_pixel) / subpixels_per_pixel);
				break;
			case mgui::screen::Q_ROUND:
				return pixel_loc_type(round(v * _pixels_per_point * subpixels_per_pixel) / subpixels_per_pixel);
				break;
			case mgui::screen::Q_CEIL:
				return pixel_loc_type(ceil(v * _pixels_per_point * subpixels_per_pixel) / subpixels_per_pixel);
				break;
			default:
				break;
			}
			return point_to_pixel(v, Q_ROUND);
		}

		point_loc_type pixel_to_point(const pixel_loc_type& v)
		{
			return ((double)(v)) / _pixels_per_point;
		}

	}

}
