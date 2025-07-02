# DATA-COMPRESSION-TOOL

*company name: CODETECH IT SOLUTIONS 
* NAME : AASHISH SAW
* INTERN ID : CITS0D398
* DOMAIN : C LANGUAGE
* DURATION : 4 WEEKS
* MENTOR : NEELA SANTOSH 
* DESCRIPTION :

  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

  #QUE1 : WRITE A PROGRAM TO IMPLEMENT A
BASIC DATA COMPRESSION
ALGORITHM LIKE RUN-LENGTH
ENCODING (RLE).

  Data compression plays a vital role in reducing the size of data for efficient storage and transmission. Among various compression techniques, Run-Length Encoding (RLE) stands out as a simple yet effective lossless algorithm, particularly useful when data contains many consecutive repeated characters. This project focuses on implementing the RLE algorithm using the C programming language.

The program accepts a string input from the user, which may include alphabets, digits, spaces, and special characters. It scans the input sequentially, counting the number of consecutive occurrences of each character. Instead of storing repeated characters individually, the program compresses them by storing a single instance of the character followed by the count of its repetitions. For example, a sequence such as “aaaabbbcc” is compressed to “a4b3c2”. This not only reduces the size of the data but also provides insight into how compression algorithms function at a fundamental level.

Developed using C, the program utilizes standard libraries such as stdio.h and string.h for input/output operations and string manipulation. The code was compiled and tested on platforms supporting the GCC compiler and can be executed on Windows, Linux, or via online C compilers. Additionally, the program saves the compressed output to a file, illustrating practical use in storing compressed data.

Overall, this project serves as an educational tool to demonstrate the concept of data compression. It introduces beginners to algorithm design, string processing, and file handling in C, laying the groundwork for more complex compression and decompression techniques used in real-world applications.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#QUE2: DELIVERABLE: A TOOL THAT
COMPRESSES AND DECOMPRESSES
TEXT FILES.

Data compression is a crucial technique in computer science that helps reduce the size of data for storage efficiency and faster transmission. Among various compression algorithms, Run-Length Encoding (RLE) is one of the simplest forms of lossless compression, especially effective when the data contains many consecutive repeating characters. This project implements a tool in C programming language that performs both compression and decompression of text files using the RLE algorithm.

The program begins by reading the content of a user-specified text file. It then compresses the data by scanning through the text, counting consecutive repeated characters, and replacing them with a single instance of the character followed by the number of repetitions. For example, a sequence like “aaaaabb” is compressed into “a5b2”. This reduces the file size, particularly for text containing many repeating characters such as spaces or repeated letters.

After compression, the program saves the compressed data into a new file, allowing for efficient storage or transmission. The tool also supports decompression, where it reads the compressed file, interprets the encoded format, and reconstructs the original text. The decompressed output is saved into a separate file, ensuring that the process is lossless and the original data can be perfectly restored.

This project was developed using standard C libraries for file handling, string manipulation, and input/output operations. It was tested on common platforms using GCC compiler. The tool is educational and practical, demonstrating fundamental concepts in file processing, string algorithms, and data compression. It serves as a foundation for understanding more complex compression methods used in various software applications today.

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
