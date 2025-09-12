#include <cctype>
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <string>

//Count lines, words and characters in standard input
int main()
{
    unsigned long num_lines, num_words, num_chars;
    num_lines = num_words = num_chars = 0;
    using namespace std;
    string line;
    while(getline(cin, line)) {
        num_lines++;
        num_chars += line.length() + 1;
        bool in_word = false;
        for (size_t i = 0; char c = line[i]; i++)
            if (isspace(static_cast<unsigned char>(c))) {
                if (in_word)
                    num_words++;
                in_word = false;
            } else if(!in_word)
                in_word = true;
            if (in_word)
                num_words++;
    }
    cout << right << setw(10) << "lines: " << num_lines << " words: " << num_words << " chars: " << num_chars << '\n';
}