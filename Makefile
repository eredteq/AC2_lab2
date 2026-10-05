CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
AR = ar
ARFLAGS = rcs

TARGET = Kolomiets_app
LIB_NAME = libcalculator.a

# Головна ціль
all: $(TARGET)

# Створення статичної бібліотеки
$(LIB_NAME): calculator.o
	$(AR) $(ARFLAGS) $@ $^

# Компіляція об'єктних файлів
calculator.o: calculator.cpp calculator.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

main.o: main.cpp calculator.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Збирання виконуваного файлу
$(TARGET): main.o $(LIB_NAME)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Очищення
clean:
	rm -f *.o *.a $(TARGET)