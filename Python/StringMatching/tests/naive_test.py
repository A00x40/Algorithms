import sys
import os
import pytest

# Add the project root (Algorithms/) to sys.path
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..', '..')))

from StringMatching.naive import naive_string_matching

def test_found_middle():
    assert naive_string_matching("hello world", "world") == 6

def test_found_start():
    assert naive_string_matching("abc", "abc") == 0

def test_found_middle_phrase():
    assert naive_string_matching("the quick brown fox", "quick") == 4

def test_not_found():
    assert naive_string_matching("hello world", "python") == -1
    assert naive_string_matching("abc", "def") == -1

def test_empty_needle_and_haystack():
    assert naive_string_matching("", "") == 0

def test_empty_needle():
    assert naive_string_matching("test", "") == 0

def test_empty_haystack():
    assert naive_string_matching("", "test") == -1

def test_needle_longer_than_haystack():
    assert naive_string_matching("hi", "hello") == -1

if __name__ == "__main__":
    pytest.main()