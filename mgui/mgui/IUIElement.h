#pragma once

#include "Rectangle.h"

namespace mgui {

	template<class T>
	struct LayoutPreference2D {
		T min_dx, min_dy;
		T prefer_dx, prefer_dy;
		float ratio_dx, ratio_dy;
		bool ignore;
	};
	using LayoutPreference2Di = LayoutPreference2D<int>;
	using LayoutPreference2Df = LayoutPreference2D<float>;

	class IUIElement {
	public:
		virtual Rectangle2Di ReportRequiredAreaForRender(const Rectangle2Di& query) = 0;


		
		virtual LayoutPreference2Di ReportLayoutPreference() = 0;
	};
}