# Naive String Matching Algorithm
# This algorithm searches for a pattern `needle` in a text `haystack` by checking each position in the haystack.
# Time complexity: O((n - m + 1) * m), where n is the length of haystack and m is the length of needle.

def naive_string_matching(haystack, needle):
    """
    This function implements the naive string matching algorithm
    
    Keyword arguments:
    Param haystack: The text in which we search for the pattern
    Param needle: The pattern we need to find
    Return: The starting Index of the first occurence of the pattern, or -1 if it doesn't exist
    """
    
    for i in range(len(haystack) - len(needle) + 1):

        found = True
        for j in range(len(needle)):

            if haystack[i+j] != needle[j]:
                found = False
                break

        if found:
            return i

    return -1