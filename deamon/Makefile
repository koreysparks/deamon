
PROJECT = deamon_exe
AUTHOR = bsmith
PREFIX = /usr/local
HOME = .
DEAMON_LGS='deamon_lgs'
DEAMON_HDS='deamon_hds'
DEAMON_EQS='deamon_eqs'
DEAMON_OT='deamon_kiwi_ot'
DEAMON_BK='deamon_bk'
DEAMON_RS='deamon_rs'
# =================================


# ==============bin===================
LINK = $(PROJECT)
TARGET = $(PROJECT)
# ===================================


# ===============header====================
HEADERS = $(PROJECT)*.hpp
# ========================================


# ===============config====================
CC = g++

#CFLAGS = -Wall -D_DEBUG -DLANCE_LINUX
CFLAGS = -Wall -g -ggdb3  -fPIC  -DLANCE_LINUX
LFLAGS = -lpthread \
	-lrt	\
	-ldl 	\
	-L$(BASE) -lbase \
	$(COMMON_LIBS)/shengli_xml.a \
	$(COMMON_LIBS)/shengli_tool.a 

OBJS = \
	 deamon.o
				
IMPORTS = \
# ========================================


# ==================compile====================
%.o : %.cpp
	$(CC) -c $(CFLAGS) $< -o $@
	
all : bin
	
	-$(shell mkdir $(DEAMON_LGS) -p;     cp deamon_exe $(DEAMON_LGS)/$(DEAMON_LGS) -rf;  cp deamon.xml $(DEAMON_LGS)/deamon.xml)
	-$(shell mkdir $(DEAMON_HDS) -p;     cp deamon_exe $(DEAMON_HDS)/$(DEAMON_HDS) -rf;  cp deamon.xml $(DEAMON_HDS)/deamon.xml)
	-$(shell mkdir $(DEAMON_EQS) -p;     cp deamon_exe $(DEAMON_EQS)/$(DEAMON_EQS) -rf;  cp deamon.xml $(DEAMON_EQS)/deamon.xml)
	-$(shell mkdir $(DEAMON_OT) -p; 	 cp deamon_exe $(DEAMON_OT)/$(DEAMON_OT) -rf;  	 cp deamon.xml $(DEAMON_OT)/deamon.xml)
	-$(shell mkdir $(DEAMON_BK) -p;      cp deamon_exe $(DEAMON_BK)/$(DEAMON_BK) -rf;    cp deamon.xml $(DEAMON_BK)/deamon.xml)
	-$(shell mkdir $(DEAMON_RS) -p;      cp deamon_exe $(DEAMON_RS)/$(DEAMON_RS) -rf;    cp deamon.xml $(DEAMON_RS)/deamon.xml)

bin : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LFLAGS) $(IMPORTS)
	
install : $(TARGET)
		@cp $(TARGET) $(HOME)/bin/
		@ln -s $(HOME)/bin/$(TARGET) $(HOME)/bin/$(LINK)
		
clean:
	@rm -f $(OBJS)
	@rm -f $(TARGET)
	@rm -f $(HOME)/bin/$(TARGET)
	@rm -f $(HOME)/bin/$(LINK)
	@rm -rf *deamon_* 
	














