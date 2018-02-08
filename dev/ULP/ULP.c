/* ULP radio driver */
#include "net/netstack.h"
#include "net/packetbuf.h"
#include "net/rime/rimestats.h"
#include "dev/watchdog.h"

#include "dev/leds.h"

#include <string.h>
#include <stdio.h>

/*---------------------------------------------------------------------------*/
/* Prototypes for Netstack API radio driver functions */
/*---------------------------------------------------------------------------*/
/* Init the radio. */
static int
init(void);
/* Prepare the radio with a packet to be sent. */
static int
prepare(const void *payload, unsigned short payload_len);
/* Send the packet that has previously been prepared. */
static int
transmit(unsigned short payload_len);
/* Prepare & transmit a packet. */
static int
send(const void *payload, unsigned short payload_len);
/* Read a received packet into a buffer. */
static int
read(void *buf, unsigned short bufsize);
/*
 * Perform a Clear-Channel Assessment (CCA) to find out if there is
 * a packet in the air or not.
 */
static int
channel_clear(void);
/* Check if the radio driver is currently receiving a packet. */
static int
receiving_packet(void);
/* Check if the radio driver has just received a packet. */
static int
pending_packet(void);
/* Turn the radio on. */
static int
on(void);
/* Turn the radio off. */
static int
off(void);
/* Get a radio parameter value. */
static radio_result_t
get_value(radio_param_t param, radio_value_t *value);
/* Set a radio parameter value. */
static radio_result_t
set_value(radio_param_t param, radio_value_t value);
/* Get a radio parameter object. */
static radio_result_t
get_object(radio_param_t param, void *dest, size_t size);
/* Set a radio parameter object. */
static radio_result_t
set_object(radio_param_t param, const void *src, size_t size);
/*---------------------------------------------------------------------------*/
/* The radio driver exported to contiki */
/*---------------------------------------------------------------------------*/
const struct radio_driver ULP_driver = {
  init,
  prepare,
  transmit,
  send,
  read,
  channel_clear,
  receiving_packet,
  pending_packet,
  on,
  off,
  get_value,
  set_value,
  get_object,
  set_object
};

static int
on(void)
{
}
static int
off(void)
{
}
static int
send(const void *payload, unsigned short payload_len)
{
	encrypting

	print (encrypt)
	modem out (SPI, ...)

}
static int
read(void *buf, unsigned short buf_len)
{
	mode input (SPI, ...)

	decrypting
	print (decrypt)
	write to buf

}
static int
channel_clear(void)
{

	will be updated after meeting with chip part

	return 1;

}
