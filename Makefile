CXX = g++
CXXFLAGS = -std=c++11 -I./headers
SRC_DIR = ./src
HEADERS_DIR = ./headers
OUTPUT_DIR = ./bin

# Create output directory if it doesn't exist
$(shell mkdir -p $(OUTPUT_DIR))

# Target executables
ISING1D = $(OUTPUT_DIR)/ising1d
ISING2D = $(OUTPUT_DIR)/ising2d
TEST_CASE = $(OUTPUT_DIR)/test_case

# Source files
ISING1D_SRC = main_1d.cpp $(SRC_DIR)/isingmodel.cpp $(SRC_DIR)/monte_carlo_sim_1d.cpp
ISING2D_SRC = main_2d.cpp $(SRC_DIR)/isingmodel2d.cpp $(SRC_DIR)/monte_carlo_sim_2d.cpp
TEST_CASE_SRC = test_case.cpp $(SRC_DIR)/isingmodel.cpp

# Default target
all: $(ISING1D) $(ISING2D) $(TEST_CASE)

# Compile targets
$(ISING1D): $(ISING1D_SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(ISING2D): $(ISING2D_SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(TEST_CASE): $(TEST_CASE_SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Run all programs and Python scripts
run: all
	@echo "Running ising1d..."
	@./$(ISING1D)
	@echo "Running ising2d..."
	@./$(ISING2D)
	@echo "Running test_case..."
	@./$(TEST_CASE)
	@echo "Running Python scripts..."
	python3 plot_ising_1d.py
	python3 plot_ising_2d.py

# Clean compiled files
clean:
	rm -rf $(OUTPUT_DIR)/*.o $(OUTPUT_DIR)/ising1d $(OUTPUT_DIR)/ising2d $(OUTPUT_DIR)/test_case

.PHONY: all clean run
