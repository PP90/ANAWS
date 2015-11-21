//Simple application that set an IPv6 address to a mote and then it will be shown.

#include "contiki.h"
#include <stdio.h>//for printf function

//Libraries for IpV6 functions
#include "stuff.c"

#undef RF_CHANNEL
#define RF_CHANNEL //Set the radio frequency channel
#define HOW_MUCH_TIME 2
PROCESS(snd_process, "snd_process");
AUTOSTART_PROCESSES(&snd_process);
//print_address();
PROCESS_THREAD(snd_process, ev, data){
PROCESS_BEGIN();
set_address();
 send_udp_broadcast();
PROCESS_END();
}
