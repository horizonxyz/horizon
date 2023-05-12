#pragma once
#ifndef HORIZON_PRECOMPILED_HEADERS
#define HORIZON_PRECOMPILED_HEADERS

#include <algorithm>
#include <chrono>
#include <queue>
#include <random>
#include <memory>
#include <mutex>
#include <utility>
#include <functional>
#include <set>
#include <cassert>
#include <cstdint>
#include <ctime>
#include <cstring>
#include <sstream>
#include <string>
#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <mutex>
#include <tuple>
#include <type_traits>
#include <atomic>
#include <stdint.h>

#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/asio/signal_set.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/multi_array.hpp>
#include <boost/asio/deadline_timer.hpp>
#include <boost/make_shared.hpp>
#include <boost/filesystem.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/thread.hpp>
#include <boost/filesystem.hpp>
#include <boost/bind/placeholders.hpp>

#include <mysqlx/xdevapi.h>

#ifndef SOL_ALL_SAFETIES_ON
#define SOL_ALL_SAFETIES_ON 1
#endif
#ifdef SOL_STD_VARIANT
#define SOL_STD_VARIANT 0
#endif
#include <sol/sol.hpp>

#include "Logging/Logger.hpp"

#include "Core/Multithreading/LockedLookupTable.hpp"
#include "Core/Multithreading/ThreadSafeQueue.hpp"

#include "Server/Common/Configuration/ServerConfiguration.hpp"
#include "Server/Common/Configuration/Horizon.hpp"

#include "Utility/TaskScheduler.hpp"

#endif /* HORIZON_PRECOMPILED_HEADERS */