#include "ExportData.h"

ExportData::ExportData(string fileName)
{
    vector<string> res = explode(fileName,'.');
    manager.open(res[0]+".log");
    manager << "Inicio do arquivo!"<<endl;
}

void ExportData::writeFile(ostringstream &input)
{
   manager<< input.str() << endl;
}

vector<string> ExportData::explode(string &word, char c)
{
    vector<string> res;
    std::istringstream iss(word);

    for (string s; getline(iss, s, c);)
    {
        res.push_back(s);
    }
    return (res);
}
