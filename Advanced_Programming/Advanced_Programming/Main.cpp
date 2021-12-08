#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

static bool** board;
static int numRows;
static int numCols;

static void read_board(std::string fileName)
{
    std::string line;
    std::ifstream ReadFile(fileName);
    std::getline(ReadFile, line);
    

    std::vector<int> vect;

    std::stringstream ss(line);

    for (int i; ss >> i;) {
        vect.push_back(i);
        if (ss.peek() == ',')
            ss.ignore();
    }
    numRows = vect[1];
    numCols = vect[0];

    board = new bool* [numRows];

    for (int i = 0; i < numRows; ++i)
    {
        board[i] = new bool[numCols];
    }

    for (int j = 0; j < numRows; ++j)
    {
        std::getline(ReadFile, line);
       

       const char* string = line.c_str();
       for (int k = 0; k < numCols; k++)
       {
           if (string[k] == 'x')
           {
               board[j][k] = true;
           }
           else if (string[k] == '.')
           {
               board[j][k] = false;
           }
       }
       
    }
    
}

static void write_board(std::string fileName)
{
    std::ofstream WriteFile(fileName, std::ios::out);
    WriteFile << numRows << "," << numCols << std::endl;
    char *line = new char[numCols + 1];
    line[numCols] = '\n';
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            if (board[i][j] == true)
            {
                line[j] = 'x';
            }
            else
            {
                line[j] = '.';
            }
            
        }
        WriteFile.write(line, sizeof(char) * (numCols + 1));
        
    }

    WriteFile.close();
}
static void show_usage(std::string name)
{
    std::cerr << "Usage: " << name << " <option(s)> SOURCES"
        << "Options:\n"
        << "\t-h,--help\t\tShow this help message\n"
        << "\t--load LOAD\tSpecify the source path\n"
        << "\t--save SAVE\tSpecify the destination path\n"
        << "\t--generations GENERATIONS\tSpecify the number of generations\n"
        << "\t--measure MEASURE\tSpecify that the processing time should be measuered\n"
        << std::endl;
}



int main(int argc, char* argv[])
{
    if (argc < 5) {
        show_usage(argv[0]);
        return 1;
    }

    std::string destination;
    std::string source;
    bool measure;
    int generations;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if ((arg == "-h") || (arg == "--help")) {
            show_usage(argv[0]);
            return 0;
        }
        else if ((arg == "--load")) {
            if (i + 1 < argc) { // Make sure we aren't at the end of argv!
                source = argv[++i]; // Increment 'i' so we don't get the argument as the next argv[i].
            }
            else { // Uh-oh, there was no argument to the destination option.
                std::cerr << "--load option requires one argument." << std::endl;
                return 1;
            }
        }
        else if (arg == "--save")
        {
            if (i + 1 < argc) {
                destination = argv[++i];
            }
            else { // Uh-oh, there was no argument to the destination option.
                std::cerr << "--save option requires one argument." << std::endl;
                return 1;
            }
        }
        else if (arg == "--generations")
        {
            if (i + 1 < argc) {
                try
                {
                    generations = std::stoi(argv[++i]);
                }
                catch (const std::exception&)
                {
                    std::cerr << "could not read number of generations!";
                    return 1;
                }

            }
        }
        else if (arg == "--measure")
        {
            measure = true;
        }
        else {

        }
    }

    read_board(source);
    write_board("./random250_out.gol");
    return 0;
}