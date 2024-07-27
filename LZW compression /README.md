# LZW Compression
This project implements the LZW (Lempel-Ziv-Welch) compression algorithm. It includes a simple example demonstrating the compression and decompression of text files.

## Getting Started
To get started with the LZW compression project:
1. Open the project in Visual Studio.
2. Build the project to compile `source.cpp`.
3. Run the compiled executable to see the compression and decompression in action.

## Usage
After building the project, you can run the executable to compress or decompress text files. The program accepts the following command-line arguments:
```shell
LZW_txt_compressor.exe <file_to_compress>
```
The program will create in directory the compressed file. <file_to_compress+.txt>

## Files Included
- `source.cpp`: The implementation of the LZW compression algorithm.
- `example1.txt` and `example2.txt`: Sample text files used for testing.
- `LZW_txt_compression.exe` : The compiled executable file.

## Source
**How Computers Compress Text: Huffman Coding and Huffman Trees -** https://www.youtube.com/watch?v=JsTptu56GM8&ab_channel=TomScott
**Lempel-Ziv-Welch Compression Algorithm - Tutorial -** https://www.youtube.com/watch?v=j2HSd3HCpDs&ab_channel=TechRetox
**GeeksGorGeeks Article -** https://www.geeksforgeeks.org/lzw-lempel-ziv-welch-compression-technique/
**Chatgpt -** for better understanding string, map, unordered_map, fstream and vector libraries; commenting and edge cases https://chatgpt.com/?model=auto

## Disclaimer
the program isn't finished yet. Decompressor not included.
