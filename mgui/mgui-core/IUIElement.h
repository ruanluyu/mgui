#pragma once

#include "geo.h"
using namespace mgui::geo;

namespace mgui {

	template<class T>
	struct LayoutPreference2D {
		T min_dx, min_dy;
		T prefer_dx, prefer_dy;
		float ratio_dx, ratio_dy;
		bool ignore;
	};

	class IUIElement {
	public:
		virtual void RenderAsBackground(const Position2Dpx& query) = 0;


		
		virtual LayoutPreference2Di ReportLayoutPreference() = 0;
	};
}