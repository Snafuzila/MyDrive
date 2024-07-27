#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>
#include <vector>
//using namespace std;

std::unordered_map<std::string, int> create_table();
std::string compress_file(int argc, char* argv[]);


int main(int argc, char* argv[])
{
    // Check if the correct number of arguments are provided
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1; // Return a non-zero value to indicate an error
    }

    // Call the handle_file function with the command-line argument
    std::string result = compress_file(argc, argv);

    // Check if the result is empty, indicating an error occurred
    if (result.empty()) {
        std::cerr << "An error occurred while processing the file." << std::endl;
        return 1; // Return a non-zero value to indicate an error
    }

    // Print the name of the compressed file
    std::cout << "Compressed file created: " << result << std::endl;

    return 0; // Return 0 to indicate successful execution
}


std::unordered_map<std::string, int> create_table()
{
    // Declare a map with integer keys and character values
    // In cpp map is dynamically allocated so I don't need to allocate a specific size
    std::unordered_map<std::string, int> table;

    // Fill the first 256 entries with ASCII values
    for (int i = 0; i < 256; ++i)
    {
        table[std::string(1, static_cast<char>(i))] = i;
    }
    return table;
}
std::string compress_file(int argc, char* argv[])
{
    std::string w , filename = argv[1]; // Get the filename from command-line arguments

    // Check if the filename has a .txt extension and remove it
    if (filename.length() >= 4 && filename.substr(filename.length() - 4) == ".txt") {
        filename = filename.substr(0, filename.length() - 4);
    }
    std::string compressed_filename = filename + "_compressed.txt";

    std::unordered_map<std::string, int> table = create_table();
    int table_size = 256;

    std::ifstream file(argv[1], std::ios::binary); // Open the input file
    if (!file) 
    {
        std::cerr << "Unable to open file: " << argv[1] << std::endl;
        return std::string(); // Return an empty string on error
    }

    std::ofstream compressed_file(compressed_filename, std::ios::binary); // Open the output file

    if (!compressed_file.is_open())
    {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return std::string(); // Return an empty string on error
    }

    char c;
    while (file.get(c))
    {
        std::string wc = w + c;
        if (table.count(wc))
            w = wc;
        else {
            //compressed_file << (table[w]) << " ";
            compressed_file.write(reinterpret_cast<const char*>(&table[w]), sizeof(int));
            // Add wc to the table/dictionary.
            table[wc] = table_size++;
            w = std::string(1, c);
        }
    }
    if (!w.empty())
    {
        //compressed_file << (table[w]) << " ";
        compressed_file.write(reinterpret_cast<const char*>(&table[w]), sizeof(int));
    }

    compressed_file.close();
    file.close();
    std::cout << table_size << std::endl;
    return compressed_filename;
}