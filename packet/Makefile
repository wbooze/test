
#
# Makefile for Wavelet Packet code on UNIX (Live Free or Die!)
#
# This make file assumes that the GNU g++ compiler is available
#
# To run this make file (on UNIX) enter
#
#   make -f Makefile.unix
#
# Most recently tested using 
#
# g++ (GCC) 3.2.3 20030502 (Red Hat Linux 3.2.3-42)
#

DEBUG     = -g
BROWSE    =

GNU_FLAGS = -Wno-deprecated
CFLAGS    = $(BROWSE) $(DEBUG) -D_UNIX_ $(GNU_FLAGS)
OBJ       = o
#
# Specify the UNIX C++ compiler here
#
CC        = g++
# CC        = CC
# CC        = /usr/local/forte/SUNWspro/bin/CC
#

LOCALINC = include

INCLUDE = -I$(LOCALINC) 

PACKET_OBJ = blockpool.$(OBJ) packtree_base.$(OBJ) packtree.$(OBJ) packfreq.$(OBJ) costshannon.$(OBJ) invpacktree.$(OBJ) packtest.$(OBJ) 


all: $(PACKET_OBJ)
	$(CC) $(PACKET_OBJ) $(DEBUG) -o packet

#
# clean-up for Microsoft object and browser files and emacs temps
#
# It's totally wierd, clean stopped working...
clean:
#	rm *.obj *.pdb *.sbr *.exe
#	rm -f include/*~
#	rm -f src/*~


include/costbase.h: include/packnode.h

include/costshannon.h: include/costbase.h include/packnode.h

include/costthresh.h: include/costbase.h include/packnode.h

include/haar.h: include/liftbase.h

include/haar_classic.h: include/liftbase.h

include/line.h: include/liftbase.h

include/packdata.h: include/blockpool.h

include/invpacktree.h: include/packdata.h

include/packnode.h: include/packdata.h

include/packdata_list.h: include/fifo_list.h include/packdata.h

include/packcontainer.h: include/packnode.h

include/queue.h: include/fifo_list.h include/packnode.h

include/packtree.h: include/packnode.h include/packcontainer.h include/liftbase.h

include/invpacktree.h: include/liftbase.h include/list.h include/packcontainer.h include/packdata.h include/packdata_list.h

packtree_base.$(OBJ): include/queue.h include/packnode.h include/packcontainer.h include/packtree_base.h
	$(CC) -c $(INCLUDE) $(CFLAGS) src/$*.cpp

packtree.$(OBJ): include/queue.h include/packcontainer.h include/blockpool.h
	$(CC) -c $(INCLUDE) $(CFLAGS) src/$*.cpp

packfreq.$(OBJ): include/packfreq.h
	$(CC) -c $(INCLUDE) $(CFLAGS) src/$*.cpp

costshannon.$(OBJ): 
	$(CC) -c $(INCLUDE) $(CFLAGS) src/$*.cpp

packdata_list.$(OBJ): 
	$(CC) -c $(INCLUDE) $(CFLAGS) src/$*.cpp

invpacktree.$(OBJ): include/blockpool.h
	$(CC) -c $(INCLUDE) $(CFLAGS) src/$*.cpp

blockpool.$(OBJ): 
	$(CC) -c $(INCLUDE) $(CFLAGS) src/$*.cpp

local_new.$(OBJ): 
	$(CC) -c $(INCLUDE) $(CFLAGS) src/$*.cpp


packtest.$(OBJ): include/haar.h include/haar_classic.h include/packnode.h include/packcontainer.h include/packtree.h include/invpacktree.h include/costshannon.h include/costthresh.h
	$(CC) -c $(INCLUDE) $(CFLAGS) src/$*.cpp

%.o: src/%.cpp include/%.h

