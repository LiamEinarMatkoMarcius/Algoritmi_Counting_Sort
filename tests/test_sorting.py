import subprocess
import unittest

def run_sorting_test(mode, input_numbers):
    args = ["./your_program", str(mode)] + list(map(str, input_numbers))
    result = subprocess.run(args, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    output = result.stdout.strip()
    if not output:
        return []
    return list(map(int, output.split()))

class TestSorting(unittest.TestCase):
    def test_counting_sort_sorted(self):
        input_data = [5, 3, 4, 1, 2]
        output = run_sorting_test(0, input_data)
        self.assertEqual(output, sorted(input_data))

    def test_roman_sort_sorted(self):
        input_data = [10, 7, 8, 9, 6]
        output = run_sorting_test(1, input_data)
        self.assertEqual(output, sorted(input_data))

    def test_with_duplicates(self):
        input_data = [3, 2, 1, 2, 3]
        output = run_sorting_test(0, input_data)
        self.assertEqual(output, sorted(input_data))

    def test_single_element(self):
        input_data = [42]
        output = run_sorting_test(1, input_data)
        self.assertEqual(output, [42])

if __name__ == "__main__":
    unittest.main()
