#ifndef U2F_EMU
#define U2F_EMU

#include "u2f-emu-types.h"


/**
** \brief Get the error description specific to a return code.
**
** \param rc The return code.
** \return The respective error description.
*/
const char *u2f_emu_strerror(u2f_emu_rc rc);

/**
** \brief Instantiate a new U2F virtual emultaed device.
**
** \param vdev Virtual device reference.
** \return Success: U2F_EMU_OK.
**         Failure: - memory allocation: U2F_EMU_MEMORY_ERROR.
**                  - not supported: U2F_EMU_SUPPORTED_ERROR
*/
u2f_emu_rc u2f_emu_vdev_new(u2f_emu_vdev **vdev,
        u2f_emu_transport transport);

/**
** \brief Set the apdu length of an U2F virtual emultaed device.
**
** \param vdev Virtual device pointer.
** \param apdu The apdu length
** \return Success: U2F_EMU_OK
**         Failure: not allowed: U2F_EMU_PERMISSION_ERROR
*/
u2f_emu_rc u2f_emu_vdev_set_apdu(u2f_emu_vdev *vdev_ref,
    u2f_emu_apdu apdu);

/**
** \brief Free an U2F virtual emultaed device.
**
** \param vdev Virtual device pointer
*/
void u2f_emu_vdev_free(u2f_emu_vdev *vdev);

#endif