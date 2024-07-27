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
		

		PixelLocT quantize_point_to_pixel(const PointLocT& v, QuantizationMode mode)
		{
			switch (mode)
			{
			case mgui::screen::Q_FLOOR:
				return PixelLocT(floor(v * _pixels_per_point * subpixels_per_pixel) / subpixels_per_pixel);
				break;
			case mgui::screen::Q_ROUND:
				return PixelLocT(round(v * _pixels_per_point * subpixels_per_pixel) / subpixels_per_pixel);
				break;
			case mgui::screen::Q_CEIL:
				return PixelLocT(ceil(v * _pixels_per_point * subpixels_per_pixel) / subpixels_per_pixel);
				break;
			default:
				break;
			}
			return quantize_point_to_pixel(v, Q_ROUND);
		}

		PointLocT pixel_to_point(const PixelLocT& v)
		{
			return ((double)(v)) / _pixels_per_point;
		}

	}

}
