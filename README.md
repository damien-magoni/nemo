nemo
====

The Network Mobilizer (nemo) is a mobility engine for emulating mobile networks.
It can generate or import connectivity scenarios for mobile networks. 
A connectivity scenario is a timestamped list of wireless link connexion and deconnexion events between mobile nodes. 
It works by issuing orders to NEmu (http://nemu.valab.net/) that in turn sends them to the vnd emulators. 
nemo is able to send these orders in real time which enables the emulation connectivity changes 
between mobile nodes by creating, destroying or changing the characteristics of the links at the appropriate time. 
It is implemented in C++ and uses some Boost libraries. 
The source code is available here under the LGPLv3, 
however, it is also included in NEmu and it is recommended to use NEmu for emulating virtual mobile networks.
If you use either nemo or NEmu for your research or educational work, 
please cite: Network Emulator: a Network Virtualization Testbed for Overlay Experimentations. 
Vincent Autefage, Damien Magoni. 
CAMAD'12 - IEEE International Workshop on Computer-Aided Modeling Analysis and 
Design of Communication Links and Networks, pp. 38-42, September 17-19, 2012, Barcelona, Spain.
