#pragma once

//!
//! \brief Callback function indicating new frame data is
//! is available
//!
bool new_frame_arrived(void* data, int type, int sz, bool cine, int frmnum);

//!
//! \brief Do nothing with the new frame. This is
//! to be called before stopping the acquisition, such
//! that the Ulterius thread stops trying to access the
//! global buffer
//!
bool ignore_new_frame(void* data, int type, int sz, bool cine, int frmnum);

//!
//! \brief Callback function indicating device settings
//! have changed
//!
bool params_changed(void* paramID, int ptX, int ptY);

//!
//! \brief Do nothing with the new params. This is
//! to be called before stopping the acquisition, such
//! that the Ulterius thread stops trying to access the
//! global buffer
//!
bool ignore_new_params(void* paramID, int ptX, int ptY);
