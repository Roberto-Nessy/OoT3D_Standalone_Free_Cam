/**
 * @file apt.h
 * @brief APT (Applet) service.
 */
#pragma once

/**
 * @brief Sends an APT command through IPC, taking care of locking, opening and closing an APT session.
 * @param aptcmdbuf Pointer to command buffer (should have capacity for at least 16 words).
 */
Result aptSendCommand(u32* aptcmdbuf);

/**
 * @brief Checks whether the system is a New 3DS.
 * @param out Pointer to write the New 3DS flag to.
 */
Result APT_CheckNew3DS(bool* out);
