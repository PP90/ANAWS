//Library that contains a lot of useful function. 
//Function list:
//Set an address
//Get an address

//Send packet with UDP (Broadcasting mode and not only)
//Receive packet with UPD (Possibile filtering)

#include "simple-udp.h"
#include "net/ip/uip.h"
#include "net/ipv6/uip-ds6.h"
#include "net/ip/uip-debug.h"
#include "simple-udp.h"
#include <stdio.h>
#define UDP_PORT 1234

static struct simple_udp_connection broadcast_connection;

//Function to set IPv6 address.
//It can be set either manually or automatically or statefully.
///To do: prefix and conf type have to be passed as parameteres
void set_address(){
uip_ipaddr_t ipaddr;
//First field is the prefix of my link local(?).The last field is what IPv6 adrress it is assigned to my device
uip_ip6addr(&ipaddr,0xaaaa, 0,0,0,0,0,0,0);
uip_ds6_set_addr_iid(&ipaddr, &uip_lladdr);//The IPv6 address is get from MAC address.
uip_ds6_addr_add(&ipaddr, 0, ADDR_AUTOCONF);
}

//UIP_DS6_ADDR_NB is the address list size. The size depends on number of unicast addresses.

void print_address(){
int i;
uint8_t state;
printf("IPv6 address: ");
for(i=0; i< UIP_DS6_ADDR_NB; i++){//capire perchè ho 2 indirizzi diversi
		printf("i=%d\n",i);
		state=uip_ds6_if.addr_list[i].state;
		if(state==0){//state=0 tentative
		printf("Address tentative:\n");
		uip_debug_ipaddr_print(&uip_ds6_if.addr_list[i].ipaddr);
		printf("\n");
		}
		if(state==1){//state=1 preferred
		printf("Address preferred:\n");
		uip_debug_ipaddr_print(&uip_ds6_if.addr_list[i].ipaddr);
		printf("\n");
		}
		if(state==2){//state=2 deprecated
		printf("Address deprecated:\n");
		uip_debug_ipaddr_print(&uip_ds6_if.addr_list[i].ipaddr);
		printf("\n");
		}
	
	if(uip_ds6_if.addr_list[i].isused){
		printf("The actual used address is:\n");
		uip_debug_ipaddr_print(&uip_ds6_if.addr_list[i].ipaddr);
		printf("\n");
		}
	}
}

static void 
        callback_function(struct simple_udp_connection *c,
        const uip_ipaddr_t *snd_addr,
        uint16_t snd_port,
        const uip_ipaddr_t *rcv_addr,
        uint16_t rcv_port,
        const uint8_t *data,
        uint16_t datalen){
        int i;
        printf("Sender addr: ");
        uip_debug_ipaddr_print(snd_addr);
        printf("\n");
        for(i=0; i<datalen; i++){
        printf("%c",data[i]);
        }
        printf("\n");
}
//The sender sends a broadcast message to all multicast link local nodes
void send_udp_broadcast(){
uip_ipaddr_t mcast_allnodes_address;
uip_create_linklocal_allnodes_mcast(&mcast_allnodes_address);
simple_udp_register(&broadcast_connection, UDP_PORT, NULL,UDP_PORT, callback_function);
simple_udp_sendto(&broadcast_connection, "Test", 4, (const uip_ipaddr_t*)&mcast_allnodes_address);
}

//The receiver when receives something from broadcast, call the callback function
void receive_udp_broadcast(){
simple_udp_register(&broadcast_connection, UDP_PORT, NULL, UDP_PORT, callback_function);
}

