#include <bits/stdc++.h>

using namespace std;


#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>

bool myfunc(string str1, string str2)
{
    return str1.size() < str2.size();
}

string arrange(string sentence) {
    std::istringstream stringstream(sentence);
    std::vector<std::string> vectorOfStrings;
    const char delimeter  = ' ';

    std::string substring="";
    // convert sentence into substrings and put it in a vector container
    while (std::getline(stringstream, substring, delimeter))
    {
        //size_t found = substring.find(".");
        substring.erase(std::remove(substring.begin(), substring.end(), '.'), substring.end());
        std::transform(substring.begin(), substring.end(), substring.begin(), ::tolower);
        vectorOfStrings.push_back(substring);        
    }
    // Sort strings in ascending order
    std::sort(vectorOfStrings.begin(), vectorOfStrings.end(), myfunc);  
    vectorOfStrings[0][0] = std::toupper(vectorOfStrings[0][0]);
    std::vector<string>::iterator it = vectorOfStrings.end();
    vectorOfStrings.push_back(".");
    string result="";
    int index = 0 ;
    for(const auto& str : vectorOfStrings)
    {
        result+=str; 
        index++;
        if (str != "." && ((vectorOfStrings.size() - 1) != index) ) 
            result+=" ";
    }
    return result;   

}


int main()
{
    
    std::cout << arrange("Cats and Hats.");
    return 0;
}