#include <vector>
#include <string>

using namespace std;


std::vector<std::string> split(const std::string& str, char delim){
    std::vector<std::string> tokens;

    int len = str.length();

    if (!str.empty())
    {
        string buff = "";
        for (int i = 0; i < len; i++) {

            if (str[i]==delim) {
                tokens.push_back(buff);
                buff = "";
            }
            else {
                buff += str[i];
            }

        };
        tokens.push_back(buff); //так как в конце строчки нет разделителя

    }

    return tokens;
}
