import sys
import os
import pytest

# Add the project root (Algorithms/) to sys.path
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..', '..')))

from StringMatching.KMP import kmp_string_matching 

# Test Case 1: Basic test case where pattern is found
def test_basic_case():
    haystack = "ababcababcabc"
    needle = "abcab"
    result = kmp_string_matching(haystack, needle)
    assert result == [2, 7], f"Expected [2, 7], but got {result}"

# Test Case 2: No match found in the haystack
def test_no_match():
    haystack = "abcdefgh"
    needle = "xyz"
    result = kmp_string_matching(haystack, needle)
    assert result == [], f"Expected [], but got {result}"

# Test Case 3: Pattern is the same as the haystack
def test_pattern_equals_haystack():
    haystack = "abc"
    needle = "abc"
    result = kmp_string_matching(haystack, needle)
    assert result == [0], f"Expected [0], but got {result}"

# Test Case 4: Pattern has repeated characters, partial match
def test_repeated_characters():
    haystack = "ababababab"
    needle = "abab"
    result = kmp_string_matching(haystack, needle)
    assert result == [0, 2, 4, 6], f"Expected [0, 2, 4, 6], but got {result}"

# Test Case 5: Pattern is larger than the haystack (edge case)
def test_pattern_larger_than_haystack():
    haystack = "abc"
    needle = "abcdef"
    result = kmp_string_matching(haystack, needle)
    assert result == [], f"Expected [], but got {result}"

# Test Case 6: Pattern with characters that appear at the start and end
def test_pattern_with_start_end_match():
    haystack = "aaaaa"
    needle = "aa"
    result = kmp_string_matching(haystack, needle)
    assert result == [0, 1, 2, 3], f"Expected [0, 1, 2, 3], but got {result}"

# Test Case 7: Case sensitivity (e.g., "a" and "A" are different)
def test_case_sensitivity():
    haystack = "aAaAaA"
    needle = "Aa"
    result = kmp_string_matching(haystack, needle)
    assert result == [1, 3], f"Expected [1, 3], but got {result}"

if __name__ == "__main__":
    pytest.main()
