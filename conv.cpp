#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(void)
{
    std::string str;
    std::vector<float> vc;
    char    buffer[256];
    float tmp;
    int offset;
    std::ifstream file("resources/42.obj");
    // std::ifstream file("resources/teapot.obj");

    std::ofstream file2("42.rt");

    do {
        offset = 2;
        file.getline(buffer, 256);
        if (buffer[0] != 'v')
            break ;
        str = buffer;
        offset = str.find(' ', offset);
        vc.push_back(std::stof(buffer + offset, NULL));
        
        offset = str.find(' ', offset);
        vc.push_back(std::stof(buffer + offset, NULL));
        
        offset = str.find(' ', offset);
        vc.push_back(std::stof(buffer + offset, NULL));
    } while (buffer[0] == 'v');

    int i;
    do {
        offset = 2;
        file.getline(buffer, 256);
        str = buffer;
        file2 << "tr ";
        offset = str.find(' ', offset);
        i = atoi(buffer + offset);
        file2 << vc[(i - 1) * 3] << "," << vc[(i - 1) * 3  + 1] << "," << vc[(i - 1) * 3 + 2] << " ";
        offset = str.find(' ', offset);
        i = atoi(buffer + offset);
        file2 << vc[(i - 1) * 3] << "," << vc[(i - 1) * 3  + 1] << "," << vc[(i - 1) * 3 + 2] << " ";
        offset = str.find(' ', offset);
        i = atoi(buffer + offset);
        file2 << vc[(i - 1) * 3] << "," << vc[(i - 1) * 3  + 1] << "," << vc[(i - 1) * 3 + 2] << " ";
        file2 << "125,125,125\n";
    } while (buffer[0] == 'f');
}