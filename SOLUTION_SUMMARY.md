# Problem 112 - Shell Simulation Solution Summary

## Problem Overview
Implement the constructor and destructor for the `arguments` class to parse command-line arguments and manage memory properly for a shell simulation.

## Solution Approach

### Constructor Implementation
The constructor parses a command string by:
1. Iterating through the input string character by character
2. Splitting on space characters to extract individual arguments
3. Handling multiple consecutive spaces correctly
4. Allocating memory for the `_argv` array and each argument string
5. Copying each argument using `strcpy`

### Destructor Implementation
The destructor ensures no memory leaks by:
1. Freeing each individual argument string (char*)
2. Freeing the array of pointers (_argv)
3. Checking for nullptr before freeing

### Key Features
- Correctly handles empty strings (argc = 0, argv = nullptr)
- Handles multiple consecutive spaces (treated as single separator)
- Properly manages dynamic memory allocation and deallocation
- Uses only allowed headers: string, cstring, vector, map, functional

## Testing Results

### Local Testing
Created comprehensive test cases covering:
- Basic commands: "ls -al /usr/bin" → argc=3
- Single arguments: "pwd" → argc=1
- Multiple spaces: "echo  hello  world" → argc=3
- Empty strings: "" → argc=0
- Complex commands: "gcc -o output main.cpp -std=c++11" → argc=5

All local tests passed successfully.

### OJ Submission Results
**Submission ID**: 767158
**Status**: Accepted
**Score**: 100/100

#### Test Groups:
1. Group 1 (80% weight): Testing argc correctness - **Accepted** (80/80 points)
2. Group 2 (20% weight): Testing other behaviors - **Accepted** (20/20 points)

#### Resource Usage:
- Time: 668 ms (well within 10000 ms limit)
- Memory: 48 MB (well within 512 MiB limit)

## Submission Count
**Total Submissions**: 1 out of 5 allowed
**First submission achieved 100% score** - No resubmission needed!

## Files in Repository
- `src.hpp`: Main solution file containing the arguments and shell classes
- `test_main.cpp`: Local test program to verify implementation
- `test_program`: Compiled test binary
- `submit_acmoj/acmoj_client.py`: Fixed submission client with submit_code method
- `SOLUTION_SUMMARY.md`: This summary document

## Key Learning Points
1. Proper string parsing with space delimiters
2. Dynamic memory management in C++ (new/delete)
3. Avoiding memory leaks by proper cleanup in destructor
4. Following strict requirements (no additional headers or member variables)
