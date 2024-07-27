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

	class UIElement {
	private:
		UIElement* parent;
	public:

		struct RenderBackgroundArguments {
			Rectangle2Dpx query_range;
			void* write_color_buffer;
		};

		virtual void RenderAsBackground(const RenderBackgroundArguments& arguments) = 0;
		
	};
}