#pragma once

#include <cstdint>

BOOL APIENTRY DllMain(HMODULE, DWORD, LPVOID);

//!
//! \brief Attempt to connect to an Ultrasonix machine at the
//! specified IP address, and subsequently start a live
//! acquisition
//!
//! \return true if no machine is connected, and a connection
//! has been successfully established, and streaming started,
//! false otherwise
//!
_declspec (dllexport)
bool start_acquisition(const char *ip_address) noexcept;

//!
//! \brief Attempt to stop the current live acquisition
//!
//! \return true if a live acquisition was on and was
//! successfully stopped, or if no live acquisition was on,
//! false otherwise
//!
_declspec (dllexport)
bool stop_acquisition() noexcept;

//!
//! \brief Check whether a live acquisition is on
//!
//! \return true if a live acquisition is on, false
//! otherwise
//!
_declspec (dllexport)
bool is_acquiring() noexcept;

//!
//! \brief Copy current data on to passed memory, along
//! with the video frame dimensions, ultrasound image depth
//! and used frequency
//!
_declspec (dllexport)
bool get_data(
    uint8_t *data, uint32_t *width, uint32_t *height,
    uint32_t *depth, uint32_t *freq
) noexcept;
