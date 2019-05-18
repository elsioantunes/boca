// Helper macros for the C++ Standard Library high resolution timer using
// std::chrono::high_resolution_clock, which represents the clock with the
// smallest tick period provided by the implementation.
// The clock is not guaranteed to be steady, though. Check the
// std::chrono::high_resolution_clock::is_steady flag to be sure.
//
// Requires C++ 11 Standard Library
// Qt: Add CONFIG += c++11 to project file
// Makefile: Use CXXFLAGS = -std=c++11
// Command line: g++ -std=c++11 -o <output> <input>
//
// Author: Harlen C Batagelo
// License: Creative Commons Attribution 3.0 Unported License
//          http://creativecommons.org/licenses/by/3.0/deed.en_US

#ifndef TIMING_H
#define TIMING_H

#include <chrono>

// Example:
// time_point ts = time_now(); // Get start time
// ... // Your stuff goes here
// time_point te = time_now(); // Get end time
// auto duration = itime_ns(te - ts); // Time diff in ns

typedef std::chrono::high_resolution_clock::time_point time_point;
#define time_now() std::chrono::high_resolution_clock::now()

// Time as a double
#define dtime_ns(x) std::chrono::duration<double, std::nano>(x).count()
#define dtime_us(x) std::chrono::duration<double, std::micro>(x).count()
#define dtime_ms(x) std::chrono::duration<double, std::milli>(x).count()
#define dtime_s(x) std::chrono::duration<double>(x).count()
#define dtime_min(x) std::chrono::duration<double, std::ratio<60>>(x).count()
#define dtime_h(x) std::chrono::duration<double, std::ratio<3600>>(x).count()

// Time truncated to an integer
#define itime_ns(x) std::chrono::duration_cast<std::chrono::nanoseconds>(x).count()
#define itime_us(x) std::chrono::duration_cast<std::chrono::microseconds>(x).count()
#define itime_ms(x) std::chrono::duration_cast<std::chrono::milliseconds>(x).count()
#define itime_s(x) std::chrono::duration_cast<std::chrono::seconds>(x).count()
#define itime_min(x) std::chrono::duration_cast<std::chrono::minutes>(x).count()
#define itime_h(x) std::chrono::duration_cast<std::chrono::hours>(x).count()

#endif // TIMING_H
