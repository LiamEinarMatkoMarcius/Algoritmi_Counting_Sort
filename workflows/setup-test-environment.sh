#!/bin/bash
# filepath: c:\Users\liame\Desktop\Faks\Letnik_2.2\SISTEMSKA_ADMINISTRACIJA\Git\Algoritmi_Counting_Sort\setup-test-environment.sh

echo "Setting up the test environment..."

# Install Python dependencies
if [ -f requirements.txt ]; then
    echo "Installing Python dependencies..."
    pip install -r requirements.txt
else
    echo "No requirements.txt found. Skipping Python dependency installation."
fi

# Compile the C++ code
if [ -f Counting_roman:sort.cpp ]; then
    echo "Compiling Counting_roman:sort.cpp..."
    g++ -o counting_sort Counting_roman:sort.cpp
else
    echo "C++ source file not found! Exiting."
    exit 1
fi

echo "Test environment setup complete."