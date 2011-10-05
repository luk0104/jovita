SRCS = jovita.cpp parser.cpp opcode.cpp

CXX = g++
CXXFLAGS = -O0 -ggdb
LDFLAGS = -lreadline
TARGET = jovita

OBJS = $(SRCS:.cpp=.o)

.SUFFIXES: .cpp .o

.cpp.o:
	$(CXX) -c $(CXXFLAGS) -o $@ $<

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $<

clean:
	rm -f $(OBJS) $(TARGET)
