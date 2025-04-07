#!/bin/bash
# filepath: c:\Users\liame\Desktop\Faks\Letnik_2.2\SISTEMSKA_ADMINISTRACIJA\Git\Algoritmi_Counting_Sort\run-tests.sh

echo "Running tests..."

# Check if the compiled executable exists
if [ ! -f counting_sort ]; then
    echo "Compiled executable 'counting_sort' not found! Exiting."
    exit 1
fi

# Run Python tests
if [ -f tests/test_sorting.py ]; then
    echo "Executing Python tests..."
    python -m unittest discover tests
else
    echo "Test script 'tests/test_sorting.py' not found! Exiting."
    exit 1
fi

echo "Tests completed."