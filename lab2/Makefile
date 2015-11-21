CONTIKI_PROJECT = snd_broadcast_UDP ipv6_addr_lib rcv_UDP unicast_snd
all:$(CONTIKI_PROJECT)

CONTIKI = /home/user/contiki##It is the default folder of contiki

##Enabling the IPv6 in the make file
WITH_UIP=1
UIP_CONF_IPV6=1
CFLAG+= -DUIP_CONF_IPV6=1 -DWITH_UIP6=1

include $(CONTIKI)/Makefile.include
