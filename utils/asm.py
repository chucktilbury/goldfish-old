#!/usr/bin/env python3
'''
This is the main driver program for the assembler. It takes the command
parameters and uses os.system() to run them against the intended input.

1. Run preprocessor on the source file into a temporary file.
2. Run the assembler on the temp file into the output file.
3. Delete the temp file.

'''

