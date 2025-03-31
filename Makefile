# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11

# Executable names
EXEC1 = ising1d
EXEC2 = ising2d
EXEC3 = test_case

# Source files for each executable
SRC1 = main_1d.cpp isingmodel.cpp monte_carlo_sim_1d.cpp
SRC2 = main_2d.cpp isingmodel2d.cpp monte_carlo_sim_2d.cpp
SRC3 = test_case.cpp isingmodel.cpp

# Default target
all: $(EXEC1) $(EXEC2) $(EXEC3) run_python

# Compile and build executables
$(EXEC1): $(SRC1)
	$(CXX) $(CXXFLAGS) -o $(EXEC1) $(SRC1)

$(EXEC2): $(SRC2)
	$(CXX) $(CXXFLAGS) -o $(EXEC2) $(SRC2)

$(EXEC3): $(SRC3)
	$(CXX) $(CXXFLAGS) -o $(EXEC3) $(SRC3)

# Run all executables and python scripts
run: $(EXEC1) $(EXEC2) $(EXEC3)
	./$(EXEC1)
	./$(EXEC2)
	./$(EXEC3)
	python3 plot_ising_1d.py
	python3 plot_ising_2d.py

# Separate Python scripts execution target
run_python:
	python3 plot_ising_1d.py
	python3 plot_ising_2d.py

# Clean up compiled files
clean:
	rm -f $(EXEC1) $(EXEC2) $(EXEC3)
