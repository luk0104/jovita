SRCS = jovita.cpp parser.cpp opcode.cpp cpu.cpp

#TEST_SRCS = test_opcode.cpp

SRCS += $(TEST_SRCS)

CXX = g++
CXXFLAGS = -O0 -ggdb
LDFLAGS = -lreadline
TARGET = jovita

OBJS = $(SRCS:.cpp=.o)

.SUFFIXES: .cpp .o

.cpp.o:
	$(CXX) -c $(CXXFLAGS) -o $@ $<

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $(OBJS)

clean:
	rm -f $(OBJS) $(TARGET)
