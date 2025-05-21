# Knuth-Morris-Pratt String Matching Algorithm
# This algorithm searches for a pattern `needle` in a text `haystack` by checking each position in the haystack.
# Time complexity: O(n + m), where n is the length of haystack and m is the length of needle.
# Space Complexity: KMP uses extra space for the LPS array O(m) where m is the length of the needle

def compute_lps(pattern):
    """
    This function computes the LPS (Longest Prefix Suffix) array for the given pattern.
    
    Keyword arguments:
    Param pattern: the pattern (needle) for which we compute the LPS array
    
    Returns:
    lps: an array where each index i holds the length of the longest prefix that is also a suffix
    """
    m = len(pattern) 
    lps = [0] * m  # Initialize the LPS array to zeroes

    length = 0  # Length of the previous longest prefix-suffix
    i = 1  # Start from the second character (since lps[0] is always 0)

    while i < m:
        if pattern[i] == pattern[length]:  
            length += 1
            lps[i] = length 
            i += 1 
        else:
            if length != 0:
                length = lps[length - 1]  # Jump to the previous longest prefix suffix
            else:
                lps[i] = 0  # No match at all, so set LPS for this index to 0
                i += 1 

    return lps 


def kmp_string_matching(haystack, needle):
    """
    This function implements the Knuth-Morris-Pratt (KMP) string matching algorithm.
    It searches for the first occurrence of the pattern (needle) in the text (haystack).

    Keyword arguments:
    Param haystack: the text in which we search for the pattern (needle)
    Param needle: the pattern to be searched in the haystack
    
    Returns:
    result: a list containing starting indices of all matches (if any), or an empty list if no match
    """
    
    n = len(haystack)  
    m = len(needle) 
    
    lps = compute_lps(needle)  # Compute the LPS array for the needle
    
    result = []  # To store the indices of all matches found
    i = j = 0  # i is for haystack, j is for needle
    
    while i < n: 
        if haystack[i] == needle[j]:  
            i += 1 
            j += 1  
        
        if j == m: 
            result.append(i - j)  # Append the starting index of the match (i - j)
            j = lps[j - 1]  # Use the LPS array to find the next possible match
            
        elif i < n and haystack[i] != needle[j]: 
            if j != 0:  # If some characters have already matched, use LPS to avoid redundant comparisons
                j = lps[j - 1] 
            else:
                i += 1  # If no match so far, just move to the next character in the haystack
    
    return result 
