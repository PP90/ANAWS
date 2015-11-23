CONTIKI_PROJECT = rpl_root_node rpl_lib
all:$(CONTIKI_PROJECT)

CONTIKI = /home/user/contiki##Default contiki directory

##Enabling the IPv6 in the make file
WITH_UIP=1
UIP_CONF_IPV6=1
CFLAG+= -DUIP_CONF_IPV6=1 -DWITH_UIP6=1
CFLAG+= -DUIP_CONF_IPV6_RPL
CFLAG+= -DRPL_CONF_STATS=1

include $(CONTIKI)/Makefile.include
