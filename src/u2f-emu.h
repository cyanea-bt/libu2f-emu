#ifndef U2F_EMU
#define U2F_EMU

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "u2f-emu-types.h"


/**
** \brief Get the error description specific to a return code.
**
** \param rc The return code.
** \return The respective error description.
*/
const char *u2f_emu_strerror(u2f_emu_rc rc);

/**
** \brief Instantiate a new U2F virtual emulated device.
**
** \param vdev_ref The virtual device reference.
** \param transport The transport of the virtual device.
** \return Success: U2F_EMU_OK.
**         Failure: - memory allocation: U2F_EMU_MEMORY_ERROR.
**                  - not supported: U2F_EMU_SUPPORTED_ERROR.
*/
u2f_emu_rc u2f_emu_vdev_new(u2f_emu_vdev **vdev_ref,
        u2f_emu_transport transport);

/**
** \brief Set the apdu length of an U2F virtual emultated device.
**
** \param vdev The virtual device.
** \param apdu The apdu length.
** \return Success: U2F_EMU_OK.
**         Failure: not allowed: U2F_EMU_PERMISSION_ERROR
*/
u2f_emu_rc u2f_emu_vdev_set_apdu(u2f_emu_vdev *vdev,
        u2f_emu_apdu apdu);

/**
** \brief Free an U2F virtual emulated device.
**
** \param vdev The virtual device.
*/
void u2f_emu_vdev_free(u2f_emu_vdev *vdev);

/**
** \brief Ask an U2F virtual emulated device to process input data.
**
** \param vdev The virtual device.
** \param data The input data to process.
** \param size The size of the input data in bytes.
** \return Success: U2F_EMU_OK.
**         Failure: - transport does not exist, or is not
**                    implemented: U2F_EMU_SUPPORTED_ERROR:.
*/
u2f_emu_rc u2f_emu_vdev_process(u2f_emu_vdev *vdev,
        const void *data, size_t size);

/**
** \brief Check if an U2F virtual emulated device has response data
**        To previous processed data.
**
** \param vdev The virtual device pointer.
** \return Has response: true.
**         Has not response: false.
*/
bool u2f_emu_vdev_has_response(u2f_emu_vdev *vdev);

/**
** \brief Get a response from an U2F virtual emulated device.
**
** \param vdev The virtual device pointer.
** \param data The data ref buffer to put the response.
** \return The size of the allocated data.
*/
size_t u2f_emu_vdev_get_response(u2f_emu_vdev *vdev, uint8_t **data);

#endif