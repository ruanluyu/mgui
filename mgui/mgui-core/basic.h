#pragma once

#include "fpm/fixed.hpp"  // For fpm::fixed_16_16
#include "fpm/math.hpp"   // For fpm::cos
#include "fpm/ios.hpp"    // For fpm::operator<<

#include <memory>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <sstream>

#include "uuid.h"
#include "geo.h"
#include "screen.h"
#include "logger.h"

namespace mgui {
	template<typename T>
	using sptr = std::shared_ptr<T>;
	
	template<typename T>
	using wptr = std::weak_ptr<T>;

}