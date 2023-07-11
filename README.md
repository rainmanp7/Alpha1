# Alpha1 and Alpha2 Congestion Control Algorithms
THIS is Strictly ALPHA / BETA Testing...
The purpose is to create a congestion control so
that I can simply call it by sysctl configuration for
my network to improve multiple things. You want to helpp
implement this? Make it possible? Why not try it or help me make
this possible...

This repository contains two congestion control algorithms: Alpha1 and Alpha2.

Alpha1

The Alpha1 algorithm is a simple congestion control algorithm that adjusts the congestion window based on the packet loss rate. If the packet loss rate is high, then the congestion window is reduced. If the packet loss rate is low, then the congestion window is increased.

Alpha2

The Alpha2 algorithm is a more sophisticated congestion control algorithm that also takes into account the CPU usage. If the CPU usage is high, then the packet compression is disabled. This helps to reduce the load on the CPU and improve the overall performance of the network.

How to use

To use the Alpha1 or Alpha2 algorithms, you can simply call the adjust_congestion_window() function. This function takes two arguments: the congestion control object and the packet loss rate.

For example, the following code shows how to use the Alpha1 algorithm:

struct CongestionControl cc; int packet_loss_rate = 5;

adjust_congestion_window(&cc, packet_loss_rate);


// Future release I need this into the Linux kernal and
To be able to simply call it by sysctl to load up as
a functional algorithm because it has or should have
2 choices 
Alpha1 Congestion Control 
Alpha2 Congestion Control + Packet Compression
Alpha1 Congestion Control
